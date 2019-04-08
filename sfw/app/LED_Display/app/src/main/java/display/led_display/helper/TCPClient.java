package display.led_display.helper;

import android.os.Handler;
import android.util.Log;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.util.ArrayList;

public class TCPClient {

    private final Handler handler;
    private MessageCallback messageCallback;
    private String ipAddress, incomingMessage;
    private int portNumber;
    private ArrayList<String> messages;
    private boolean mRun;
    BufferedReader in;
    PrintWriter out;

    public TCPClient(Handler handler, String ipAddress, int portNumber, ArrayList<String> messages, MessageCallback messageCallback) {
        this.handler = handler;
        this.ipAddress = ipAddress;
        this.portNumber = portNumber;
        this.messages = messages;
        this.messageCallback = messageCallback;
    }

    public void run() {
        mRun = true;
        Log.d("handler", this.handler.toString());
        Log.d("handler", ""+this.handler.hasMessages(1));
        try {
            InetAddress serverAddress = InetAddress.getByName(ipAddress);
            Socket socket = new Socket(serverAddress, portNumber);

            try {
                out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                Log.d("TCPClient", "In/Out created");
                for(int i = 0; i < messages.size(); i++) {
                    Log.d("Loop Count", ""+i);
                    //Sending message with command specified by AsyncTask
                    sendMessage(messages.get(i));
                    while (mRun) {
                        Log.d("waiting", "give ME SOMETHING!!!");
                        incomingMessage = in.readLine();
                        if (incomingMessage != null) {
                            incomingMessage = incomingMessage.trim();
                            if (incomingMessage.equals("Message Received")) {
                                Log.d("Response Parser", "Closing TCP connection");
                                break;
                            }
                        }
                        incomingMessage = null;
                    }
                }
                Log.d("TCPClient", "Received Message: " + incomingMessage);
            } catch (Exception e) {
                Log.d("TCPClient", "Error", e);
            } finally {
                out.flush();
                out.close();
                in.close();
                socket.close();
                Log.d("TCPClient", "Socket Closed");
            }
        } catch (Exception e) {
            Log.d("TCPClient", "Error", e);
        }
        handler.sendEmptyMessage(2);
    }

    public void sendMessage(String message) {
        if (out != null && !out.checkError()) {
            out.println(message);
            out.flush();
            Log.d("TCPClient", "Sent Message: " + message);
        }
    }

    public void stopClient() {
        mRun = false;
    }

    public boolean isRunning() {
        return mRun;
    }

    public interface MessageCallback {
        public void callbackMessageReceiver(String message);
    }
}

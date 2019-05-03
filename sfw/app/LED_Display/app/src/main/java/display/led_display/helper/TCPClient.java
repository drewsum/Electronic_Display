package display.led_display.helper;

import android.os.Handler;
import android.os.Message;
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
    private final String ipAddress;
    private final int portNumber;
    private final ArrayList<String> messages;
    private boolean mRun = false;
    private int progressCount;
    private BufferedReader in = null;
    private PrintWriter out = null;
    private final Boolean isProject;

    private static final int SENDING = 1;

    public TCPClient(Handler handler, String ipAddress, int portNumber, ArrayList<String> messages, Boolean isProject) {
        this.handler = handler;
        this.ipAddress = ipAddress;
        this.portNumber = portNumber;
        this.messages = messages;
        this.progressCount = 0;
        this.isProject = isProject;
    }

    public void run() {
        String messageReceived = "Message Received";
        String resendMessage = "Resend Message";
        mRun = true;
        try {
            InetAddress serverAddress = InetAddress.getByName(ipAddress);
            Socket socket = new Socket(serverAddress, portNumber);

            try {
                out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                Log.d("TCPClient", "In/Out created");
                for(int i = 0; i < messages.size(); i++) {
                    if(isProject) {
                        progressCount++;
                        //Sending message with command specified by AsyncTask
                        Message msg = new Message();
                        msg.what = SENDING;
                        msg.arg1 = progressCount;
                        msg.arg2 = messages.size();
                        handler.sendMessage(msg);
                    }
                    sendTCPMessage(messages.get(i));
                    mRun = true;
                    while (mRun) {
                        Log.d("In a loop", "Waiting for server to respond");
                        String incomingMessage = in.readLine();
                        if (incomingMessage != null) {
                            incomingMessage = incomingMessage.trim();

                            if (incomingMessage.equals(messageReceived)) {
                                Log.d("TCPClient", "Received Message: " + incomingMessage);
                                mRun = false;
                            } else if (incomingMessage.equals(resendMessage)) {
                                Log.d("TCPClient", "Received Message: " + incomingMessage);
                                // re-sends message over and over
                                mRun = false;
                                i--;
                            }
                        }
                        incomingMessage = null;
                    }
                }
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
    }

    private void sendTCPMessage(String message) {
        if (out != null && !out.checkError()) {
            out.println(message);
            out.flush();
            Log.d("TCPClient", "Sent Message: " + message);
        } else {
            Log.d("out", "out is bad");
        }
    }

    public void stopClient() {
        mRun = false;
    }

    public boolean isRunning() {
        return mRun;
    }
}

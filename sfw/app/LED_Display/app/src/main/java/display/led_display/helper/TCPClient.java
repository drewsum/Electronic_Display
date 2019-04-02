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

import display.led_display.MenuActivity;

public class TCPClient {

    private static final String TAG = "TCPClient";
    private final Handler mHandler;
    private String ipNumber, incomingMessage, command;
    int portNumber;
    BufferedReader in;
    PrintWriter out;
    private MessageCallback listener = null;
    private boolean mRun = false;

    /**
     * TCPClient class constructor, which is created in AsyncTasks after the button click.
     *
     * @param mHandler Handler passed as an argument for updating the UI with sent messages
     * @param command  Command passed as an argument, e.g. "shutdown -r" for restarting computer
     * @param ipNumber String retrieved from IpGetter class that is looking for ip number.
     * @param listener Callback interface object
     */
    public TCPClient(Handler mHandler, String command, String ipNumber, int portNumber, MessageCallback listener) {
        this.listener = listener;
        this.ipNumber = ipNumber;
        this.portNumber = portNumber;
        this.command = command;
        this.mHandler = mHandler;
    }

    /**
     * Public method for sending the message via OutputStream object.
     *
     * @param message Message passed as an argument and sent via OutputStream object.
     */
    public void sendMessage(String message) {
        if (out != null && !out.checkError()) {
            out.println(message);
            out.flush();
            mHandler.sendEmptyMessageDelayed(MenuActivity.SENDING, 1000);
            Log.d(TAG, "Sent Message: " + message);

        }
    }

    /**
     * Public method for stopping the TCPClient object ( and finalizing it after that ) from AsyncTask
     */
    public void stopClient() {
        Log.d(TAG, "Client stopped!");
        mRun = false;
    }

    public void run() {

        mRun = true;

        try {
            // Creating InetAddress object from ipNumber passed via constructor from IpGetter class.
            InetAddress serverAddress = InetAddress.getByName(ipNumber);

            Log.d(TAG, "Connecting...");

            /**
             * Sending empty message with static int value from MenuActivity
             * to update UI ( 'Connecting...' ).
             *
             * @see com.example.turnmeoff.MenuActivity.CONNECTING
             */
            mHandler.sendEmptyMessageDelayed(MenuActivity.CONNECTING, 1000);

            /**
             * Here the socket is created with hardcoded port.
             * Also the port is given in IpGetter class.
             *
             * @see com.example.turnmeoff.IpGetter
             */
            Socket socket = new Socket(serverAddress, portNumber);


            try {

                // Create PrintWriter object for sending messages to server.
                out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

                //Create BufferedReader object for receiving messages from server.
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

                Log.d(TAG, "In/Out created");

                //Sending message with command specified by AsyncTask
                this.sendMessage(command);

                //
                //mHandler.sendEmptyMessageDelayed(MenuActivity.SENDING, 2000);

                //Listen for the incoming messages while mRun = true
                while (mRun) {
                    incomingMessage = in.readLine();
                    if (incomingMessage != null && listener != null) {
                        Log.d("Received message", incomingMessage);
                        incomingMessage = incomingMessage.trim();
                        if(incomingMessage.equals("Message Received. Close.")) {
                            Log.d("Response Parser", "Closing TCP connection");
                        } else if(incomingMessage.equals("Message Received. Keep Alive.")) {
                            Log.d("Response Parser", "Keeping Connection open");
                        }
                        /**
                         * Incoming message is passed to MessageCallback object.
                         * Next it is retrieved by AsyncTask and passed to onPublishProgress method.
                         *
                         */
                        listener.callbackMessageReceiver(incomingMessage);

                    }
                    incomingMessage = null;

                }

                Log.d(TAG, "Received Message: " + incomingMessage);

            } catch (Exception e) {

                Log.d(TAG, "Error", e);
                mHandler.sendEmptyMessageDelayed(MenuActivity.ERROR, 2000);

            } finally {

                out.flush();
                out.close();
                in.close();
                socket.close();
                mHandler.sendEmptyMessageDelayed(MenuActivity.SENT, 3000);
                Log.d(TAG, "Socket Closed");
            }

        } catch (Exception e) {

            Log.d(TAG, "Error", e);
            mHandler.sendEmptyMessageDelayed(MenuActivity.ERROR, 2000);

        }

    }

    public interface MessageCallback {
        /**
         * Method overriden in AsyncTask 'doInBackground' method while creating the TCPClient object.
         *
         * @param message Received message from server app.
         */
        void callbackMessageReceiver(String message);
    }
}
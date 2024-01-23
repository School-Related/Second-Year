# echo-server.py

import socket
import os

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)




# Define the file to be sent
file_name = '../Assignment_3/sunset.mp4'

# Create a socket object
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:

    # Bind the socket to a specific address and port number
    s.bind((HOST, PORT))

    # Listen for incoming connections
    s.listen()

    # Wait for a client to connect
    conn, addr = s.accept()

    # Send the file to the client
    with open(file_name, 'rb') as f:
        data = f.read(1024)
        while data:
            conn.send(data)
            data = f.read(1024)

    # Close the connection
    conn.close()
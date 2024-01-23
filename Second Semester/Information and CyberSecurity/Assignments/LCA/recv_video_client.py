
import socket

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432  # The port used by the server

# create writeable buffer for storing video 



# Create a socket object
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:

    # Connect to the server
    s.connect((HOST, PORT))

    # Receive the file from the server
    with open('received_video.mp4', 'wb') as f:
        while True:
            data = s.recv(1024)
            if not data:
                break
            f.write(data)

    # Close the connection
    s.close()
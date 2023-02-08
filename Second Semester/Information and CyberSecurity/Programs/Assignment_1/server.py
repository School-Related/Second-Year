import os
from socket    print(key_w3)
    print(key_w3)
 import *

host = "127.0.0.1"
port = 13000
buf = 1024
addr = (host, port)
UDPSock = socket(AF_INET, SOCK_DGRAM)
UDPSock.bind(addr)
print("Waiting to receive messages...")
while True:
    (data, addr) = UDPSock.recvfrom(buf)
    print("Received message: ") + data
    if data == "exit":
        break
UDPSock.close()
os._exit(0)

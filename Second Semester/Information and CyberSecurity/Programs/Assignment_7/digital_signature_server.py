# echo-server.py

import socket
from hashlib import sha256
from pathlib import Path
import sys, os
ROOT_DIR = str(Path(__file__).parent.parent)
sys.path.insert(1, os.path.join(ROOT_DIR, "Assignment_4"))
from rsa import isPrime, getLowLevelPrime
import random

HOST = "192.168.251.249"  # Standard loopback interface address (localhost)
PORT = 65432  # Port to listen on (non-privileged ports are > 1023)

# defining some basic variables

message = ""
signature = ""
public_key = None
private_key = None
p, g = None, None


def make_global_key():
    global public_key
    global private_key
    p = getLowLevelPrime(8)
    

def generate_our_keys():
    pass

def generate_message():
    global message
    message = "Hello, world"

def make_signature():
    global signature


def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()
        with conn:
            print(f"Connected by {addr}")
            make_global_key()
            generate_our_keys()
            generate_message()
            make_signature()
            conn.sendall(str(p).encode())
            conn.sendall(str(g).encode())
            conn.sendall(str(public_key).encode())
            client_public_key = int(conn.recv(1024).decode())
            conn.sendall(message.encode())
            conn.sendall(signature.encode())
            
            print("Sent message")


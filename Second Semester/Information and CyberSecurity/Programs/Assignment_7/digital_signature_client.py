
import socket
from pathlib import Path
import sys, os
ROOT_DIR = str(Path(__file__).parent.parent)
sys.path.insert(1, os.path.join(ROOT_DIR, "Assignment_4"))
from rsa import isPrime, getLowLevelPrime
import random
from hashlib import sha256

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432  # The port used by the server

# defining some basic variables

message = ""
our_signature = ""
server_signature = ""

public_key = None
private_key = None
p, g = None, None

def generate_signature():


def verify_signature():
    pass

def generate_key():
    pass

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        p = int(s.recv(1024).decode())
        g = int(s.recv(1024).decode())
        server_public_key = int(s.recv(1024).decode())
        s.sendall(str(public_key).encode())
        message = s.recv(1024).decode()
        server_signature = s.recv(1024).decode()
        print("Received message")
        if verify_signature():
            print("Signature is valid")
        else:
            print("Signature is invalid")


    print(f"Received {data!r}")

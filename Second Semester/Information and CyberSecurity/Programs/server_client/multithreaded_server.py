# Echo server.py
import socket
import time
import threading
from rsa import make_keys
from rsa import rsa_encryption
from rsa import rsa_decryption
import json


messages_to_send = [
    # "hi",
    # "hello",
    # "how are you?",
    # "I am fine",
    # "So",
    # "Where have you been ?",
    # "i was here only",
    # "bye",
]
messages_to_send = messages_to_send[::-1]
texting = True

messages_received = []

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65436  # Port to listen on (non-privileged ports are > 1023)

public_key = [0, 0]
private_key = [0, 0]
client_public_key = [0, 0]


def encrypt_alg(plain_text):
    # print("encrypting: ", plain_text, type(plain_text))
    cipher_texts = []
    plain_texts = []
    
    for i in plain_text:
        # print(ord(i))
        cipher_text = rsa_encryption(ord(i), key=client_public_key)
        cipher_texts.append(cipher_text)

    cipher_texts = [chr(i) for i in cipher_texts]
    cipher_text = "".join(cipher_texts)
    
    time.sleep(1)
    return cipher_text


def encrypt():
    global texting
    plain_text = ""
    while texting:
        plain_text = input("> ")
        cipher_text = encrypt_alg(plain_text)
        messages_to_send.insert(0, cipher_text)
        if plain_text == "bye":
            texting = False
            return

    texting = False


def decrypt_alg(cipher_text):
    plain_texts = []
    
    for i in cipher_text:
        # print(ord(i))
        plain_text = rsa_decryption(ord(i), key=private_key)
        plain_texts.append(plain_text)
        
    plain_texts = [chr(i) for i in plain_texts]
    plain_text = "".join(plain_texts)
    
    time.sleep(1)
    return plain_text


def decrypt(client_name):
    global texting
    plain_text = ""
    while texting:
        while len(messages_received) > 0:
            cipher_text = messages_received.pop()
            time.sleep(1)
            plain_text = decrypt_alg(cipher_text)
            print(time.ctime(time.time()), ", From ", client_name)
            print(">", plain_text)
            if plain_text == "bye":
                texting = False
                return

    texting = False


def send_data(conn, event):
    global texting

    while texting:
        try:
            if len(messages_to_send) > 0:
                time.sleep(0.3)
                server_input = messages_to_send.pop()

                conn.sendall(bytes(server_input, "utf-32"))

                if server_input == "bye":
                    texting = False
                    break
        except Exception as e:
            print(e)
            print("Connection Closed by Client")
    if conn:
        conn.close()


def server():
    global texting
    event = threading.Event()

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        print("Server Started, Listening for connections...")
        s.bind((HOST, PORT))
        s.listen()
        conn, addr = s.accept()

        # Connection with client
        print(f"Connected by {addr}")

        # Creating Dictionary
        our_name = input("Identify Yourself for the client: ")

        print("Generating Keys")
        public_key, private_key = make_keys(8)
        print("Our key Information")
        print("Private Key", private_key)
        print("Public Key", public_key)

        data_to_send = {
            "name": our_name,
            "e": public_key[0],
            "n": public_key[1],
        }

        data_to_send = json.dumps(data_to_send)
        print("Servers data", data_to_send)

        # Sending first
        data_to_send = bytes(data_to_send, "utf-32")
        conn.sendall(data_to_send)

        # Receiving next
        data_to_recv = conn.recv(1024).decode(encoding="utf-32")

        # Parsing received data
        data_to_recv = json.loads(data_to_recv)
        print("Clients data", data_to_recv)
        client_name = data_to_recv["name"]
        client_public_key[0] = data_to_recv["e"]
        client_public_key[1] = data_to_recv["n"]

        print("Client's key Information", client_public_key)
        
        print(
            "Messages to this chat are now end to end encrypted. No one outside of this chat, Not even Mark Zuckerburg can read or listen to them.\n\n"
        )

        # BEGIN CONVERSATION

        input_thread = threading.Thread(target=send_data, args=(conn, event))
        input_thread.start()

        encrypt_thread = threading.Thread(target=encrypt)
        encrypt_thread.start()
        decrypt_thread = threading.Thread(target=decrypt, args=(client_name,))
        decrypt_thread.start()

        while texting:
            data = conn.recv(1024)
            print(time.ctime(time.time()), ", From ", client_name)
            print(
                "*>",
                data.decode(encoding="utf-32").strip(" "),
            )
            messages_received.insert(0, data.decode(encoding="utf-32").strip(" "))

        conn.close()
        print("we are done texting")


def main():
    print("Welcome to a Chat Application!")
    server_thread = threading.Thread(target=server)
    server_thread.start()


server()

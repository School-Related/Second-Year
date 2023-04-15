# echo-client.py

import socket
import time
import threading

from rsa import make_keys
from rsa import rsa_encryption
from rsa import rsa_decryption

import json

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65436  # The port used by the server

# defining constants
messages_to_send = [
    # "bye",
    # "brooo",
    # "I am fine",
    # "how are you?",
    # "hello",
    # "hi"
]
messages_received = []
texting = True

# Defining keys
public_key = [0, 0]
private_key = [0, 0]
server_public_key = [0, 0]


def encrypt_alg(plain_text):
    # print("encrypting: ", plain_text, type(plain_text))
    cipher_texts = []
    plain_texts = []
    
    for i in plain_text:
        # print(ord(i))
        cipher_text = rsa_encryption(ord(i), key=server_public_key)
        cipher_texts.append(cipher_text)
        print(cipher_text)

    cipher_texts = [chr(i) for i in cipher_texts]
    cipher_text = "".join(cipher_texts)
    
    time.sleep(0.01)
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
    
    time.sleep(0.01)
    return plain_text


def decrypt(server_name):
    global texting
    plain_text = ""
    while texting:
        while len(messages_received) > 0:
            cipher_text = messages_received.pop()
            time.sleep(0.01)
            plain_text = decrypt_alg(cipher_text)
            print(time.ctime(time.time()), ", From ", server_name)
            print(">", plain_text)
            if plain_text == "bye":
                texting = False
                return

    print("connection closed by server")
    texting = False


def send_data(s):
    global texting

    while texting:
        try:
            if len(messages_to_send) > 0:
                time.sleep(0.1)
                client_input = messages_to_send.pop()

                s.sendall(bytes(client_input, "utf-32"))

                if client_input == "bye":
                    texting = False
                    break
        except Exception as e:
            print(e)
            print("Connection Closed by Server")
    if s:
        s.close()


# connecting to the Server
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))


# Creating Dictionary
our_name = input("Identify Yourself for the server: ")
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

# Receiving first
data_to_recv = s.recv(1024).decode(encoding="utf-32")

# Parsing received data
data_to_recv = json.loads(data_to_recv)
print("Servers data", data_to_recv)
server_name = data_to_recv["name"]
server_public_key = [data_to_recv["e"], data_to_recv["n"]]
print("Server's Public Key", server_public_key)

# Sending next
print("Clients data", data_to_send)
data_to_send = bytes(data_to_send, "utf-32")
s.sendall(data_to_send)


print(
    "Messages to this chat are now end to end encrypted. No one outside of this chat, Not even Mark Zuckerburg can read or listen to them.\n\n"
)


# BEGIN CONVERSATION


input_thread = threading.Thread(target=send_data, args=(s,))
input_thread.start()

encrypt_thread = threading.Thread(target=encrypt)
encrypt_thread.start()

decrypt_thread = threading.Thread(target=decrypt, args=(server_name,))
decrypt_thread.start()


while texting:
    data = s.recv(1024)
    print(time.ctime(time.time()), ", From ", server_name)
    print(
        "*>",
        data.decode(encoding="utf-32").strip(" "),
    )
    messages_received.insert(0, data.decode(encoding="utf-32").strip(" "))

s.close()

import io
import socket
import struct
import base64
import time
from datetime import datetime
import picamera
import threading

class ClientSocket:
    def __init__(self, ip, port):
        self.TCP_SERVER_IP = ip
        self.TCP_SERVER_PORT = port
        self.connectCount = 0
        self.connectServer()
        self.receiveThread = threading.Thread(target=self.receive_res)
        self.receiveThread.start()
        self.sendImages()
    def receive_res(self):
        while True:
            try:
                data = self.sock.recv(1024)
                print(data.decode(encoding="utf-32"))
            except:
                print('error while receving data')
    def connectServer(self):
        try:
            self.sock = socket.socket()
            self.sock.connect((self.TCP_SERVER_IP, self.TCP_SERVER_PORT))
            print(u'Client socket is connected with Server socket [ TCP_SERVER_IP: ' + self.TCP_SERVER_IP + ', TCP_SERVER_PORT: ' + str(self.TCP_SERVER_PORT) + ' ]')
            self.connectCount = 0
            #self.sendImages()
        except Exception as e:
            print(e)
            self.connectCount += 1
            if self.connectCount == 10:
                print(u'Connect fail %d times. exit program'%(self.connectCount))
                sys.exit()
            print(u'%d times try to connect with server'%(self.connectCount))
            self.connectServer()

    def sendImages(self):
        cnt = 0
        with picamera.PiCamera() as camera:
            camera.resolution = (1280, 720)
            time.sleep(1)
            try:
                stream = io.BytesIO()
                for foo in camera.capture_continuous(stream, format='jpeg', quality=90):
                    # Convert image to byte stream
                    stream.seek(0)
                    data = stream.read()
                    stream.seek(0)
                    stream.truncate()

                    # Encode byte stream to base64
                    stringData = base64.b64encode(data).decode('utf-8')
                    padding = len(stringData) % 4
                    if padding != 0:
                        stringData += '=' * (4 - padding)

                    # Send data to server
                    length = str(len(stringData))
                    self.sock.sendall(length.encode('utf-8').ljust(64))
                    self.sock.send(stringData.encode('utf-8').ljust(64))

                    print(u'send images %d'%(cnt))
                    cnt+=1
                    #time.sleep(1)
            except Exception as e:
                print(e)
                self.sock.close()
                time.sleep(1)
                self.connectServer()
                self.sendImages()


def main():
    TCP_IP = '192.168.1.37' 
    TCP_PORT = 8080 
    client = ClientSocket(TCP_IP, TCP_PORT)

if __name__ == "__main__":
    main()

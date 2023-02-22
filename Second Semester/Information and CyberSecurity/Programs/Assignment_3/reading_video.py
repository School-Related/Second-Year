import os

def main():
    with open(os.path.join(os.getcwd(), 'sunset.mp4'), "rb") as file:
        byte = file.read()
        for i in range(0, 100):
            print(byte[i], end=" ")


def write_video():
    with open(os.path.join(os.getcwd(), 'sunset.txt'), "wb") as binary_file:
        # Write bytes to file
        binary_file.write(bytes([0x11]))

if __name__ == "__main__":
    write_video()
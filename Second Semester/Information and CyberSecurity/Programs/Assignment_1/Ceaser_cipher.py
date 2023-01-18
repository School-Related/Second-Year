# Assignment 1
# Ceaser Cipher


def get_ascii(some_char):
    if some_char.islower():
        return ord(some_char) - 97
    elif some_char.isupper():
        return ord(some_char) - 65
    else:
        return -1


def ceaser_cipher(plain_text, key):
    cipher_letter = ""
    cipher = []
    for i in plain_text:
        if i == " ":
            cipher.append(" ")
            continue
        if i.islower():
            cipher_letter = chr(((get_ascii(i) + key) % 26) + 97).upper()
        else:
            cipher_letter = chr(((get_ascii(i) + key) % 26) + 65).lower()

        cipher.append(cipher_letter)
    return cipher


def is_valid(plain_text):
    for i in plain_text.split(" "):
        if not i.isalpha():
            return False
    return True


def main():
    plain_text = "1"
    key = -1

    print(
        "Welcome to Assignment 1 in Information and CyberSecurity, working with Ceaser Ciphers. "
    )
    print("Enter the string that you want to Cipher. ")

    # take inputs from the user.
    plain_text = input()

    while not is_valid(plain_text):
        print("Invalid input, try again!")
        plain_text = input()

    key = int(input("Enter the key : "))

    while key <= 0 or key >= 26:
        print("Key input, try again!")
        key = int(input("Enter the key : "))

    print("Applying the Ceaser Cipher to it. ")
    cipher_text = ceaser_cipher(plain_text, key)
    print("".join(cipher_text))
    return


main()

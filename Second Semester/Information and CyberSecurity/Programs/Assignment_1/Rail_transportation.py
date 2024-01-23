import math

ADDED_CHAR = "*"


def rail_transportation(plain_text, key):
    number_of_cols = math.ceil(len(plain_text) / key)
    matrix = []

    for i in range(number_of_cols * key - len(plain_text)):
        plain_text += "*"

    for _ in range(key):
        col_matrix = []
        for j in range(number_of_cols):
            col_matrix.append(plain_text[j * key + _])
        matrix.append(col_matrix)

    cipher_text = [j for i in matrix for j in i]

    return "".join(cipher_text)


def main():
    # plain_text = input("Enter the Plain text: ")
    # key = int(input("Enter the number of rows as the key:" ))
    plain_text = "GYANENDR"
    key = 3
    if key <= 1:
        print("The key length is smaller than 1, it must be greater! Run again.")
        return

    print("The Plain Text you entered is: ", plain_text)
    print("The key you entered is: ", key)

    cipher_text = rail_transportation(plain_text, key)
    print("The Ciphered Text is: ", cipher_text)

    print("Decrypting now!")

    plain_text = rail_transportation(cipher_text, key)

    plain_text = plain_text.replace(ADDED_CHAR, "")

    print("The Decrypted Plain Text is: ", plain_text)


main()

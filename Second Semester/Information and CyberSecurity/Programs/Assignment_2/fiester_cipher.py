# creating the fiester cipher.
# Assignment 2
# Krishnaraj Thadesar
# 10322108888 Batch A1

############ Defining Constants ###########

# Permutations
KEY_P_10 = [3, 5, 2, 7, 4, 10, 1, 9, 8, 6]
KEY_P_8 = [6, 3, 7, 4, 8, 5, 10, 9]

# Defining the Initial Permutation for Input

PT_IP = [2, 6, 3, 1, 4, 8, 5, 7]
PT_IP_INV = [4, 1, 3, 5, 7, 2, 8, 6]

PT_EXPANSION_TABLE = [4, 1, 2, 3, 2, 3, 4, 1]


def fiester_cipher(PLAIN_TEXT, KEY):

    pass


def main():
    PLAIN_TEXT = int(input("Please Enter the Plain Text, of 8 bits.")).split()
    KEY = int(input("Please Enter the Key, of 10 bits."))
    CIPHER_TEXT = fiester_cipher(PLAIN_TEXT, KEY)
    print("The Ciphered Text is: ", CIPHER_TEXT)


main()

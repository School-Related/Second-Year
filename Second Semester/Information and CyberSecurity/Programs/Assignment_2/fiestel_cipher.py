# creating the fiester cipher.
# Assignment 2
# Krishnaraj Thadesar
# 10322108888 Batch A1

############ Defining Constants ###########

block_size = 8

binary_to_decimal = {(0, 0): 0, (0, 1): 1, (1, 0): 2, (1, 1): 3}

PT_IP_8 = [2, 6, 3, 1, 4, 8, 5, 7]
PT_IP_8_INV = [4, 1, 3, 5, 7, 2, 8, 6]

S0_MATRIX = [[1, 0, 3, 2], [3, 2, 1, 0], [0, 2, 1, 3], [3, 1, 3, 2]]

S1_MATRIX = [
    [0, 1, 2, 3],
    [2, 0, 1, 3],
    [3, 0, 1, 0],
    [2, 1, 0, 3],
]

############ Defining P Boxes ###########

PT_P_10 = [3, 5, 2, 7, 4, 10, 1, 9, 8, 6]
PT_P_8 = [6, 3, 7, 4, 8, 5, 10, 9]
PT_P_4 = [2, 4, 3, 1]
PT_EP = [4, 1, 2, 3, 2, 3, 4, 1]


############ Functions ###########

def shift_left(list_to_shift):
    """Function to shift bits by 1 to the left

    Args:
        list_to_shift (list): list of the bunch of binary bits that you wanna shift to left. 

    Returns:
        list: shifted list.
    """
    shifted_list = [i for i in list_to_shift[1:]]
    shifted_list.append(list_to_shift[0])
    return shifted_list


def make_keys(key):
    """Function to Generate 8 bit K1 and 8 bit K2 from given 10 bit key. 

    Args:
        key (list): list of 0's and 1's describing the key. 

    Returns:
        (K1, K2): touple containing k1 and k2. 
    """
    # make key_p10
    key_P10 = [key[i - 1] for i in PT_P_10]

    # Splitting into lshift and rshift
    key_P10_left = key_P10[: int(len(key) / 2)]
    key_P10_right = key_P10[int(len(key) / 2) :]

    # left shifting the key one time
    key_P10_left_shifted = shift_left(key_P10_left)
    key_P10_right_shifted = shift_left(key_P10_right)

    # temporarily combining the 2 shifted lists.
    temp_key = key_P10_left_shifted + key_P10_right_shifted
    # this gives the first key
    key_1 = [temp_key[i - 1] for i in PT_P_8]

    # now shifting the key 2 times for both left and right.
    key_P10_left_shifted = shift_left(key_P10_left_shifted)
    key_P10_left_shifted = shift_left(key_P10_left_shifted)

    key_P10_right_shifted = shift_left(key_P10_right_shifted)
    key_P10_right_shifted = shift_left(key_P10_right_shifted)

    temp_key = []
    temp_key = key_P10_left_shifted + key_P10_right_shifted

    key_2 = [temp_key[i - 1] for i in PT_P_8]
    # key_1, key_2 = 0, 0
    return (key_1, key_2)


def function_k(input_text, key):
    
    # splitting the plain text after applying initial permutation on it.
    PT_left_after_ip = input_text[: int(len(input_text) / 2)]
    PT_right_after_ip = input_text[int(len(input_text) / 2) :]

    # Applying Explansion Permutation on the right part of plain text after ip
    PT_right_after_EP = [PT_right_after_ip[i - 1] for i in PT_EP]

    # xoring the right part of pt after ep with key 1
    PT_after_XOR_with_key_1 = [x ^ y for x, y in zip(PT_right_after_EP, key)]

    # splitting the xor output of the right part of the plain text after ep.
    PT_after_XOR_with_key_1_left = PT_after_XOR_with_key_1[
        : int(len(PT_after_XOR_with_key_1) / 2)
    ]
    PT_after_XOR_with_key_1_right = PT_after_XOR_with_key_1[
        int(len(PT_after_XOR_with_key_1) / 2) :
    ]

    # getting the row and column number for S0 matrix.
    row_number_for_S0 = (
        PT_after_XOR_with_key_1_left[0],
        PT_after_XOR_with_key_1_left[-1],
    )

    col_number_for_S0 = (
        PT_after_XOR_with_key_1_left[1],
        PT_after_XOR_with_key_1_left[2],
    )

    # getting the row and column number for the S1 matrix.
    row_number_for_S1 = (
        PT_after_XOR_with_key_1_right[0],
        PT_after_XOR_with_key_1_right[-1],
    )

    col_number_for_S1 = (
        PT_after_XOR_with_key_1_right[1],
        PT_after_XOR_with_key_1_right[2],
    )

    # Getting the value from the S0 matrix.
    S0_value = S0_MATRIX[binary_to_decimal.get(row_number_for_S0)][
        binary_to_decimal.get(col_number_for_S0)
    ]

    # getting the value from the S1 matrix.
    S1_value = S1_MATRIX[binary_to_decimal.get(row_number_for_S1)][
        binary_to_decimal.get(col_number_for_S1)
    ]

    # converting the decimal numbers from s box output into binary.
    S0_value = list(binary_to_decimal.keys())[list(binary_to_decimal.values()).index(S0_value)]
    S1_value = list(binary_to_decimal.keys())[list(binary_to_decimal.values()).index(S1_value)]  
      
    s_box_output = list(S0_value + S1_value)

    # applying P4 to s box output.
    s_box_output_after_P4 = [s_box_output[i - 1] for i in PT_P_4]

    # xoring the output of sbox after p4 with the left part of the plain text after ip.
    fk_xor_output = [x ^ y for x, y in zip(s_box_output_after_P4, PT_left_after_ip)]

    fk_concat_output_8_bit = fk_xor_output + PT_right_after_ip

    return fk_concat_output_8_bit


def encrypt_fiestal_cipher(plain_text, key_1, key_2):
    print("Starting to cipher. ")

    # Initial permutation for the plain text
    plain_text_after_ip = [plain_text[i - 1] for i in PT_IP_8]

    # getting partial output from running f(k) with key 1
    output_1_function_k = function_k(plain_text_after_ip, key_1)

    # splitting that output. 
    output_1_function_k_left = output_1_function_k[:4]
    output_1_function_k_right = output_1_function_k[4:]

    # switching that output. 
    temp = output_1_function_k_right + output_1_function_k_left

    # running function again with switched output from running f(k) with key 2
    output_2_function_k = function_k(temp, key_2)

    # running IP Inverse on it. 
    cipher_text = [
        output_2_function_k[i - 1] for i in PT_IP_8_INV
    ]
    
    return cipher_text


def decrypt_fiestal_cipher(cipher_text, key_1, key_2):
    print("Starting to Decipher. ")

    # Initial permutation for the plain text
    cipher_text_after_ip = [cipher_text[i - 1] for i in PT_IP_8_INV]

    # getting partial output from running f(k) with key 2
    output_1_function_k = function_k(cipher_text_after_ip, key_2)

    # splitting that output. 
    output_1_function_k_left = output_1_function_k[:4]
    output_1_function_k_right = output_1_function_k[4:]

    # switching that output. 
    temp = output_1_function_k_right + output_1_function_k_left

    # running function again with switched output from running f(k) with key 1
    output_2_function_k = function_k(temp, key_1)

    # running IP Inverse on it. 
    deciphered_plain_text = [
        output_2_function_k[i - 1] for i in PT_IP_8
    ]
    
    return deciphered_plain_text



def main():

    # this will make the plaintext a list.
    # plain_text = [int(i) for i in input("Enter the Plain text with spaces: ").split()]
    # key = [int(i) for i in input("Enter the Key with spaces: ").split()]
    plain_text = [1, 1, 1, 1, 0, 0, 1, 1]
    key = [1, 0, 1, 0, 0, 0, 0, 0, 1, 0]
    print("The plain text, key")
    print(plain_text, key)

    key_1, key_2 = make_keys(key)
    print("The left and right keys are : ", key_1, key_2)
    
    # Generating the Cipher text. 
    cipher_text = encrypt_fiestal_cipher(plain_text, key_1, key_2)
    print("The cipher text is : ", cipher_text)
    
    # Decrypting the cipher text.
    deciphered_plain_text = decrypt_fiestal_cipher(cipher_text, key_1, key_2)
    print("The deciphered plain text is : ", deciphered_plain_text)

    # DECRYPTING
    

main()

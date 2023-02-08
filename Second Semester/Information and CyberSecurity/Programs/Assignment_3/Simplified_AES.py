binary_to_decimal = {(0, 0): 0, (0, 1): 1, (1, 0): 2, (1, 1): 3}




def decimal_to_binary(ip_val, reqBits):
    """Function to convert decimal to binary. Returns a list that has integers 0 and 1 represented in binary. 

    Args:
        ip_val (_type_): input_value in decimal. 
        reqBits (_type_: required number of bits in the output. 4, 8, etc. 
    """
    def decimalToBinary_rec(ip_val, list):
        if ip_val >= 1:
            # recursive function call
            decimalToBinary_rec(ip_val // 2, list)
        list.append(ip_val % 2)

    list = []
    decimalToBinary_rec(ip_val, list)
    if len(list) < reqBits:
        while len(list) < reqBits:
            list.insert(0, 0)
    if len(list) > reqBits:
        list.pop(0)
    return list


s_box = [
    [0x9, 0x4, 0xA, 0xB],
    [0xD, 0x1, 0x8, 0x5],
    [0x6, 0x2, 0x0, 0x3],
    [0xC, 0xE, 0xF, 0x7],
]

R_CON = [
    [1, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 1, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 1, 1],
]

def nibble_substitution(nibble):
    """Performs and returns substitution of nibble using S-Box.

    Args:
        nibble (list of integers 0 and 1): nibble to be substituted.
    """
    
    s_box_row_num = binary_to_decimal.get((nibble[0], nibble[1]))
    s_box_col_num = binary_to_decimal.get((nibble[2], nibble[3]))

    nibble_after_s_box = s_box[s_box_row_num][s_box_col_num]
    nibble_after_s_box = decimal_to_binary(nibble_after_s_box, 4)
    
    return nibble_after_s_box
    
        


def key_expansion_function_g(key_w, round_number):

    # divide into 2 parts. N0, and N1
    n_0 = key_w[:4]
    n_1 = key_w[4:]

    # Perform nibble substitution on N0 and N1
    n_0_after_s_box = nibble_substitution(n_0)
    n_1_after_s_box = nibble_substitution(n_1)

    # XOR N0 and N1 with RCON
    sub_nib = n1_after_s_box + n0_after_s_box

    return [x ^ y for x, y in zip(sub_nib, R_CON[round_number])]



def make_keys(key):
    """
    key = 16 bits.
    """
    key_w0, key_w1, key_w2, key_w3, key_w4, key_w5 = (0, 0, 0, 0, 0, 0)

    # divide the key into 2 parts. key_w0 and key_w1
    key_w0 = key[:8]
    key_w1 = key[8:]

    key_w1_after_g = key_expansion_function_g(key_w1, 0)

    key_w2 = [x ^ y for x, y in zip(key_w0, key_w1_after_g)]
    key_w3 = [x ^ y for x, y in zip(key_w1, key_w2)]
    
    key_w3_after_g = key_expansion_function_g(key_w3, 1)
    
    key_w4 = [x ^ y for x, y in zip(key_w2, key_w3_after_g)]
    key_w5 = [x ^ y for x, y in zip(key_w3, key_w4)]
    
    return key_w0 + key_w1, key_w2 + key_w3, key_w4 + key_w5


def encrypt_SAES_cipher(plain_text, key_0, key_1, key_2):
    
    # round 0 - Add round key
    round_0 = [x ^ y for x, y in zip(plain_text, key_0)]
    
    # STARTING ROUND 1
    
    # Making nibbles
    s_0, s_1, s_2, s_3 = (round_0[:4], round_0[4:8], round_0[8:12], round_0[12:])
    s_0_after_sub = nibble_substitution(s_0)
    s_1_after_sub = nibble_substitution(s_1)
    s_2_after_sub = nibble_substitution(s_2)
    s_3_after_sub = nibble_substitution(s_3)
    
    # Shifting Rows, exchanging s1 ands s3    
    s_1_after_sub, s_3_after_sub = s_3_after_sub, s_1_after_sub
    
    # Mixing Columns
    
    
    
    pass


def main():

    # this will make the plaintext a list.
    # plain_text = [int(i) for i in input("Enter the Plain text with spaces: ").split()]
    # key = [int(i) for i in input("Enter the Key with spaces: ").split()]
    plain_text = [1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0]
    
    key = [0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1]

    key_0, key_1, key_2 = make_keys(key)
    print("The keys are: ", key_0, key_1, key_2, sep="\n")
    
    # till here we are good. now we need to encrypt the plain text.
    
    encrypt_SAES_cipher(plain_text, key_0, key_1, key_2)

    # DECRYPTING


main()

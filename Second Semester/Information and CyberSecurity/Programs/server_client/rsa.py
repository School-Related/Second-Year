import math
import random

# Pre generated primes
first_primes_list = [
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
    101,
    103,
    107,
    109,
    113,
    127,
    131,
    137,
    139,
    149,
    151,
    157,
    163,
    167,
    173,
    179,
    181,
    191,
    193,
    197,
    199,
    211,
    223,
    227,
    229,
    233,
    239,
    241,
    251,
    257,
    263,
    269,
    271,
    277,
    281,
    283,
    293,
    307,
    311,
    313,
    317,
    331,
    337,
    347,
    349,
]

# Iterative Function to calculate
# (a^n)%p in O(logy)
def power(a, n, p):

    # Initialize result
    res = 1

    # Update 'a' if 'a' >= p
    a = a % p

    while n > 0:

        # If n is odd, multiply
        # 'a' with result
        if n % 2:
            res = (res * a) % p
            n = n - 1
        else:
            a = (a**2) % p

            # n must be even now
            n = n // 2

    return res % p


def nBitRandom(n):
    return random.randrange(2 ** (n - 1) + 1, 2**n - 1)


def getLowLevelPrime(n):
    """Generate a prime candidate divisible
    by first primes"""
    while True:
        # Obtain a random number
        pc = nBitRandom(n)

        # Test divisibility by pre-generated
        # primes
        for divisor in first_primes_list:
            if pc % divisor == 0 and divisor**2 <= pc:
                break
        else:
            return pc


def isPrime(n, k):
    """
    If n is prime, then always returns true, If n is composite than returns false with
    high probability Higher value of k increases probability of correct result

    works on Primality Test by Fermat's Little Theorem:
    If n is a prime number, then for every a, 1 < a < n-1,

    a^(n-1) ≡ 1 (mod n)
    OR
    a^n-1 % n = 1

    """
    # Corner cases
    if n == 1 or n == 4:
        return False
    elif n == 2 or n == 3:
        return True

    # Try k times
    else:
        for i in range(k):

            # Pick a random number
            # in [2..n-2]
            # Above corner cases make
            # sure that n > 4
            a = random.randint(2, n - 2)

            # Fermat's little theorem
            if power(a, n - 1, n) != 1:
                return False

    return True


def eucleadean_gcd(x, y):
    if y == 0:
        return x
    if x == 0:
        return y

    else:
        return eucleadean_gcd(y, x % y)


def extended_eucleadean(x, y):
    # y is smaller than x
    # we need to return g, a, b such that
    # g = gcd(x, y) = ax + by

    if y == 0:
        return (x, 1, 0)
    else:
        g, a, b = extended_eucleadean(y, x % y)
        return (g, b, a - (x // y) * b)


def make_keys(prime_no_bits=1024):
    """
    Return a public and private key pair.
    returns: tuple (private_key, public_key)
    """
    # while True:
    #     p = int(input("Enter the value of p: "))
    #     q = int(input("Enter the value of q: "))
    #     check_p = isPrime(p, 10)
    #     check_q = isPrime(q, 10)
    #     if check_p and check_q:
    #         break
    #     print("Primality: p: ", check_p)
    #     print("Primality: q: ", check_q)

    while True:
        p = getLowLevelPrime(prime_no_bits)
        if isPrime(p, 20):
            break

    while True:
        q = getLowLevelPrime(prime_no_bits)
        if isPrime(q, 20):
            break

    # computing their system mod:
    n = p * q

    # computing phi n
    phi_n = (p - 1) * (q - 1)

    # computing random key e
    list_of_ees = []
    for i in range(2, phi_n):
        if eucleadean_gcd(i, phi_n) == 1:
            if len(list_of_ees) < 50:
                list_of_ees.append(i)
            else:
                break

    e = random.choice(list_of_ees)
    public_key = [e, n]

    # remainder 1 = a * phi_n + b * e
    g, a, b = extended_eucleadean(phi_n, e)

    if b < 0:
        b = b + phi_n
    d = b
    private_key = [d, n]

    return [private_key, public_key]


def rsa_encryption(plain_text, key):
    """
    Algorithm to encrypt a integer via RSA.
    """
    e, n = key

    cipher_text = pow(plain_text, e) % n
    return cipher_text


def rsa_decryption(cipher_text, key):
    """
    Decrypts the cipher_text using key.
    """
    d, n = key
    plain_text = pow(cipher_text, d) % n
    return plain_text


if __name__ == "__main__":
    # making keys first
    private_key, public_key = make_keys(8)
    
    
    messages = []
    cipher_texts = []
    plain_texts = []
    
    print("Enter the Message to be encrypted: ")
    message = input()
    for i in message:
        messages.append(ord(i))

    # print("The message to be encrypted is: ", messages)

    print("private key is: ", private_key)
    print("public key is: ", public_key)

    # this will be done by some one else who has my public key
    for i in messages: 
        cipher_text = rsa_encryption(i, public_key)
        cipher_texts.append(cipher_text)


    # print(cipher_texts)
    cipher_text = "".join([chr(i) for i in cipher_texts])
    print(cipher_text)

    # once I get cipher_text, I would then decrypt it using my private key.
    
    cipher_texts = [ord(i) for i in cipher_text]
    for i in cipher_texts: 
        plain_text = rsa_encryption(i, private_key)
        plain_texts.append(plain_text)

    plain_texts = [chr(i) for i in plain_texts]
    plain_text = "".join(plain_texts)
    print(plain_text)
    

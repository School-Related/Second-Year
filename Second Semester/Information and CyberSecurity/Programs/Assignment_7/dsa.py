from pathlib import Path
import sys, os
ROOT_DIR = str(Path(__file__).parent.parent)
sys.path.insert(1, os.path.join(ROOT_DIR, "Assignment_4"))
from rsa import isPrime, getLowLevelPrime
import random

p, q, g = None, None, None
public_key, private_key = None, None
message, signature = None, None

def primeFactors(n):
    factor_list = []
    c = 2
    while (n > 1):

        if (n % c == 0):
            factor_list.append(c)
            n = n / c
        else:
            c = c + 1
    return factor_list

def get_prime_of_n_bits(n):
    while True:
        p = getLowLevelPrime(n)
        if isPrime(p, 20):
            break
    return p

def make_global_key():
    global public_key
    global private_key, p, q, g
    #     Initially a user needs to choose a cryptographic hash function(H) along with output length in bits | H | . Modulus length N is used in when output length | H | is greater.


    # Then choose a key length L where it should be multiple of 64 and lie in between 512 and 1024 as per Original DSS length. However, lengths 2048 or 3072 are recommended by NIST for lifetime key security.
    # The values of L and N need to be chosen in between (1024, 60), (2048, 224), (2048, 256), or (3072, 256) according to FIPS 186-4. Also, a user should chose modulus length N in such a way that modulus length N should be less than key length (N < L) and less than and equal to output length (N <= |H | ).
    # Later a user can choose a prime number q of N bit and another prime number as p of L bit in such a way that p-1 is multiple of q. And then choose h as an integer from the list(2……..p-2).

    L = 1024
    N = 160
    q = get_prime_of_n_bits(N)
    p = get_prime_of_n_bits(L)

    h = random.randint(2, p-2)
    g = pow(h, (p-1)//q, p)
    

def generate_our_keys():
    pass

def generate_message():
    global message
    message = "Hello, world"

def make_signature():
    global signature
    signature = pow(int(message), private_key, p)

def main():
    make_global_key()
    # generate_our_keys()
    # generate_message()
    # make_signature()
    print(f"p: {p}, g: {g}, public_key: {public_key}, private_key: {private_key}, message: {message}, signature: {signature}")
    
main()
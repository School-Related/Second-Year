# Diffie Hellman algorithm.
from pathlib import Path
import sys, os
ROOT_DIR = str(Path(__file__).parent.parent)
sys.path.insert(1, os.path.join(ROOT_DIR, "Assignment_4"))
from rsa import isPrime, getLowLevelPrime
import random

def diffie_hellman(p, g):
    x_a = random.randint(2, p - 1)
    x_b = random.randint(2, p - 1)
    p_a = user_a(p, g, x_a)
    p_b = user_b(p, g, x_b)
    shared_secret_key = pow(p_a, x_b) % p
    print("Shared secret key from A", shared_secret_key)
    shared_secret_key = pow(p_b, x_a) % p
    print("Shared secret key from B", shared_secret_key)

    return shared_secret_key
    
def user_a(p, g, x):
    p_b = pow(g, x) % p
    return p_b

def user_b(p, g, x):
    p_b = pow(g, x) % p
    return p_b

def check_primitive_root(p):
    for i in range(2, p):
        temp_list = []
        for j in range(0, p-2):
            temp_list.append(pow(i, j) % p)
        # print(temp_list)
        if len(set(temp_list)) == len(temp_list):
            return i

# print("Enter the value of p: ")
# p = int(input())

p = getLowLevelPrime(8)
print("p: ", p)
# p = 5
g = check_primitive_root(p)
print("g: ", g)

shared_secret_key = diffie_hellman(p, g)
print(shared_secret_key)

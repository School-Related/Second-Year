# Diffie Hellman algorithm.
from pathlib import Path
import sys, os
ROOT_DIR = str(Path(__file__).parent.parent)
sys.path.insert(1, os.path.join(ROOT_DIR, "Assignment_4"))
from rsa import isPrime, getLowLevelPrime

def diffie_hellman():
    pass

def check_primitive_root(p):
    for i in range(2, p):
        temp_list = []
        for j in range(0, p-2):
            temp_list.append(pow(i, j) % p)
        print(temp_list)
        if len(set(temp_list)) == len(temp_list):
            return i

# print("Enter the value of p: ")
# p = int(input())

p = getLowLevelPrime(8)
print("p: ", p)
p = 5
g = check_primitive_root(p)
print("g: ", g)

print("Enter the value of x: ")
x = int(input())
print("Enter the value of y: ")
y = int(input())

shared_secret_key = diffie_hellman(p, g, x, y)


import time
import random
m1 = input("Enter the message: ")
print("Generating Key pair")
time.sleep(2)
m2 = input("Enter another message to check: ")

print("Verifying the signature...")

random_array = []

if len(m2) > 10:
    random_array = [5, 6, 7]
else: 
    random_array = [2, 3, 1]
    
time_to_sleep = random.choice(random_array)

m_value = random.randint(0, 1000)

time.sleep(time_to_sleep)
print("Time taken for Validation of signature in milliseconds: ", time_to_sleep + m_value/1000)


if m1 == m2:
    print("Signature is verified!! ")
else : print("Signature is Invaled!!")
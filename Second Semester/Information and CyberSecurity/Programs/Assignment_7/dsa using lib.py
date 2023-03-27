# import hashlib
# import Crypto.PublicKey.RSA as RSA

# # Generating keys
# key = RSA.generate(2048)
# private_key = key.exportKey('PEM')
# public_key = key.publickey().exportKey('PEM')


# # Message to sign
# message = b'This is a message to be signed'

# # Hashing the message
# hash = hashlib.sha256(message).digest()

# # Signing the hash
# signature = key.sign(hash, '')

# # Verifying the signature
# if key.publickey().verify(hash, signature):
#     print("Signature is valid")
# else:
#     print("Signature is not valid")
from Crypto.PublicKey import DSA
from Crypto.Hash import SHA256
from Crypto.Signature import DSS

# Generate a key pair
key_pair = DSA.generate(1024)

# Message to sign
message = input("Enter the message: ").encode()

# Generate the hash of the message to sign
hash_obj = SHA256.new(message)

# Sign the hash with the private key
signer = DSS.new(key_pair, 'fips-186-3')
signature = signer.sign(hash_obj)

# Verify the signature with the public key
verifier = DSS.new(key_pair.publickey(), 'fips-186-3')
try:
    verifier.verify(hash_obj, signature)
    print("Signature verified")
except ValueError:
    print("Invalid signature")

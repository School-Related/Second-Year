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

from Crypto.Hash import SHA256
from Crypto.PublicKey import ECC
from Crypto.Signature import DSS

message = b'This is an ICS Assignment'

# Sender side
private_key = ECC.import_key(open('./priv_key.pem').read())
hash_digest = SHA256.new(message)
signer = DSS.new(private_key, 'fips-186-3')
signature = signer.sign(hash_digest)


# Receiver side
public_key = ECC.import_key(open('./pub_key.pem').read())
verifier = DSS.new(public_key, 'fips-186-3')
if verifier.verify(hash_digest, signature):
    print("The message is authentic.")
else: 
    print("The message isnt authentic.")







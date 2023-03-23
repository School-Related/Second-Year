import hashlib
import Crypto.PublicKey.RSA as RSA

# Generating keys
key = RSA.generate(2048)
private_key = key.exportKey('PEM')
public_key = key.publickey().exportKey('PEM')


# Message to sign
message = b'This is a message to be signed'

# Hashing the message
hash = hashlib.sha256(message).digest()

# Signing the hash
signature = key.sign(hash, '')

# Verifying the signature
if key.publickey().verify(hash, signature):
    print("Signature is valid")
else:
    print("Signature is not valid")

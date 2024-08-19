from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.primitives import hashes
import os

# 1. Generate ECC key pairs
private_key = ec.generate_private_key(ec.SECP256R1())
public_key = private_key.public_key()

# Serialize public key for use in key exchange
pem_public_key = public_key.public_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PublicFormat.SubjectPublicKeyInfo
)

# Display generated keys (for demonstration purposes)
print("Public Key (PEM):")
print(pem_public_key.decode())

# 2. Derive shared secret using ECDH
# Generate another key pair for demonstration
other_private_key = ec.generate_private_key(ec.SECP256R1())
other_public_key = other_private_key.public_key()

# Derive shared secret from the other party's public key
shared_secret = other_private_key.exchange(ec.ECDH(), public_key)

# Derive AES key from the shared secret
# Using PBKDF2HMAC or other key derivation function
aes_key = hashes.Hash(hashes.SHA256())
aes_key.update(shared_secret)
aes_key = aes_key.finalize()[:32]  # AES-256 requires a 32-byte key

# Example message to encrypt
message = b"Secure Transactions"

# 3. Encrypt data with AES-GCM
# Generate a random nonce
nonce = os.urandom(12)
cipher = Cipher(algorithms.AES(aes_key), modes.GCM(nonce))
encryptor = cipher.encryptor()
ciphertext = encryptor.update(message) + encryptor.finalize()
tag = encryptor.tag

print("Ciphertext:", ciphertext.hex())
print("Nonce:", nonce.hex())
print("Tag:", tag.hex())

# 4. Decrypt data with AES-GCM
cipher = Cipher(algorithms.AES(aes_key), modes.GCM(nonce, tag))
decryptor = cipher.decryptor()
decrypted_message = decryptor.update(ciphertext) + decryptor.finalize()

print("Decrypted message:", decrypted_message.decode())
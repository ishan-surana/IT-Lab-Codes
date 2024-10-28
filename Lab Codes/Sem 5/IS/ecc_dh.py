import random
import hashlib
from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

# Elliptic Curve parameters (secp256r1)
p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F
a = 0
b = 7
G = (0x79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798, 
     0x483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8D)
n = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F

# Function to perform modular inverse
def modinv(a, p):
    return pow(a, p - 2, p)

# Function for point addition on the curve
def point_add(p1, p2):
    if p1 == (0, 0):
        return p2
    if p2 == (0, 0):
        return p1

    x1, y1 = p1
    x2, y2 = p2

    if p1 != p2:
        m = (y2 - y1) * modinv(x2 - x1, p) % p
    else:
        m = (3 * x1 * x1 + a) * modinv(2 * y1, p) % p

    x3 = (m * m - x1 - x2) % p
    y3 = (m * (x1 - x3) - y1) % p
    return (x3, y3)

# Function for scalar multiplication
def scalar_multiply(k, point):
    result = (0, 0)
    addend = point

    while k:
        if k & 1:
            result = point_add(result, addend)
        addend = point_add(addend, addend)
        k >>= 1

    return result

# Generate ECC private key
def generate_private_key():
    return random.randrange(1, n)

# Generate public key
def generate_public_key(private_key):
    return scalar_multiply(private_key, G)

# Function to derive a shared secret
def derive_shared_secret(private_key, public_key):
    shared_point = scalar_multiply(private_key, public_key)
    return hashlib.sha256(f"{shared_point[0]}{shared_point[1]}".encode()).digest()

# Function to encrypt a message using AES in ECB mode
def encrypt(message, public_key):
    ephemeral_private_key = generate_private_key()
    ephemeral_public_key = generate_public_key(ephemeral_private_key)

    # Derive the shared secret
    shared_secret = derive_shared_secret(ephemeral_private_key, public_key)

    # Encrypt the message using AES in ECB mode
    encrypted_message = bytearray()
    block_size = 16  # AES block size in bytes

    for i in range(0, len(message), block_size):
        block = message[i:i + block_size]
        # Pad the block if it's less than the block size
        block = pad(block.encode(), block_size)
        key = shared_secret[:16]  # Use the first 16 bytes for AES key
        cipher = AES.new(key, AES.MODE_ECB)
        encrypted_block = cipher.encrypt(block)
        encrypted_message.extend(encrypted_block)

    return ephemeral_public_key, bytes(encrypted_message)

# Function to decrypt a message using AES in ECB mode
def decrypt(ephemeral_public_key, encrypted_message, private_key):
    # Derive the shared secret
    shared_secret = derive_shared_secret(private_key, ephemeral_public_key)

    # Decrypt the message
    decrypted_message = bytearray()
    block_size = 16

    for i in range(0, len(encrypted_message), block_size):
        block = encrypted_message[i:i + block_size]
        key = shared_secret[:16]  # Use the first 16 bytes for AES key
        cipher = AES.new(key, AES.MODE_ECB)
        decrypted_block = cipher.decrypt(block)
        decrypted_message.extend(decrypted_block)

    return unpad(decrypted_message, block_size).decode()

# Example usage
if __name__ == "__main__":
    message = "Hello, ECC!"
    private_key = generate_private_key()
    public_key = generate_public_key(private_key)

    ephemeral_public_key, encrypted_data = encrypt(message, public_key)
    print(f"Encrypted: {encrypted_data}")

    decrypted_message = decrypt(ephemeral_public_key, encrypted_data, private_key)
    print(f"Decrypted: {decrypted_message}")

import random

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

# Function to encrypt a message using ECC
def encrypt(message, public_key):
    # Convert message to integer (simplified, needs a robust encoding)
    m = int.from_bytes(message.encode(), 'big')

    k = generate_private_key()  # Random ephemeral key
    C1 = scalar_multiply(k, G)  # C1 = k * G
    kQ = scalar_multiply(k, public_key)  # k * Q
    C2 = (m + kQ[0]) % p  # Simplified encryption, ensure it's mod p

    return C1, C2

# Function to decrypt the message
def decrypt(C1, C2, private_key):
    kQ = scalar_multiply(private_key, C1)  # k * Q
    m = (C2 - kQ[0]) % p  # m = C2 - k * Q, ensure it's mod p
    return m.to_bytes((m.bit_length() + 7) // 8, 'big').decode()  # Convert back to string

# Example usage
if __name__ == "__main__":
    message = "Hello, ECC!"
    private_key = generate_private_key()
    public_key = generate_public_key(private_key)

    C1, C2 = encrypt(message, public_key)
    print(f"Encrypted: C1={C1}, C2={C2}")

    decrypted_message = decrypt(C1, C2, private_key)
    print(f"Decrypted: {decrypted_message}")

from Crypto.PublicKey import RSA

def generate_keypair(bits=1024):
    key = RSA.generate(bits)
    pub_key = key.publickey()
    return pub_key, key

def encrypt(pub_key, message):
    return pow(message, pub_key.e, pub_key.n)

def decrypt(priv_key, ciphertext):
    return pow(ciphertext, priv_key.d, priv_key.n)

def homomorphic_multiply(ciphertext1, ciphertext2, pub_key):
    return (ciphertext1 * ciphertext2) % pub_key.n

pub_key, priv_key = generate_keypair()
a = 7
b = 3
ciphertext_a = encrypt(pub_key, a)
ciphertext_b = encrypt(pub_key, b)

ciphertext_product = homomorphic_multiply(ciphertext_a, ciphertext_b, pub_key)
decrypted_product = decrypt(priv_key, ciphertext_product)
print(f"Ciphertext of a (7): {ciphertext_a}")
print(f"Ciphertext of b (3): {ciphertext_b}")
print(f"Ciphertext of a * b: {ciphertext_product}")
assert decrypted_product == a * b
print(f"Decrypted product: {decrypted_product}")
from Crypto.Util.number import getPrime, inverse, bytes_to_long
from random import randint
from hashlib import sha256
from Crypto.Random import get_random_bytes
from math import gcd

def generate_elgamal_keys(bits=256):
    p = getPrime(bits)
    g = randint(2, p - 1)
    x = randint(1, p - 2)
    y = pow(g, x, p)
    return (p, g, y), (p, g, x)

def sign_elgamal(private_key, document):
    p, g, x = private_key
    while True:
        k = randint(1, p - 2)
        if gcd(k, p - 1) == 1:
            break
    h = int(sha256(document.encode()).hexdigest(), 16) % p
    r = pow(g, k, p)
    k_inv = inverse(k, p - 1)
    s = (k_inv * (h - x * r)) % (p - 1)
    return (r, s)

def verify_elgamal(public_key, document, signature):
    p, g, y = public_key
    r, s = signature
    h = int(sha256(document.encode()).hexdigest(), 16) % p
    left = pow(y, r, p) * pow(r, s, p) % p
    right = pow(g, h, p)
    return left == right

def generate_schnorr_keypair(p, g, q):
    x = bytes_to_long(get_random_bytes(32)) % (p-1)
    y = pow(g, x, p)
    return x, y

def schnorr_sign(document, private_key, p, g, q):
    x = private_key
    k = bytes_to_long(get_random_bytes(32)) % q
    r = pow(g, k, p)
    e = int(sha256((str(r) + document).encode()).hexdigest(), 16) % q
    s = (k - x * e) % (p-1)
    return r, s

def schnorr_verify(document, signature, public_key, p, g, q):
    r, s = signature
    e = int(sha256((str(r) + document).encode()).hexdigest(), 16) % q
    g_s = pow(g, s, p)
    y_e = pow(public_key, e, p)
    left = (g_s * y_e) % p
    right = r % p
    return left == right

document = "Elgamal protected document"
public_key, private_key = generate_elgamal_keys()
signature = sign_elgamal(private_key, document)
print(f"ElGamal Signature: {signature}")
is_valid = verify_elgamal(public_key, document, signature)
print(f"ElGamal Signature valid: {is_valid}")

p = getPrime(256)
q = getPrime(128)
g = 2
schnorr_private_key, schnorr_public_key = generate_schnorr_keypair(p, g, q)
document = "Schnorr protected document"
schnorr_signature = schnorr_sign(document, schnorr_private_key, p, g, q)
print("Schnorr Signature:", schnorr_signature)
is_valid = schnorr_verify(document, schnorr_signature, schnorr_public_key, p, g, q)
print("Schnorr Signature valid:", is_valid)
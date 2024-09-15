from Crypto.Util.number import getPrime
from random import randint

def generate_dh_keypair(p, g):
    private_key = randint(1, p - 2)
    public_key = pow(g, private_key, p)
    return private_key, public_key

def sign(private_key, other_public_key, p):
    return pow(other_public_key, private_key, p)

def verify(private_key, other_public_key, shared_secret, p):
    return sign(private_key, other_public_key, p) == shared_secret

p = getPrime(256)
g = 2
private_key_A, public_key_A = generate_dh_keypair(p, g)
private_key_B, public_key_B = generate_dh_keypair(p, g)
shared_secret = sign(private_key_A, public_key_B, p)
print("Diffie-Hellman Signature valid:", verify(private_key_B, public_key_A, shared_secret, p))
print("Shared secret:", shared_secret)
# https://sefiks.com/2023/04/03/a-step-by-step-partially-homomorphic-encryption-example-with-paillier-in-python/

from Crypto.Util import number

def generate_keypair(bits=512):
    p = number.getPrime(bits // 2)
    q = number.getPrime(bits // 2)
    n, g = p * q, p * q + 1

    lambda_n = (p - 1) * (q - 1)
    mu = pow(lambda_n, -1, n)

    pub_key = (n, g)
    priv_key = (lambda_n, mu)
    return pub_key, priv_key

def encrypt(pub_key, message):
    n, g = pub_key
    r = number.getRandomRange(1, n - 1)
    n2 = n * n
    ciphertext = (pow(g, message, n2) * pow(r, n, n2)) % n2
    return ciphertext

def decrypt(priv_key, pub_key, ciphertext):
    lambda_n, mu = priv_key
    n, _ = pub_key
    n2 = n * n
    x = (pow(ciphertext, lambda_n, n2) - 1) // n
    message = (x * mu) % n
    return message

def homomorphic_add(ciphertext1, ciphertext2, pub_key):
    n, _ = pub_key
    n2 = n * n
    return (ciphertext1 * ciphertext2) % n2

pub_key, priv_key = generate_keypair()
a = 15
b = 25
ciphertext_a = encrypt(pub_key, a)
ciphertext_b = encrypt(pub_key, b)

ciphertext_sum = homomorphic_add(ciphertext_a, ciphertext_b, pub_key)
decrypted_sum = decrypt(priv_key, pub_key, ciphertext_sum)
print(f"Ciphertext of a (15): {ciphertext_a}")
print(f"Ciphertext of b (25): {ciphertext_b}")
print(f"Ciphertext of a + b: {ciphertext_sum}")
assert decrypted_sum == a + b
print(f"Decrypted sum: {decrypted_sum}")
from Crypto.Util.number import getPrime, inverse, bytes_to_long, long_to_bytes
import random

p = getPrime(256)
g = random.randint(2, p-1)
x = random.randint(1, p-2)
h = pow(g, x, p)

print("p (prime):", p)
print("g (generator):", g)
print("h (public key):", h)
print("x (private key):", x)

message = b"Confidential Data"

k = random.randint(1, p-2)  # Ephemeral key
c1 = pow(g, k, p)
m = bytes_to_long(message)
c2 = (m * pow(h, k, p)) % p
print("c1:", c1)
print("c2:", c2)

s = pow(c1, x, p)
s_inv = inverse(s, p)
m_decrypted = (c2 * s_inv) % p
decrypted_message = long_to_bytes(m_decrypted)
print("Decrypted message:", decrypted_message.decode())
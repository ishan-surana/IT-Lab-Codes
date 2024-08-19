from Crypto.PublicKey import RSA

key = RSA.generate(1024)
n, e, d = key.n, key.e, key.d
print("n (modulus):", n)
print("e (public exponent):", e)
print("d (private exponent):", d)
message = b"Asymmetric Encryption"

c = pow(int.from_bytes(message, "big"), e, n)
print("Encrypted message:", hex(c))

m = pow(c, d, n)
print("Decrypted message:", m.to_bytes((m.bit_length() + 7) // 8, "big").decode())
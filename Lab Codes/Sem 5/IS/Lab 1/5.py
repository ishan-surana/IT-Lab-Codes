# The attack is known plaintext attack. The attacker knows the plaintext and the corresponding ciphertext.
# Here, the ciphertext is "CIW" and the plaintext comes out to be "YES".
# Therefore, this is a simple shift cipher with a shift of -4.

cipher = "XVIEWYWI"
plain = ''.join([(chr((ord(c) - ord('A') - 4) % 26 + ord('A'))) for c in cipher])
print(plain)
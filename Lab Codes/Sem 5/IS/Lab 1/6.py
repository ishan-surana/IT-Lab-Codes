alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

# Brute-force to find the key pair (a, b)
for a in range(26):
    if a % 26 != 0:  # Check if 'a' is coprime with 26 (i.e., a has a modular inverse)
        for b in range(26):
            if (a * alphabet.index('A') + b) % 26 == alphabet.index('G') and (a * alphabet.index('B') + b) % 26 == alphabet.index('L'):
                print("Key pair found: a =", a, ", b =", b)
                inv_a = pow(a, -1, 26)
                message = "XPALASXYFGFUKPXUSOGEUTKCDGFXANMGNVS"
                decrypted = ''.join([alphabet[(inv_a * (alphabet.index(message[i]) - b)) % 26] for i in range(len(message))])
                print("Decrypted =", decrypted)
import numpy as np

message = "We live in an insecure world"
message = message.replace(" ", "").lower()  # Remove spaces and convert to uppercase
if len(message) % 2 != 0:
    message += "x"  # Pad the message with 'X' if its length is not even

# Key matrix K
key = np.array([3, 3, 2, 7]).reshape(-1, 2)

alphabet = "abcdefghijklmnopqrstuvwxyz"
message_vector = [ord(c) - ord("a") for c in message]

# Reshape the message vector into 2-row vectors for matrix multiplication
message_matrix = np.array(message_vector).reshape(-1, 2).T

# Perform matrix multiplication (mod 26)
ciphertext_matrix = np.dot(key, message_matrix) % 26

# Convert numbers back to letters
ciphertext = ""
for col in ciphertext_matrix.T:
    ciphertext += alphabet[col[0]]
    ciphertext += alphabet[col[1]]

print("Plaintext =", message, "\nCiphertext =", ciphertext)
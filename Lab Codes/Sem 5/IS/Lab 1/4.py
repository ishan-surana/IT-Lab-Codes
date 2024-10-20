message = "We live in an insecure world"
message = message.replace(" ", "").lower()  # Remove spaces and convert to uppercase
if len(message) % 2 != 0:
    message += "x"  # Pad the message with 'X' if its length is not even

# Key matrix K
# key = np.array([3, 3, 2, 7]).reshape(-1, 2)
key = [[3, 3], [2, 7]]

alphabet = "abcdefghijklmnopqrstuvwxyz"
message_vector = [ord(c) - ord("a") for c in message]

# Reshape the message vector into 2-row vectors for matrix multiplication
# message_matrix = np.array(message_vector).reshape(-1, 2).T
message_matrix = [message_vector[i:i+len(message_vector)//2] for i in range(2)]

# Perform matrix multiplication (mod 26)
# ciphertext_matrix = np.dot(key, message_matrix) % 26
# Shorter way to do matrix multiplication
# ciphertext_matrix = [[sum(a*b for a, b in zip(X_row, Y_col)) % 26 for Y_col in zip(*message_matrix)] for X_row in key]
ciphertext_matrix = [[0 for _ in range(len(message_matrix[0]))] for _ in range(len(key))]
for i in range(len(key)):
    for j in range(len(message_matrix[0])):
        for k in range(len(message_matrix)):
            ciphertext_matrix[i][j] += key[i][k] * message_matrix[k][j]
        ciphertext_matrix[i][j] %= 26

# Convert numbers back to letters
ciphertext = ""
# for col in ciphertext_matrix.T:
#     ciphertext += alphabet[col[0]]
#     ciphertext += alphabet[col[1]]
for i in range(len(ciphertext_matrix[0])):
    ciphertext += alphabet[ciphertext_matrix[0][i]] + alphabet[ciphertext_matrix[1][i]]

print("Plaintext =", message, "\nCiphertext =", ciphertext)
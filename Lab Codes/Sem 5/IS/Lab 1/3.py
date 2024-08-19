message = "The key is hidden under the door pad".replace(" ", "").lower().replace("j", "i")  # Remove spaces, uppercase, replace J with I
key = "guidance"
alphabet = "abcdefghiklmnopqrstuvwxyz"  # Note: 'J' is omitted
cipher_matrix = list(dict.fromkeys(key + alphabet))

# Prepare the message for encryption
prepared_message = "".join([message[i]+'x' if (i == len(message) - 1 or message[i] == message[i + 1]) else message[i] for i in range(len(message))])

# Encrypt the message
ciphertext = ""
for i in range(0, len(prepared_message), 2):
    row1, col1 = divmod(cipher_matrix.index(prepared_message[i]), 5)
    row2, col2 = divmod(cipher_matrix.index(prepared_message[i + 1]), 5)
    
    if row1 == row2:  # Same row, then we shift right
        ciphertext += cipher_matrix[row1 * 5 + (col1 + 1) % 5]
        ciphertext += cipher_matrix[row2 * 5 + (col2 + 1) % 5]
    elif col1 == col2:  # Same column, then we shift down
        ciphertext += cipher_matrix[((row1 + 1) % 5) * 5 + col1]
        ciphertext += cipher_matrix[((row2 + 1) % 5) * 5 + col2]
    else:  # Rectangle
        ciphertext += cipher_matrix[row1 * 5 + col2]
        ciphertext += cipher_matrix[row2 * 5 + col1]

# # Decrypt the message
# decrypted = ""
# for i in range(0, len(ciphertext), 2):
#     first = ciphertext[i]
#     second = ciphertext[i + 1]
    
#     row1, col1 = divmod(cipher_matrix.index(first), 5)
#     row2, col2 = divmod(cipher_matrix.index(second), 5)
    
#     if row1 == row2:  # Same row
#         decrypted += cipher_matrix[row1 * 5 + (col1 - 1) % 5]
#         decrypted += cipher_matrix[row2 * 5 + (col2 - 1) % 5]
#     elif col1 == col2:  # Same column
#         decrypted += cipher_matrix[((row1 - 1) % 5) * 5 + col1]
#         decrypted += cipher_matrix[((row2 - 1) % 5) * 5 + col2]
#     else:  # Rectangle
#         decrypted += cipher_matrix[row1 * 5 + col2]
#         decrypted += cipher_matrix[row2 * 5 + col1]

print("Cipher Matrix:")
for i in range(0, 25, 5):
    print(cipher_matrix[i:i + 5])

print("\nPlaintext =", message)
print("Prepared Message =", prepared_message)
print("Ciphertext =", ciphertext)
# print("Decrypted =", decrypted)
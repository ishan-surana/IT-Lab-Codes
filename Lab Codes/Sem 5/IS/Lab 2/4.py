from Crypto.Cipher import DES3
from Crypto.Util.Padding import pad, unpad

message = b"Classified Text"
key = "1234567890ABCDEF1234567890ABCDEF1234567890ABCDEF"

cipher = DES3.new(key[:24], DES3.MODE_ECB)  # Truncate key to 24 bytes
padded_message = pad(message, DES3.block_size)

ciphertext = cipher.encrypt(padded_message)
print("Ciphertext:", bytes.hex(ciphertext))

decrypted_message = unpad(cipher.decrypt(ciphertext), DES3.block_size)
print("Decrypted message:", decrypted_message.decode())
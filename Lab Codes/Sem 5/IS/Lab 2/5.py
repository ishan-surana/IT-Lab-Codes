from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad

message = b"Top Secret Data"
key = b"FEDCBA9876543210FEDCBA9876543210"

cipher = AES.new(key[:24], AES.MODE_ECB)
padded_message = pad(message, AES.block_size)

ciphertext = cipher.encrypt(padded_message)
print("Ciphertext:", bytes.hex(ciphertext))

decrypted_message = unpad(cipher.decrypt(ciphertext), AES.block_size)
print("Decrypted message:", decrypted_message.decode())
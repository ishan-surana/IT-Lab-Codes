from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad
from binascii import hexlify

key = b"A1B2C3D4"
message = b"Confidential Data"

cipher = DES.new(key, DES.MODE_ECB)
message = pad(message, DES.block_size)

ciphertext = cipher.encrypt(message)
print("Ciphertext:", hexlify(ciphertext))

decrypted_message = unpad(cipher.decrypt(ciphertext), DES.block_size)
print("Decrypted message:", decrypted_message.decode())
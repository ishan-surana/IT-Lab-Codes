from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from base64 import b64encode

key = bytes.fromhex("0123456789ABCDEF"*2)
message = b"Sensitive Information"
cipher = AES.new(key, AES.MODE_ECB)

padded_message = pad(message, AES.block_size)
ciphertext = cipher.encrypt(padded_message)
print("Ciphertext (hex):", b64encode(ciphertext).decode())

decrypted_message = unpad(cipher.decrypt(ciphertext), AES.block_size)
print("Decrypted message:", decrypted_message.decode())
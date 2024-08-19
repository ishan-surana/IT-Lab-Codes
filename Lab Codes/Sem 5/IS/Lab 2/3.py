from Crypto.Cipher import DES, AES
from Crypto.Util.Padding import pad, unpad
import time

message = b"Performance Testing of Encryption Algorithms"
padded_message = pad(message, DES.block_size)

des_key = b"8bytekey"  # DES key must be 8 bytes long
des_cipher = DES.new(des_key, DES.MODE_ECB)

aes_key = b"0123456789ABCDEF"*2  # 32 bytes for AES-256
aes_cipher = AES.new(aes_key, AES.MODE_ECB)

start_time = time.perf_counter()
des_ciphertext = des_cipher.encrypt(padded_message)
des_encryption_time = time.perf_counter() - start_time

start_time = time.perf_counter()
des_decrypted = unpad(des_cipher.decrypt(des_ciphertext), DES.block_size)
des_decryption_time = time.perf_counter() - start_time

start_time = time.perf_counter()
aes_ciphertext = aes_cipher.encrypt(padded_message)
aes_encryption_time = time.perf_counter() - start_time

start_time = time.perf_counter()
aes_decrypted = unpad(aes_cipher.decrypt(aes_ciphertext), AES.block_size)
aes_decryption_time = time.perf_counter() - start_time

print("DES Encryption Time: {:.10f} seconds".format(des_encryption_time))
print("DES Decryption Time: {:.10f} seconds".format(des_decryption_time))
print("AES-256 Encryption Time: {:.10f} seconds".format(aes_encryption_time))
print("AES-256 Decryption Time: {:.10f} seconds".format(aes_decryption_time))
from Crypto.PublicKey import RSA, ECC
from Crypto.Cipher import AES, PKCS1_OAEP
from Crypto.Signature import DSS
from Crypto.Hash import SHA256
from Crypto.Random import get_random_bytes
import time

# RSA Key Generation
rsa_start_time = time.time()
rsa_key = RSA.generate(2048)
rsa_end_time = time.time()
rsa_key_gen_time = rsa_end_time - rsa_start_time
print(f"RSA Key Generation Time: {rsa_key_gen_time:.10f} seconds")

# ECC Key Generation
ecc_start_time = time.time()
ecc_key = ECC.generate(curve='P-256')
ecc_end_time = time.time()
ecc_key_gen_time = ecc_end_time - ecc_start_time
print(f"ECC Key Generation Time: {ecc_key_gen_time:.10f} seconds")

# Function to perform RSA-based hybrid encryption and decryption
def rsa_hybrid_encrypt(file_data, rsa_key):
    # Step 1: Generate AES key and encrypt file data
    aes_key = get_random_bytes(32)  # AES-256 key
    aes_cipher = AES.new(aes_key, AES.MODE_EAX)
    ciphertext, tag = aes_cipher.encrypt_and_digest(file_data)

    # Step 2: Encrypt AES key with RSA
    rsa_cipher = PKCS1_OAEP.new(rsa_key.publickey())
    encrypted_aes_key = rsa_cipher.encrypt(aes_key)

    return encrypted_aes_key, aes_cipher.nonce, ciphertext, tag

def rsa_hybrid_decrypt(encrypted_aes_key, nonce, ciphertext, tag, rsa_key):
    # Step 1: Decrypt AES key with RSA
    rsa_cipher = PKCS1_OAEP.new(rsa_key)
    aes_key = rsa_cipher.decrypt(encrypted_aes_key)

    # Step 2: Decrypt file data with AES
    aes_cipher = AES.new(aes_key, AES.MODE_EAX, nonce=nonce)
    decrypted_data = aes_cipher.decrypt_and_verify(ciphertext, tag)

    return decrypted_data

# Function to perform ECC-based hybrid encryption
def ecc_hybrid_encrypt(file_data, ecc_key):
    # Step 1: Generate AES key and encrypt file data
    aes_key = get_random_bytes(32)  # AES-256 key
    aes_cipher = AES.new(aes_key, AES.MODE_EAX)
    ciphertext, tag = aes_cipher.encrypt_and_digest(file_data)

    # Step 2: Sign the AES key with ECC (Note: ECC is typically used with ECDH for key exchange)
    h = SHA256.new(aes_key)
    signer = DSS.new(ecc_key, 'fips-186-3')
    signature = signer.sign(h)

    return signature, aes_cipher.nonce, ciphertext, tag

# ECC does not directly support decryption as RSA does
# Typically, ECDH would be used to derive a shared key, which is not shown here
# Here, ECC is used to sign the AES key instead of directly encrypting it

# Generate test file data
file_data_1mb = get_random_bytes(1024 * 1024)  # 1 MB file
file_data_10mb = get_random_bytes(1024 * 1024 * 10)  # 10 MB file

# RSA Encryption/Decryption for 1MB file
rsa_enc_start = time.time()
enc_aes_key, nonce, ciphertext, tag = rsa_hybrid_encrypt(file_data_1mb, rsa_key)
rsa_enc_time_1mb = time.time() - rsa_enc_start
rsa_decrypt_start = time.time()
rsa_decrypted_data = rsa_hybrid_decrypt(enc_aes_key, nonce, ciphertext, tag, rsa_key)
rsa_dec_time_1mb = time.time() - rsa_decrypt_start

# RSA Encryption/Decryption for 10MB file
rsa_enc_start = time.time()
enc_aes_key, nonce, ciphertext, tag = rsa_hybrid_encrypt(file_data_10mb, rsa_key)
rsa_enc_time_10mb = time.time() - rsa_enc_start
rsa_decrypt_start = time.time()
rsa_decrypted_data = rsa_hybrid_decrypt(enc_aes_key, nonce, ciphertext, tag, rsa_key)
rsa_dec_time_10mb = time.time() - rsa_decrypt_start

# ECC Encryption for 1MB file (Note: ECC decryption is not implemented here due to pycryptodome limitations)
ecc_enc_start = time.time()
ecc_signature, nonce, ecc_ciphertext, tag = ecc_hybrid_encrypt(file_data_1mb, ecc_key)
ecc_enc_end = time.time()

ecc_enc_time_1mb = ecc_enc_end - ecc_enc_start

# ECC Encryption for 10MB file
ecc_enc_start = time.time()
ecc_signature, nonce, ecc_ciphertext, tag = ecc_hybrid_encrypt(file_data_10mb, ecc_key)
ecc_enc_end = time.time()

ecc_enc_time_10mb = ecc_enc_end - ecc_enc_start

# Print performance results
print(f"RSA Encryption Time (1MB): {rsa_enc_time_1mb:.10f} seconds")
print(f"RSA Decryption Time (1MB): {rsa_dec_time_1mb:.10f} seconds")
print(f"RSA Encryption Time (10MB): {rsa_enc_time_10mb:.10f} seconds")
print(f"RSA Decryption Time (10MB): {rsa_dec_time_10mb:.10f} seconds")

print(f"ECC Encryption Time (1MB): {ecc_enc_time_1mb:.10f} seconds")
print(f"ECC Encryption Time (10MB): {ecc_enc_time_10mb:.10f} seconds")
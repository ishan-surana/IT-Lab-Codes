from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad
import base64

def encrypt_des(key: bytes, data: str) -> str:
    cipher = DES.new(key, DES.MODE_ECB)
    padded_data = pad(data.encode(), DES.block_size)
    encrypted_data = cipher.encrypt(padded_data)
    return base64.b64encode(encrypted_data).decode()

def decrypt_des(key: bytes, encrypted_data: str) -> str:
    cipher = DES.new(key, DES.MODE_ECB)
    encrypted_data = base64.b64decode(encrypted_data)
    padded_data = cipher.decrypt(encrypted_data)
    return unpad(padded_data, DES.block_size).decode()

if __name__ == "__main__":
    key = b'A1B2C3D4'
    plaintext = "Confidential Data"

    encrypted = encrypt_des(key, plaintext)
    print(f"Encrypted: {encrypted}")

    decrypted = decrypt_des(key, encrypted)
    print(f"Decrypted: {decrypted}")
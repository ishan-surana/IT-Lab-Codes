# ECC code using PyCryptodome
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives.asymmetric import ec
from cryptosystems import AES

# Generate ECC private key
private_key = ec.generate_private_key(ec.SECP256R1(), default_backend())
public_key = private_key.public_key()

# Function to encrypt a message
def encrypt(message, public_key):
    # Generate ephemeral private key
    ephemeral_private_key = ec.generate_private_key(ec.SECP256R1(), default_backend())
    ephemeral_public_key = ephemeral_private_key.public_key()

    # Derive the shared secret
    shared_secret = ephemeral_private_key.exchange(ec.ECDH(), public_key)

    # Encrypt the message using the shared secret
    encrypted_message = bytearray()
    num_keys = len(shared_secret) // 16
    for i in range(num_keys):
        current_key = shared_secret[i * 16: (i + 1) * 16]
        aes = AES(current_key)
        encrypted_message += aes.encrypt(message[i * 16: (i + 1) * 16])
    
    return ephemeral_public_key, encrypted_message

# Function to decrypt a message
def decrypt(ephemeral_public_key, encrypted_message, private_key):
    # Derive the shared secret
    shared_secret = private_key.exchange(ec.ECDH(), ephemeral_public_key)

    # Decrypt the message
    decrypted_message = ""
    num_keys = len(shared_secret) // 16
    for i in range(num_keys):
        current_key = shared_secret[i * 16: (i + 1) * 16]
        # extract the encrypted message for the current key from the encrypted message which is a bytearray
        current_encrypted_message = encrypted_message[i * 16: (i + 1) * 16]
        aes = AES(current_key)
        decrypted_message += aes.decrypt(current_encrypted_message)
    
    return decrypted_message

# Example usage
message = "Hello, ECC!"
ephemeral_public_key, encrypted_message = encrypt(message, public_key)
print(f"Encrypted: {encrypted_message}")

decrypted_message = decrypt(ephemeral_public_key, encrypted_message, private_key)
print(f"Decrypted: {decrypted_message}")


# from cryptosystems import ECC
# ecc = ECC()
# print("Plaintext:", int.from_bytes("Hello, World!".encode(), 'big'))
# print("Cipher Text:", ecc.encrypt("Hello, World!"))
# print("Decrypted Text:", ecc.decrypt(ecc.encrypt("Hello, World!"), 'int'))

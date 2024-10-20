from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad
import hashlib

def encrypt_data(key, data):
    cipher = AES.new(key, AES.MODE_CBC)
    iv = cipher.iv
    ciphertext = cipher.encrypt(pad(data, AES.block_size))
    return iv, ciphertext

def decrypt_data(key, iv, ciphertext):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    plaintext = unpad(cipher.decrypt(ciphertext), AES.block_size)
    return plaintext.decode()

def create_index(documents, key):
    index = {}
    for doc_id, doc in documents.items():
        for word in doc.split():
            word_hash = hashlib.sha256(word.encode()).digest()
            if word_hash not in index:
                index[word_hash] = []
            index[word_hash].append(doc_id)

    # Encrypt the index
    encrypted_index = {}
    for word_hash, doc_ids in index.items():
        encrypted_index[encrypt_data(key, word_hash)[1]] = [
            encrypt_data(key, doc_id.encode())[1] for doc_id in doc_ids
        ]
    return encrypted_index

def search(encrypted_index, query, key):
    query_hash = hashlib.sha256(query.encode()).digest()
    encrypted_query_hash = encrypt_data(key, query_hash)[1]
    
    if encrypted_query_hash in encrypted_index:
        return [
            decrypt_data(key, *encrypt_data(key, doc_id.encode())) for doc_id in encrypted_index[encrypted_query_hash]
        ]
    else:
        return []

# Example usage
documents = {
    "doc1": "this is a document with some words",
    "doc2": "another document with different words",
    "doc3": "yet another document with some common words"
}

key = get_random_bytes(16)
encrypted_index = create_index(documents, key)
query = "document"
results = search(encrypted_index, query, key)
print(results)

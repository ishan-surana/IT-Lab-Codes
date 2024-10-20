from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from collections import defaultdict
from Crypto.Random import get_random_bytes

documents = {
    1: "The quick brown fox jumps over the lazy dog.",
    2: "A journey of a thousand miles begins with a single step.",
    3: "To be or not to be, that is the question.",
    4: "All that glitters is not gold.",
    5: "In the end, we will remember not the words of our enemies, but the silence of our friends.",
    6: "The only thing we have to fear is fear itself.",
    7: "To infinity and beyond.",
    8: "That's one small step for a man, one giant leap for mankind.",
    9: "The greatest glory in living lies not in never falling, but in rising every time we fall.",
    10: "Life is what happens when you're busy making other plans."
}

def encrypt_aes(key, plaintext):
    cipher = AES.new(key, AES.MODE_CBC)
    ct_bytes = cipher.encrypt(pad(plaintext.encode(), AES.block_size))
    return cipher.iv, ct_bytes

def decrypt_aes(key, iv, ciphertext):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    pt = unpad(cipher.decrypt(ciphertext), AES.block_size)
    return pt.decode()

def create_inverted_index(docs):
    index = defaultdict(list)
    for doc_id, text in docs.items():
        for word in text.lower().split():
            index[word].append(doc_id)
    return index

def search(query, encrypted_index, key):
    results = []
    for word in query.lower().split():
        if word in encrypted_index:
            decrypted_ids = decrypt_aes(key, encrypted_index[word][0], encrypted_index[word][1])
            results.extend(map(int, decrypted_ids[1:-1].split(", ")))
    return set(results)

inverted_index = create_inverted_index(documents)

key = get_random_bytes(16)
encrypted_index = {word: encrypt_aes(key, str(doc_ids)) for word, doc_ids in inverted_index.items()}

search_query = "To be"
doc_ids = search(search_query, encrypted_index, key)
for doc_id in doc_ids:
    print(f"Document {doc_id}: {documents[doc_id]}")

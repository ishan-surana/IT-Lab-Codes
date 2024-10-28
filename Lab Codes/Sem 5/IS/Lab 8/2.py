import random
import math
from collections import defaultdict
from Crypto.Util.number import getPrime

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

def generate_keypair(bit_length=512):
    p = getPrime(bit_length)
    q = getPrime(bit_length)
    n = p * q
    g = n + 1
    lambda_ = (p - 1) * (q - 1) // math.gcd(p - 1, q - 1)
    return (n, g, lambda_), (p, q)

def encrypt(public_key, plaintext):
    n, g, lambda_ = public_key
    r = random.randint(1, n - 1)
    c = (pow(g, plaintext, n**2) * pow(r, n, n**2)) % n**2
    return c

def decrypt(public_key, ciphertext):
    n, _, lambda_ = public_key
    u = (pow(ciphertext, lambda_, n**2) - 1) // n
    plaintext = (u * pow(lambda_, -1, n)) % n
    return plaintext

def create_inverted_index(docs):
    index = defaultdict(list)
    for doc_id, text in docs.items():
        for word in text.lower().split():
            index[word].append(doc_id)
    return index

def search(query, encrypted_index, public_key):
    results = []
    for word in query.lower().split():
        if word in encrypted_index:
            encrypted_doc_ids = encrypted_index[word]
            results.extend([decrypt(public_key, doc_id) for doc_id in encrypted_doc_ids])
    return set(results)

inverted_index = create_inverted_index(documents)
public_key, private_key = generate_keypair()
encrypted_index = {word: [encrypt(public_key, doc_id) for doc_id in doc_ids] for word, doc_ids in inverted_index.items()}

search_query = input("Enter search query (for eg: 'to be'): ")
doc_ids = search(search_query, encrypted_index, public_key)
for doc_id in doc_ids:
    print(f"Document {doc_id}: {documents[doc_id]}")

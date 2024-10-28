import sys
from itertools import cycle
message = "the house is being sold tonight"
alphabet = "abcdefghijklmnopqrstuvwxyz"
cipher = 'd'
while cipher not in ['a', 'b', 'c']:
    cipher = input("a) Vignere with key = 'dollars'\nb) Autokey with key = 7\nc) Exit\nChoice:- ")
    if cipher not in ['a', 'b', 'c']:
        print("Invalid choice!!!")
if cipher=='c':
    sys.exit()
print("\nPlaintext =", message)
if cipher=='a':
    ciphertext = ""
    key = cycle("dollars")
    for i in range(len(message)):
        if message[i]==" ":
            ciphertext+=" "
        else:
            ciphertext += alphabet[(alphabet.find(message[i]) + alphabet.find(next(key)))%26]
    decrypted = ""
    key = cycle("dollars")
    for i in range(len(message)):
        if message[i]==" ":
            decrypted+=" "
        else:
            decrypted += alphabet[(alphabet.find(ciphertext[i]) - alphabet.find(next(key)))%26]
elif cipher=='b':
    ciphertext = ""
    key = alphabet[(7-1)] + message[:-1]
    print(key)
    for i in range(len(message)):
        if message[i]==" ":
            ciphertext+=" "
        else:
            ciphertext += alphabet[(alphabet.find(message[i]) + alphabet.find(key[i]))%26]
    decrypted = ""
    for i in range(len(message)):
        if message[i]==" ":
            decrypted+=" "
        else:
            decrypted += alphabet[(alphabet.find(ciphertext[i]) - alphabet.find(key[i]))%26]

print("Ciphertext =", ciphertext)
print("Decrypted =", decrypted)
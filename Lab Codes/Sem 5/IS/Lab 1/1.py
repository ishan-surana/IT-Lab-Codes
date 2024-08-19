import sys
message = "I am learning information security"
cipher = "e"
while cipher not in ['a', 'b', 'c', 'd']:
    cipher = input("a) Addtive with key = 20\nb) Multiplicative with key = 15\nc) Affine with key = (15, 20)\nd) Exit\nChoice:- ")
    if cipher not in ['a', 'b', 'c', 'd']:
        print("Invalid choice!!!")
if cipher=='d':
    sys.exit()
print("\nPlaintext =", message)
alphabet = "abcdefghijklmnopqrstuvwxyz"
# ciphertext = message[:1] + message[1:]
if cipher=='a':
    ciphertext = ""
    for i in range(len(message)):
        mid = alphabet[(alphabet.find(message[i].lower())+20)%26]
        if message[i]==message[i].upper():
            mid = mid.upper()
        if message[i]==" ":
            mid = " "
        ciphertext+=mid        
        # if ciphertext[i] == " ":
        #     ciphertext = ciphertext[:i] + " " + ciphertext[i+1:]
        # else:
        #     mid = alphabet[(alphabet.find(ciphertext[i].lower())+20)%26]
        #     if message[i]==message[i].upper():
        #         mid = mid.upper()
        #     ciphertext = ciphertext[:i] + mid + ciphertext[i+1:]
    decrypted = ""
    for i in range(len(message)):
        mid = alphabet[(alphabet.find(ciphertext[i].lower())-20)%26]
        if message[i]==message[i].upper():
            mid = mid.upper()
        if message[i]==" ":
            mid = " "
        decrypted+=mid
elif cipher=='b':
    ciphertext = ""
    for i in range(len(message)):
        mid = alphabet[(alphabet.find(message[i].lower())*15)%26]
        if message[i]==message[i].upper():
            mid = mid.upper()
        if message[i]==" ":
            mid = " "
        ciphertext+=mid 
    decrypted = ""
    inv_key = [i for i in range(26) if (i*15)%26==1][0]
    for i in range(len(message)):
        mid = alphabet[(alphabet.find(ciphertext[i].lower())*inv_key)%26]
        if message[i]==message[i].upper():
            mid = mid.upper()
        if message[i]==" ":
            mid = " "
        decrypted+=mid
elif cipher=='c':
    ciphertext = ""
    for i in range(len(message)):
        mid = alphabet[(alphabet.find(message[i].lower())*15 + 20)%26]
        if message[i]==message[i].upper():
            mid = mid.upper()
        if message[i]==" ":
            mid = " "
        ciphertext+=mid 
    decrypted = ""
    inv_key = [i for i in range(26) if (i*15)%26==1][0]
    for i in range(len(message)):
        mid = alphabet[((alphabet.find(ciphertext[i].lower())-20)*inv_key)%26]
        if message[i]==message[i].upper():
            mid = mid.upper()
        if message[i]==" ":
            mid = " "
        decrypted+=mid
    
print("Ciphertext =", ciphertext)
print("Decrypted =", decrypted)
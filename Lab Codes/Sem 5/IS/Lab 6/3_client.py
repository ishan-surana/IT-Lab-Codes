from Crypto.Util.number import bytes_to_long
import socket
import pickle

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 65432))

data = pickle.loads(client_socket.recv(4096))
n, e, message, signature = data['n'], data['e'], data['message'], data['signature']
m = bytes_to_long(message)

try:
    decrypted_message = pow(signature, e, n)
    if decrypted_message == m:
        print("The signature is valid.")
    else:
        print("The signature is invalid.")
except Exception as e:
    print(f"Verification failed: {e}")

client_socket.close()

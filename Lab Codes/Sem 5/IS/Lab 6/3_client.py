from Crypto.Util.number import bytes_to_long, long_to_bytes
import socket
import pickle

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect(('localhost', 65432))

data = pickle.loads(client_socket.recv(4096))
n, e, m, signature = data['n'], data['e'], data['m'], data['signature']
message = long_to_bytes(m)

try:
    decrypted_message = pow(signature, e, n)
    if decrypted_message == bytes_to_long(message):
        print("The signature is valid. Message: '" + message.decode() + "'")
    else:
        print("The signature is invalid.")
except Exception as e:
    print(f"Verification failed: {e}")

client_socket.close()

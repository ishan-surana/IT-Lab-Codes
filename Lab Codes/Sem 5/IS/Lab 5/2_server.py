import socket
import hashlib

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 12345)
server_socket.bind(server_address)
server_socket.listen(1)
num_connections = 0
print('Waiting for a connection...')
while True:
    connection, client_address = server_socket.accept()
    print('Connection from', client_address)
    num_connections+=1
    print(num_connections)
    data = connection.recv(1024)
    if data == b'exit' or not data or num_connections == 3:
        break
    data_hash = hashlib.sha256(data).hexdigest()
    connection.sendall(data_hash.encode())
from Crypto.Util.number import getPrime, inverse
import base64
import hashlib

class RabinKeyManagement:
    def __init__(self, key_size=1024):
        self.key_size = key_size
        self.keys = {}

    def generate_key_pair(self):
        p = getPrime(self.key_size // 2)
        q = getPrime(self.key_size // 2)
        n = p * q
        public_key = (n,)
        private_key = (p, q)
        return public_key, private_key

    def encrypt(self, public_key, plaintext):
        n = public_key[0]
        m = int.from_bytes(plaintext.encode(), byteorder='big')
        ciphertext = pow(m, 2, n)
        pt_hash = hashlib.sha256(plaintext.encode()).digest()
        return (base64.b64encode(ciphertext.to_bytes((ciphertext.bit_length() + 7) // 8, byteorder='big')).decode('utf-8'), base64.b64encode(pt_hash).decode('utf-8'))

    def decrypt(self, private_key, ciphertext, pt_hash):
        p, q = private_key
        c = int.from_bytes(base64.b64decode(ciphertext), byteorder='big')

        root_p1 = pow(c, (p + 1) // 4, p)
        root_p2 = (-root_p1) % p
        root_q1 = pow(c, (q + 1) // 4, q)
        root_q2 = (-root_q1) % q
        
        def chinese_remainder_theorem(a1, a2, n1, n2):
            m1 = inverse(n1, n2)
            return (a1 + (a2 - a1) * m1 * n1) % (n1 * n2)

        root_1 = chinese_remainder_theorem(root_p1, root_q1, p, q)
        root_2 = chinese_remainder_theorem(root_p1, root_q2, p, q)
        root_3 = chinese_remainder_theorem(root_p2, root_q1, p, q)
        root_4 = chinese_remainder_theorem(root_p2, root_q2, p, q)

        plaintexts = [root_1, root_2, root_3, root_4]
        for plaintext in plaintexts:
            if hashlib.sha256(plaintext.to_bytes((plaintext.bit_length() + 7) // 8, byteorder='big')).digest() == base64.b64decode(pt_hash):
                return plaintext.to_bytes((plaintext.bit_length() + 7) // 8, byteorder='big').decode('utf-8')

    def store_key_pair(self, facility_id):
        public_key, private_key = self.generate_key_pair()
        self.keys[facility_id] = {'public_key': public_key, 'private_key': private_key}
        print(f"Keys stored for {facility_id}")

    def get_key_pair(self, facility_id):
        key_pair = self.keys.get(facility_id, None)
        if key_pair:
            return key_pair
        else:
            print("Keys not found.")
            return None

    def revoke_key_pair(self, facility_id):
        if facility_id in self.keys:
            del self.keys[facility_id]
            print(f"Keys revoked for {facility_id}")

    def renew_keys(self):
        for facility_id in list(self.keys.keys()):
            self.revoke_key_pair(facility_id)
            self.store_key_pair(facility_id)
        print("All keys renewed.")

def menu():
    rkm = RabinKeyManagement()
    print("Key Management System")
    print("1. Generate and Store Key Pair")
    print("2. Retrieve Key Pair")
    print("3. Revoke Key Pair")
    print("4. Renew All Keys")
    print("5. Encrypt and Decrypt Message")
    print("6. Exit")
    while True:
        choice = input("\nChoose an option: ")
        if choice == '1':
            facility_id = input("Enter facility ID: ")
            rkm.store_key_pair(facility_id)
        elif choice == '2':
            facility_id = input("Enter facility ID: ")
            key_pair = rkm.get_key_pair(facility_id)
            if key_pair:
                print(f"Public Key: {key_pair['public_key']}")
                print(f"Private Key: {key_pair['private_key']}")
        elif choice == '3':
            facility_id = input("Enter facility ID: ")
            rkm.revoke_key_pair(facility_id)
        elif choice == '4':
            rkm.renew_keys()
        elif choice == '5':
            facility_id = input("Enter facility ID: ")
            key_pair = rkm.get_key_pair(facility_id)
            if key_pair:
                message = input("Enter message to encrypt: ")
                encrypted_message, message_hash = rkm.encrypt(key_pair['public_key'], message)
                print(f"Encrypted message: {encrypted_message}")
                decrypted_message = rkm.decrypt(key_pair['private_key'], encrypted_message, message_hash)
                print(f"Decrypted message: {decrypted_message}")
        elif choice == '6':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    menu()

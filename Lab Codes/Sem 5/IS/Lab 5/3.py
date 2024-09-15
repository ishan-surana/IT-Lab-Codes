import hashlib
import time
import random
import string

def generate_random_strings(num_strings, length=10):
    return [''.join(random.choices(string.ascii_letters + string.digits, k=length)) for _ in range(num_strings)]

def compute_hashes(data, hash_algorithm):
    hash_func = getattr(hashlib, hash_algorithm)
    return [hash_func(item.encode()).hexdigest() for item in data]

def measure_time_and_collisions(data, hash_algorithm):
    start_time = time.perf_counter()
    hashes = compute_hashes(data, hash_algorithm)
    computation_time = time.perf_counter() - start_time
    collisions = 100 - len(set(hashes))
    return computation_time, collisions

data = generate_random_strings(100, 10)
algorithms = ['md5', 'sha1', 'sha256']
for algorithm in algorithms:
    print(f"Testing {algorithm.upper()}...")
    computation_time, collisions = measure_time_and_collisions(data, algorithm)
    print(f"Computation Time: {computation_time:.10f} seconds")
    print(f"Number of Collisions: {collisions}")
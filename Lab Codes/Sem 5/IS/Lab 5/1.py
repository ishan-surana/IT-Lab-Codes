def hash_function(s):
    hash_value = 5381
    current_or = 17 # 5+3+8+1 = 17
    for i in range(2):
        for char in s:
            hash_value = (hash_value * 33) + ord(char)
            hash_value = (hash_value | current_or) << 4
            current_or = ord(char)
    hash_value = hash_value & 0xFFFFFFFF
    return hash_value

input_string = "hello"
print(f"Hash value: {hash_function(input_string)}")
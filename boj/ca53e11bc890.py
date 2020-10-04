import hashlib
print(hashlib.new('ripemd160', input().encode()).hexdigest())

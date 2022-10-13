#!/usr/bin/python3

flag = input('Enter flag: ').encode()

state = 0x42

output = b''

for b in flag:
    state ^= b
    output += bytes([state])

print(output.hex())

# 0045024b054b0e5c27540030401f72437603701977104f1727752a1f7e1b7f4d30

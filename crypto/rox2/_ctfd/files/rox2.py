#!/usr/bin/python3

flag = input('Enter flag: ').encode()

prev = flag[-1]

output = b''

for b in flag:
    output += bytes([b ^ prev])
    prev = b

print(output.hex())

# 3f07020e07000b17290f3c79046a6e421d1a2b38021100457f09186b5a17263d51470047412d6a0400064a

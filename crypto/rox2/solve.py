#!/usr/bin/python3

encoded = bytes.fromhex(
    '3f07020e07000b17290f3c79046a6e421d1a2b38021100457f09186b5a17263d51470047412d6a0400064a')

prev = ord('}')

output = b''

for b in encoded:
    curr = b ^ prev
    output += bytes([curr])
    prev = curr

print(output.decode())

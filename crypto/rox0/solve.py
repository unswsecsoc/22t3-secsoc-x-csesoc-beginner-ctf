#!/usr/bin/python3

encoded = bytes.fromhex(
    '0007050b0c0c0710393a72301d73771d21722f2f2d2c1d730c1d01303b3236721d737b2027207a763f')

output = b''

for b in encoded:
    output += bytes([0x42 ^ b])

print(output.decode())

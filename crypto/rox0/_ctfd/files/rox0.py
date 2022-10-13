#!/usr/bin/python3

flag = input('Enter flag: ').encode()

key = 0x42

output = b''

for b in flag:
    output += bytes([b ^ key])

print(output.hex())

# 0007050b0c0c0710393a72301d73771d21722f2f2d2c1d730c1d01303b3236721d737b2027207a763f

#!/usr/bin/python3

flag = input('Enter flag: ').encode()

output = b''

for i, b in enumerate(flag):
    temp = flag[(i + 8) % len(flag)]
    output += bytes([b ^ temp])

print(output.hex())

# 3974183d267f2b3924466c2b1b595e1e33136c35065d442a0b5529592a402400534529473744650044446e1a1c6e516747025013361a2371797c242f

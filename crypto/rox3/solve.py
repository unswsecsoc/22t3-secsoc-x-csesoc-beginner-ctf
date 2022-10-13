#!/usr/bin/python3

encoded = bytes.fromhex(
    '3974183d267f2b3924466c2b1b595e1e33136c35065d442a0b5529592a402400534529473744650044446e1a1c6e516747025013361a2371797c242f')

known = b'BEGINNER'

output = [0 for i in encoded]

for k_i, k in enumerate(known):
    prev = k
    for i in range(k_i, len(encoded), 8):
        next_val = prev ^ encoded[i]
        output[(i + 8) % len(output)] = next_val
        prev = next_val

print(bytes(output).decode())

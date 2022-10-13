#!/usr/bin/python3

encoded = bytes.fromhex(
    '0045024b054b0e5c27540030401f72437603701977104f1727752a1f7e1b7f4d30')

output = b''

for b in encoded:
    before_state = 0x42
    for x in output:
        before_state ^= x
    output += bytes([before_state ^ b])

print(output.decode())

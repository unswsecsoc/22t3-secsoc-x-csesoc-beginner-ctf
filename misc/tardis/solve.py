#!/bin/python

import pwn
import string
import time

# hide the notifications about starting new processes
pwn.context.log_level = 'error'

flag = "BEGINNER{"
flag_time = len(flag)
print("Initial flag is " + flag + " with length " + str(flag_time))

while True:
    p = pwn.process("./_ctfd/files/flag_checker")
    for c in string.ascii_lowercase + string.digits + '-' + '_' + '}':
        p.recvuntil("Enter a flag:")

        start = time.time()
        p.sendline(flag + c)
        p.recvline()
        now = time.time()
        elapsed = int((now - start) * 100)

        if elapsed > flag_time:
            flag = flag + c
            flag_time = elapsed
            print("Current flag is " + flag + " with length " + str(flag_time))

            if c == '}':
                exit(0)
            break

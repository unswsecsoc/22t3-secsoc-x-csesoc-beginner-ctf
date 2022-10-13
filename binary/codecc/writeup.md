# codecc

## Authors
- @ItsIronicIInsist

## Category
- Binary Exploit

## Description
Feel like you need to decompress? And by you, I mean a stream of encoded bytes. Well have I got the program for you!

## Difficulty
- Hard

## Points
150

## Hints
1. What's the best (de)compression ratio you can get?

## Files
- [codecc.c](./_ctfd/files/codecc.c) : source code
- [codecc](./_ctfd/files/codecc) : compiled program, with no protections

## Solution
<details>
<summary>Spoiler</summary>

### Idea
Decode is a decompression algorithm (PACKBITS, to the best of my ability to replicate it). The buffer for decoded output isnt dynamically reallocated when the output gets too large, so make it decompress to overflow. 
Shellcode, as ASLR is disabled, and stack is executable

### Walkthrough
1. Input will need to be encoded properly, This is just a note.
2. Put some padding in - input pad should be small, but it should decompress a LARGE amount. We want to overflow the buffer into the stack variables/return address
2b. I recommend the byte used to be 0xcc - this is a no-operation. This will be useful later
3. Addend some shellcode to the buffer. Then, grab decoded's address (w/out ASLR its always the same)
5. Now, with pad, we start to overwrite local stack vars. Most need to be preserved, so find their values before overwriting and replicate them (via a debugger)
6. Do this until you reach the return-address, upon which point to your shellcode.
6b. Note - with the NOP-bytes, you can point to anywhere in the region from the start of the buffer to the shellcode and still get shell. This helps for any minute changes in environment from local to remote
6c. Note - one local variable stored is the address of the decoded buffer. To make your exploit-code smaller, you could overwrite this such that the next write directly overwrites the return address. This couldve also bypassed a stack canary, had they been enabled.


### Flag
`BEGINNER{im4g1ne_n0t_dyn4mica11y_r3a11ocat1ng}`
</details>

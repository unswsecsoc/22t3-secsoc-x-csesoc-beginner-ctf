# One-bit

## Authors
- @ItsIronicIInsist

## Category
- Binary Exploit

## Description
Look, if you had one bit or one bit

To seize binary you ever wanted in one bit

Would you pwn it, or just let it sigsegv (-11)?

## Difficulty
- Medium

## Points
100

## Hints
1. Do you really only have one chance?

## Files
- [one-bit.c](./_ctfd/files/one-bit.c) : source code
- [one-bit](./_ctfd/files/one-bit) : compiled program

## Solution
<details>
<summary>Spoiler</summary>

### Idea
Get a 'single' bit-flip at any arbitrary location. Flip loop var's most-signifigant bit to make it negative, then use unlimited bitflips to overwrite metadata of your choice.

### Walkthrough
1. Enjoy your info leaks.
2. Figure out offset between stack leak and loop var
3. Overwrite loop-var's most-signifigant bit, making it a large negative numbers
4. Figure offset of saved return address and stack leak. Get any required ROP gadget addresses
5. Overwrite return-address and past it with ROP chain. I went (pop rdi -> addr of "/bin/sh" -> system)


### Flag
`BEGINNER{4lw4ys_h1t_7h3_l00p_var}`
</details>

# Echo

## Authors
- @ItsIronicIInsist

## Category
- Binary Exploit

## Description
Repeat after me: Binary exploitation goes hard.

## Difficulty
- Easy

## Points
50

## Hints
1. gets' manpage ought to be helpful

## Files
- [echo.c](./_ctfd/files/echo.c) : source code
- [echo](./_ctfd/files/echo) : compiled program, with no protections

## Solution
<details>
<summary>Spoiler</summary>

### Idea
gets function is notoriously insecure. Beginner-difficulty buffer overflow, win function included.

### Walkthrough
1. Get offset of user_data variable in stack. Its at an offset of 0x40. This can be seen in a debugger or decompiler
2. Enter in padding to fill stack - 0x40 bytes, can be anything that isnt newline
3. Enter another 8 bytes for stored rbp - can be anything that isnt newline
4. Now we are overwriting the saved RIP - victory function exists. Get victory function's address via debugger
5. Overwrite saved-rip to point to victory function. Then terminate input with a newline.
6. Enter an empty input. On function return, a shell should be given


### Flag
`BEGINNER{buff3r_ov3rfl0000000w}`
</details>

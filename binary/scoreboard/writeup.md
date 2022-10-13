# Scoreboard

## Authors
- @ItsIronicIInsist

## Category
- Binary Exploit

## Description
Getting on the scoreboard's easy. Getting the prize, not so much.

## Difficulty
- Easy

## Points
50

## Hints
1. How do arrays perform pointer arithmetic under the hood?

## Files
- [scoreboard.c](./_ctfd/files/scoreboard.c) : source code
- [scoreboard](./_ctfd/files/scoreboard) : compiled program

## Solution
<details>
<summary>Spoiler</summary>

### Idea
An underflow in view_user allows a user to read the flag as a MESSAGE 

### Walkthrough
1. view_user uses a signed index for the array
2. flag is 'inconspicuously' read into a global variable, scoreboard is also a global variable. Through a debugger/decompiler, it can be seen that flag lies above scoreboard in memory
3. Can use negative indexes to treat memory before the scoreboard as fake 'users'. An index of -2 has the flag treated as the MESSAGE field of a user


### Flag
`BEGINNER{p0int3r_ar1thm3tics_s1mple}`
</details>

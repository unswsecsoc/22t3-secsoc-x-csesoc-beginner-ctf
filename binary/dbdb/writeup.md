# DBDB

## Authors
- @ItsIronicIInsist

## Category
- Binary Exploit

## Description
All this code for a glorified dictionary

## Difficulty
- Hard

## Points
150

## Hints
1. Magic numbers are gross

## Files
- [dbdb.c](./_ctfd/files/dbdb.c) : source code
- [dbdb](./_ctfd/files/dbdb) : compiled program

## Solution
<details>
<summary>Spoiler</summary>

### Idea
Beat ASLR libc leak via putting chunk in unsorted bin, then reallocating and reading addresses

Stack overflow in several functions, use one_gadget due to limited overflow space.

	- Register grooming needed for one_gadget to work. Have a key:pair where key = NULL, pair points to NULL

### Walkthrough

### Flag
`BEGINNER{on3_sh0ts_sur3_4re_us3ful}`
</details>

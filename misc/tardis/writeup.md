# tardis

## Authors
- [@joooooooooooooooooooooooooooooooooooosh](https://github.com/joooooooooooooooooooooooooooooooooooosh)

## Category
- misc

## Description

Welcome, Doctor. Can you prove to me that you truly have mastery over space and time?


## Difficulty
- Medium

## Points
60

## Files
- [flag_checker](./_ctfd/files/flag_checker): The program to extract the flag from
- [source.c](./_ctfd/files/source.c): A slightly modified version of the source code for `flag_checker`


## Solution
<details>
<summary>Spoiler</summary>

### Idea
Even when you can't access secrets directly, you can often learn information through the program behaviours related to the secrets.

This is known as a 'side channel', and a very common side channel in computing is measuring time, as well as other famous side channels such as measuring power usage, electromagnetic radiation, even the sounds produced by the clicking of a hard drive!

This can be seen in many practical exploits such as Spectre and Meltdown (these were cache side channel attacks which are essentially timing attacks).

### Walkthrough

1. Opening the provided source code, we see a very straightforward program. It reads lines of input, compares them against a hidden flag, and exits if the input matches the flag.

We can see that the flag is obfuscated in some way (the methodology is redacted in the source code) so finding the flag statically isn't really possible unless you reverse the obfuscation algorithm from the assembly of the compiled program.

2. We can see that there's a call to `usleep` in every iteration of the flag checking loop - this is a clear oversimplification for some kind of pretend expensive computation, but the point it that it introduces an easily measurable side channel!

Since the `usleep` function is called every time a character is checked, and it exits the function before the `usleep` call is run if the current character does not match the flag, this means we can bruteforce the correct flag by trying every character and seeing which one takes the longest.

This theory can be tested by entering in garbage (`AAAAAAAAA`) and comparing it to a sequence of characters that we know will be correct (`BEGINNER{`). There is a measurable difference in how much time it takes to process, even when swapping just the first character to be correct (`BAAAAAAAA`).

The solution can be found [in solve.py](./solve.py).

### Flag
`BEGINNER{wibb1y-w0bb1y-s1d3-ch4nn3l5}`
</details>

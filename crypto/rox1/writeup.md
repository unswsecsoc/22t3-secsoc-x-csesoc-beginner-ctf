# ROX 1

## Authors

- @stacksparrow4

## Category

- crypto

## Description

Yeah maybe a single byte XOR key is not the best...

## Difficulty

- Easy

## Points

50

## Hints

## Files

- [rox1.py](./_ctfd/files/rox1.py): Challenge file

## Solution

<details>
<summary>Spoiler</summary>

### Idea

This time, the key is the XOR of 0x42 and all bytes up to the current. This
requires only a slight modification to the solve script.

### Walkthrough

Refer to [solve.py](./solve.py)

### Flag

`BEGINNER{sT0p_m15using_X0R_5aed2}`

</details>

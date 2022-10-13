# ROX 3

## Authors

- @stacksparrow4

## Category

- crypto

## Description

Alright, if you figure this one out, I'm throwing in the towel.

## Difficulty

- Medium

## Points

80

## Hints

## Files

- [rox3.py](./_ctfd/files/rox3.py): Challenge file

## Solution

<details>
<summary>Spoiler</summary>

### Idea

This time, each byte is XORed with the byte 8 bytes in front of it. As we
know the first 8 bytes of the flag are `BEGINNER`, we can solve for the next 8
bytes, and so forth.

### Walkthrough

Refer to [solve.py](./solve.py)

### Flag

`BEGINNER{1_th1nk_w3_sh0uld_ju5t_g1v3_uP_4t_th15_p01nt_d872a}`

</details>

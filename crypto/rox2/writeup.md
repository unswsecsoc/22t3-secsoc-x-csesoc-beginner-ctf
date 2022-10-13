# ROX 2

## Authors

- @stacksparrow4

## Category

- crypto

## Description

Ok, so my last flag was insecure, however I've checked the math for this one.
You shouldn't be able to get this!

## Difficulty

- Medium

## Points

60

## Hints

## Files

- [rox2.py](./_ctfd/files/rox2.py): Challenge file

## Solution

<details>
<summary>Spoiler</summary>

### Idea

This time, each byte is XORed with the byte immediately before it. As we
know the last byte of the flag, we can use this to decrypt the flag.

### Walkthrough

Refer to [solve.py](./solve.py)

### Flag

`BEGINNER{tH15_1snt_gett1NG_4ny_b3tt3r_5117}`

</details>

# USB

## Authors

- stacksparrow4

## Category

- forensics

## Description

I had the flag ready for you on a usb, but I seem to have accidentally permanently
deleted all files off the usb. Maybe you might be able to recover it somehow? Come
find us on campus to give it a go!

## Difficulty

- Medium

## Points

0

## Solution

<details>
<summary>Spoiler</summary>

### Idea

Use data carving to retrieve a flag from the usb.

### Walkthrough

Any USB file carving tool should work. I used foremost.

1. Create a usb dump using a linux command similar to the following `dd if=/dev/sdb1 of=temp.img`
2. Run foremost on that file `foremost -i temp.img -o output`
3. The flag should be in the output folder.

### Flag

`BEGINNER{d1d_you_us3_f0r3m05t_b31b97}`

</details>

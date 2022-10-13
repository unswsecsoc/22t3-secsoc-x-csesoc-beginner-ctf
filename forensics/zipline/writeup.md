# zipline

## Authors
- @stevenp2

## Category
- Forensics

## Description
I want to make a zip line

I like zip lines

I searched wikihow on how to make a zip line

---WIKIHOW STEPS----

How to Construct a Zip Line

1. Select a distance between two solid objects, Preferably the objects should be trees or other solid structures
2. Lay the cable out between the two points.
3. Attach cable to one point.
4. Attach a temporary cable clamp about 20 feet (6.1 m) from the end of the cable.


## Difficulty
- Easy

## Points
40

## Hints
1. There might be something hidden inside one of the images
2. `unzip` one of the files

## Files
- [nyancat8.jpg](./_ctfd/files): Hidden zip inside
- [nyancat234.jpg](./ctfd/files): Red herring
- [nyancat2.jpg](./ctfd/files): Red herring
- [nyancat654.jpg](./ctfd/files): Red herring
- [nyancat69.jpg](./ctfd/files): Red herring
- [nyancat6.jpg](./ctfd/files): Red herring
- [nyancat8.jpg](./ctfd/files): Red herring
- [nyancat96.jpg](./ctfd/files): Red herring
- [nyancatt9.jpg](./ctfd/files): Red herring


## Solution
<details>
<summary>Spoiler</summary>

### Idea
Hide a zip file inside an image

### Walkthrough
1. Run `ls -l` and find that the nyancat8.jpg is suspiciously larger than the other nyancat images
2. Use the `zipline` clue in the challenge and unzip the file
3. Open `thesecret.zip` with a text editor to get the flag (alternative run `cat thesecret.zip`)

Alternatively, run `binwalk -e nyan*`, `cd` into the the new directory created and follow step 3.

### Flag
`BEGINNER{i_Am_a_pR0f3ss1on4l_z1PLin3r_w0oHo0}`
</details>

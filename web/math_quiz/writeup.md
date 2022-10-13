# math quiz

## Authors
- @XenocidePC

## Category
- web

## Description

Can you do my math quiz? I made it using Google Forms, so you won't be able to cheat!

`https://forms.gle/XG4gBdMvBYG5Kssy5`

**Format:** Remember to wrap your answer with `BEGINNER{}`.


## Difficulty
- Easy

## Points
50

## Hints

## Files


## Solution
<details>
<summary>Spoiler</summary>

### Idea
Google Forms are very insecure

### Walkthrough
1. Attempt the quiz, until you get to a point where it starts getting difficult
2. Use inspect element (`CTRL+Shift+I` on Chrome) and search for the question text in the HTML
3. Find the answer near the question text as a string that is used for validation
4. Complete the quiz!

Note: Google Forms are so insecure to the point where it is actually possible to get the flag without starting the quiz (it's just in the page source)

### Flag
`BEGINNER{c0ngr4tuLatiOns_y0u_p4sS3d}`
</details>

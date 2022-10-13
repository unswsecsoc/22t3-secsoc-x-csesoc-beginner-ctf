# irregular expressions

## Authors
- @XenocidePC

## Category
- Misc

## Description
Here is the flag for this challenge:

`BEGINNER{((((.).{1}\4).{2}\3).{3}\2).{4}\1}`

No, really, that's actually the flag!

## Difficulty
- Medium

## Points
60

## Hints

## Files


## Solution
<details>
<summary>Spoiler</summary>

### Idea
Provide flag as regex pattern, generate a string that matches

### Walkthrough
1. Notice that the flag is a regex (regular expression), either from the title or by looking at it
2. Create a string that matches the regex, either manually (checking that it matches with https://regex101.com/) or automatically with a site like https://onlinestringtools.com/generate-string-from-regex

This problem was originally meant to be harder, as I was anticipating answers like

`BEGINNER{ABACCABADDDABACCABAEEEEABACCABADDDABACCABA}`

However I forgot that having multiple `.`'s doesn't mean the characters have to be different so you can just do

`BEGINNER{AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA}`

### Flag
`BEGINNER{((((.).{1}\4).{2}\3).{3}\2).{4}\1}`
</details>

# log hunt

## Authors
- @Expressionless-Ball-Thing

## Category
- misc

## Description
I hid a flag in this repo, here's the link:

[`https://github.com/Expressionless-Ball-Thing/Flag`](https://github.com/Expressionless-Ball-Thing/Flag)

Good hunting.

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
Digging through a massive commits log to find a flag hidden in one of them.

### Walkthrough
1. First, retrieve the commit logs with `git log`
2. Either by outputting it to a file then word search or using `grep` or through any other methods, you will find that one of the git commits looked like this:

```
commit deee0587f844eb45be36eebf89df360c9a7898af
Author: Expressionless Ball Thing <lowestley0409@gmail.com>
Date:   Sat Oct 8 18:57:37 2022 +1100

    The flag is in here
```
3. Take note of the commit hash (that is, `deee0587f844eb45be36eebf89df360c9a7898af`) and show the commit changes using `git show deee0587f844eb45be36eebf89df360c9a7898af`.

4. Then simply word search for `BEGINNER` and you will find the flag in there amongst the text.

### Flag
`BEGINNER{n33dle_1n_4_hay5tack}`
</details>

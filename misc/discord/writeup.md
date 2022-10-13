# Discord

## Authors

- @stacksparrow4

## Category

- misc

## Description

Check out the new bot on the [SecSoc Discord server](https://secso.cc/discord)!

## Difficulty

- Easy

## Points

50

## Solution

<details>
<summary>Spoiler</summary>

### Idea

Retrieve a flag from the discord bot's profile picture.

### Walkthrough

1. Join the discord server.
2. Make sure you are using the web version of discord (ie. in a web browser). Then
   use inspect element.
3. Use "Select an element" (Ctrl-Shift-C) Inspect the bot's profile picture. It should
   give you

```html
<div
  class="wrapper-1VLyxH"
  role="img"
  aria-label="Beginner CTF Challenge, Online"
  aria-hidden="false"
  style="width: 80px; height: 80px;"
></div>
```

4. Keep opening the elements until you find the link `https://cdn.discordapp.com/avatars/1028434043143995452/1352a22c8537bee23625c42c65d1ca82.webp?size=100`
5. Go to the link and scan the code to get the flag. (You may need a different QR Code app to show you the entire flag)

### Flag

`BEGINNER{d1d_u_ju5T_h4CK_D15c0rd??_c8825d}`

</details>

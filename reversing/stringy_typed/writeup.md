# stringly typed

## Authors
- @XenocidePC

## Category
- reversing

## Description

My Bash login script is so secure, it's impossible to log in with any password!


## Difficulty
- Medium

## Points
60

## Hints

## Files
- [login.sh](./_ctfd/files/login.sh)


## Solution
<details>
<summary>Spoiler</summary>

### Idea
Exploit bash parameter expansion to execute "unreachable" code

### Walkthrough
1. Notice that the password cannot be empty `[ -z ]`, but if the password is non-empty `[ -n ]` the login will fail
2. Notice that the password non-empty check does not double quote `$password`, suggesting a word splitting exploit
3. Since spaces aren't allowed in passwords, the only way to word split is with tabs, so enter a password with words separated by tabs
4. Bash will split up $password into multiple words, causing the if statement to fail (no output since stderr is redirected with `2>/dev/null`) and executing the else statement instead, giving you the flag

Note: An unintended solution was to use globbing characters (e.g. entering `*` as the password) to get multiple words

This is why double quoting variables in Bash is very important for security! (Not that Bash is a secure language in any sense)

### Flag
`BEGINNER{d0uBl3_qUoTe_yOuR_vAr1aBLeS}`
</details>

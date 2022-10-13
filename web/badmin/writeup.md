# BADMIN

## Authors

- stacksparrow4

## Category

- web

## Description

Badmin login portal is a secure login portal for bad admins!
Note: to get the flag, you must log in as the user "admin".
No bruteforcing is required.

## Difficulty

- Medium

## Points

80

## Solution

<details>
<summary>Spoiler</summary>

### Idea

SQL Injection where the keywords "UNION" and "OR" are blacklisted and unusable.

### Walkthrough

The solution is to add an SQL comment so that the AND statement is not run
(as we do not know the password).
An example payload is `admin'--`

### Flag

`BEGINNER{sqL_inj3ction_15_a_cl4551c_caf0ab}`

</details>

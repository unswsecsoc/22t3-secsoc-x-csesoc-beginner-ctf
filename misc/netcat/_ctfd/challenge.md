---
name: "🌐😸"
category: "misc"
value: 15
flag: "BEGINNER{n3t_c4t5_are_c00l_c4t5}"
state: "active"
flag_case: "case_sensitive"
---

Meow! `netcat` is a tool used by cool cybercats like me in order to connect to other computers on the internet! It's used to connect to some CTF challenges, so I'm going to teach you how to use it.

(Finding this a bit daunting? That's okay! Not many challenges in this CTF need netcat. If you're stuck, feel free to try some other challenges instead, or reach out to us on [Discord](https://secso.cc/discord) and we'd love to help you out!)

### macOS/Linux

This is easy for you!

1. Open an application called 'Terminal', either from your Applications menu or Spotlight Search.

A window should now pop up! This is called a terminal, and you'll learn more about how to use it if you do COMP1511.

2. Type the following into the terminal where the blinking cursor is.
    `nc pwn.ctf.secso.cc 5005`

3. Press enter! You should now be able to talk to me and get a flag!

### Windows

You're probably a CSE student. The best option for you is to connect to a CSE machine and follow the Linux instructions above!

If not, you'll need to follow these steps:

Unfortunately, Windows doesn't come with netcat installed. However, there is a similar tool called telnet that you can use instead. Before we can use it, we'll need to enable it.

1. Open Search in the Start Menu
2. Select 'Turn Windows features on or off'. A window should open.
3. Scroll down through the window, and look for an option called 'Telnet Client'. Make sure it is ticked, and press 'OK'. It should take a few moments to enable.
4. Open Search again, type in `cmd`, and press enter.

Yay! A window should open. This is called the Command Prompt. You can use telnet from the command prompt to connect and talk to me!

5. Type the following command into the Command Prompt window next to the blinking cursor:
    `telnet pwn.ctf.secso.cc 5005`

6. Press Enter! You can talk to me now and get a flag!

(Luckily, you'll get access to, and learn how to use a Linux command prompt if you do COMP1511. You can even learn to install [Linux with Windows](https://abiram.me/wsl-github)!)

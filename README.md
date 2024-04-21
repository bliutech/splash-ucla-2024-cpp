# 👾 Splash at UCLA 2024: Game Programming in C++

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/bliutech/splash-ucla-2024-cpp?quickstart=1)

Class resources for "Game Programming in C++" class taught to high school students at Splash @ UCLA 2024. This repository mostly contains code for an eductional game called "Pixel Panic" written in C++ by Benson Liu & Ming Zhu. It contains a few coding challenges for students to try and practice what they know about C++. To learn more about the class, check out the [slides](https://docs.google.com/presentation/d/1h2ZUdXyQxhcOHxC9gGeyEFfhUmRaC1kvG14yEtsadcM/edit?usp=sharing).

<p align="center">
    <img src=".github/pixel-panic.gif" alt="Pixel panic in action!" width="40%"/>
</p>

## Build
To build the game, run the following command.

```
make
```

There is also some auxiliary development support.

```
make format # run source code formatter
make valgrind # check for memory leaks
make clean # delete all build files
```

## Challenges
1. **Add laser shooting.** Inside `player.cpp` implement handling of shooting the layer from keyboard input. This involves getting familiar with conditionals/if-statements in C++.
2. **Add alien spawning.** Inside `alienspawner.cpp` implement spawning aliens 5 at a time using a for loop.
3. **Add alien zig-zagging.** Inside `alien.cpp` add zig-zagging movement to the alien enemy. This involves doing some game programming to add a new game mechanic.
4. **Add missiles.** Inside `missile.hpp`, add the class definition for `Missile` that inherits from the `Actor` class and then update `missile.cpp` to include zig-zagging for this new kind of bullet. Make sure to uncomment code in `missile.cpp` and `player.cpp` to see this in action!
5. **Come up with your own features!** What other features of the game do you think will be fun to add?

## Authors
The code for this class was developed by Benson Liu and Ming Zhu. To ask any questions about the class and this game, please contact the authors.

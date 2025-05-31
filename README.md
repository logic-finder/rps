## Introduction
A simple command line "rock paper scissors" game simulator written in C which utilizes a circular doubly linked list.

Given `list = [rock, paper, scissors]`, if the user's hand shape were:
- next to the program's one, then the user is the winner.
- previous to the program's one, then the program is the winner.
- the same with the program's one, then the game is a tie.

## Build
```bash
make        # builds `rps`, the executable
make clean  # deletes *.o and the executable
```
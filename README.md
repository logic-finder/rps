## Introduction
A simple command line "rock paper scissors" game simulator written in C which utilizes a circular doubly linked list.

## Build
```bash
make        # builds `rps`, the executable
make clean  # deletes *.o and the executable
```

## Explanation
Given that `list = [rock, paper, scissors]` and `list` is circular, if the user's hand shape were:
- next to the program's one, then the user is the winner.
- previous to the program's one, then the program is the winner.
- the same with the program's one, then the game is a tie.

Let's give the above approach a compare against the following:
```c
switch (user_input) {
   case rock:
      switch (program_input) {
         case rock: printf("tie"); break;
         case paper: printf("defeated"); break;
         case scissors: printf("win"); break;
      }
      break;
   case paper:
      switch (program_input) {
         case rock: printf("win"); break;
         case paper: printf("tie"); break;
         case scissors: printf("defeated"); break;
      }
      break;
   case scissors:
      switch (program_input) {
         case rock: printf("defeated"); break;
         case paper: printf("win"); break;
         case scissors: printf("tie"); break;
      }
      break;
}
```
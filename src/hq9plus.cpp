#include "hq9plus.hpp"

void run_hq9plus(std::string& command, Catcher&) {
   for (char ch: command) {
      if (ch == 'H') {
         puts("Hello, World!\n");
      }
      else if (ch == 'Q') {
         puts(command.c_str());
      }
      else if (ch == '9') {
         for (int i = 99; i >= 0;) {
            printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
            if (--i == 0) {
               break;
            }
            printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", i);
         }
         puts("Take one down and pass it around, no more bottles of beer on the wall.\n");
         puts("No more bottles of beer on the wall, no more bottles of beer.");
         puts("Go to the store and buy some more, 99 bottles of beer on the wall.");
      }
   }
}

void help_hq9plus() {
   puts("H - Print 'Hello, World!'.");
   puts("Q - Print command.");
   puts("9 - Print the song '99 bottles of beer'.");
   puts("+ - Increment the accumulator.");
   puts("Other characters are ignored.");
}

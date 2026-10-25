#include "deadfish.hpp"
#include <iostream>

void run_deadfish(std::string& command, Catcher& catcher) {
   unsigned char accumulator = 0;
   for (char ch: command) {
      if (ch == 'i') {
         ++accumulator;
      }
      else if (ch == 'd') {
         --accumulator;
      }
      else if (ch == 's') {
         accumulator *= accumulator;
      }
      else if (ch == 'o') {
         std::cout << accumulator << std::flush;
      }
      else if (ch == 'h') {
         exit(EXIT_SUCCESS);
      }
   }
}

void help_deadfish() {
   puts("i - Increment accumulator.");
   puts("d - Decrement accumulator.");
   puts("s - Square accumulator.");
   puts("o - Output accumulator as ASCII.");
   puts("h - Halt the program.");
   puts("Other characters are ignored.");
}

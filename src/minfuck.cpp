#include "minfuck.hpp"
#include <unordered_map>

void run_minfuck(std::string& command, Catcher&) {
   std::unordered_map<long, unsigned char> memory;
   long pointer = 0;

   for (char ch: command) {
      if (ch == '>') {
         ++pointer;
      }
      else if (ch == '<') {
         --pointer;
      }
      else if (ch == '+') {
         ++memory[pointer];
      }
      else if (ch == '-') {
         --memory[pointer];
      }
   }
}

void help_minfuck() {
   puts("+ - Increment at pointer.");
   puts("- - Decrement at pointer.");
   puts("> - Move pointer right.");
   puts("< - Move pointer left.");
   puts("Other characters are ignored.");
}

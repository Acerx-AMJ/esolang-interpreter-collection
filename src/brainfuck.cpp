#include "brainfuck.hpp"
#include "catcher.hpp"
#include <unordered_map>
#include <iostream>

void run_brainfuck(std::string& command, Catcher& catcher) {
   std::unordered_map<long, unsigned char> memory;
   long pointer = 0;

   long size = command.size();
   for (long index = 0; index < size; ++index) {
      char ch = command[index];

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
      else if (ch == '.') {
         std::cout << memory[pointer] << std::flush;
      }
      else if (ch == ',') {
         int c = std::cin.get();
         if (c != EOF) {
            memory[pointer] = static_cast<unsigned char>(c);
         }
      }
      else if (ch == '[') {
         if (memory[pointer] != 0) {
            continue;
         }
         size_t depth = 1;
         for (++index; index < size && depth >= 1; ++index) {
            depth += (command[index] == '[');
            depth -= (command[index] == ']');
         }

         if (depth != 0) {
            catcher.insert("Could not find a matching ']' token.");
            return;
         }
      }
      else if (ch == ']') {
         if (memory[pointer] == 0) {
            continue;
         }
         size_t depth = 1;
         for (--index; index >= 0 && depth >= 0; --index) {
            depth -= (command[index] == '[');
            depth += (command[index] == ']');
         }

         if (depth != 0) {
            catcher.insert("Could not find a matching '[' token.");
            return;
         }
      }
   }
}

void help_brainfuck() {
   puts("+ - Increment at pointer.");
   puts("- - Decrement at pointer.");
   puts("> - Move pointer right.");
   puts("< - Move pointer left.");
   puts(". - Output memory at pointer as ASCII.");
   puts(", - Store user input at pointer as ASCII.");
   puts("[ - If memory is zero, jump forward to a matching ']'.");
   puts("] - If memory is nonzero, jump backwards to a matching '['.");
   puts("Other characters are ignored.");
}

#include "hq9efuck.hpp"

#include "catcher.hpp"
#include <unordered_map>
#include <iostream>

void run_hq9efuck(std::string& command, Catcher& catcher) {
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
      else if (ch == 'e') {
         puts("42");
      }
      else if (ch == 'H') {
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

void help_hq9efuck() {
   puts("+ - Increment at pointer.");
   puts("- - Decrement at pointer.");
   puts("> - Move pointer right.");
   puts("< - Move pointer left.");
   puts(". - Output memory at pointer as ASCII.");
   puts(", - Store user input at pointer as ASCII.");
   puts("[ - If memory is zero, jump forward to a matching ']'.");
   puts("] - If memory is nonzero, jump backwards to a matching '['.");
   puts("H - Print 'Hello, World!'.");
   puts("Q - Print command.");
   puts("9 - Print the song '99 bottles of beer'.");
   puts("e - Computes and prints the answer to the Ultimate Question of Life, the Universe and Everything.");
   puts("Other characters are ignored.");
}

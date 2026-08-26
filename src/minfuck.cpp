#include "minfuck.hpp"

#include <iostream>
#include <unordered_map>

void run_minfuck(const std::string& command, Catcher&)
{
   std::unordered_map<long, unsigned char> memory;
   long pointer = 0;

   for (const auto& ch : command)
   {
      if (ch == '>')
         ++pointer;
      else if (ch == '<')
         --pointer;
      else if (ch == '+')
         ++memory[pointer];
      else if (ch == '-')
         --memory[pointer];
   }
}

void help_minfuck()
{
   std::cout << "+ - Increment at pointer.\n";
   std::cout << "- - Decrement at pointer.\n";
   std::cout << "> - Move pointer right.\n";
   std::cout << "< - Move pointer left.\n";
   std::cout << "Other characters are ignored.\n";
}

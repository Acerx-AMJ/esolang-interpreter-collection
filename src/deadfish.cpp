#include "deadfish.hpp"

#include <iostream>

void run_deadfish(const std::string& command, Catcher& catcher)
{
   unsigned char accumulator = 0;
   for (const auto& ch : command)
   {
      if (ch == 'i')
         ++accumulator;
      else if (ch == 'd')
         --accumulator;
      else if (ch == 's')
         accumulator *= accumulator;
      else if (ch == 'o')
         std::cout << accumulator << std::flush;
   }
}

void help_deadfish()
{
   std::cout << "i - Increment accumulator.\n";
   std::cout << "d - Decrement accumulator.\n";
   std::cout << "s - Square accumulator.\n";
   std::cout << "o - Output accumulator as ASCII.\n";
   std::cout << "Other characters are ignored.\n";
}

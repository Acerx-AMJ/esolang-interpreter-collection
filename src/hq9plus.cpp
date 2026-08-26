#include "hq9plus.hpp"

#include <iostream>

void run_hq9plus(const std::string& command, Catcher&)
{
   long pointer = 0;
   for (const auto& ch : command)
   {
      if (ch == 'H')
         std::cout << "Hello, World!\n";
      else if (ch == 'Q')
         std::cout << command << '\n';
      else if (ch == '9')
      {
         for (int i = 99; i >= 0;)
         {
            std::cout << i << " bottles of beer on the wall, " << i << " bottles of beer.\n";
            --i;
            if (i == 0)
               break;
            std::cout << "Take one down and pass it around, " << i << " bottles of beer on the wall.\n\n";
         }
         std::cout << "Take one down and pass it around, no more bottles of beer on the wall.\n\n";
         std::cout << "No more bottles of beer on the wall, no more bottles of beer.\n";
         std::cout << "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
      }
      else if (ch == '+')
         ++pointer;
   } 
}

void help_hq9plus()
{
   std::cout << "H - Print 'Hello, World!'.\n";
   std::cout << "Q - Print command.\n";
   std::cout << "9 - Print the song '99 bottles of beer'.\n";
   std::cout << "+ - Increment the accumulator.\n";
   std::cout << "Other characters are ignored.\n";
}

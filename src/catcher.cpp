#include "catcher.hpp"

#include <iostream>

void Catcher::error(const char* error)
{
   insert(error);
   display();
}

void Catcher::insert(const char* error)
{
   errors.push_back(error);
}

bool Catcher::ok() const
{
   return errors.empty();
}

void Catcher::display()
{
   if (ok()) return;

   std::cout << '\n' << errors.size() << " Error(s) occurred:\n";
   for (const auto& error: errors)
      std::cout << error << '\n';

   std::cout << '\n';
   errors.clear();
   std::exit(-1);
}

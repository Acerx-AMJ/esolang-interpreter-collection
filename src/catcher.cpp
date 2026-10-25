#include "catcher.hpp"
#include <cstdio>
#include <cstdlib>

void Catcher::error(const char* error) {
   insert(error);
   display();
}

void Catcher::insert(const char* error) {
   errors.push_back(error);
}

bool Catcher::ok() const {
   return errors.empty();
}

void Catcher::display() {
   if (ok()) {
      return;
   }

   printf("\n%zu Error(s) occurred:\n", errors.size());
   for (const char *error: errors) {
      puts(error);
   }

   putchar('\n');
   errors.clear();
   exit(EXIT_FAILURE);
}

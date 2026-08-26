#ifndef CATCHER_HPP
#define CATCHER_HPP

#include <vector>

class Catcher
{
   std::vector<const char*> errors;
public:

   void error(const char* error);
   void insert(const char* error);
   bool ok() const;
   void display();
};

#endif

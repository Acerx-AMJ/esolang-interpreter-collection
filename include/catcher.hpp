#pragma once
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

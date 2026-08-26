#include "catcher.hpp"
#include "file.hpp"
#include "languages.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
   Catcher catcher;

   if (argc == 2 && std::string(argv[1]) == "-h")
   {
      std::cout << "inter -h                 Display help.\n";
      std::cout << "inter language -h        Display help about the language.\n";
      std::cout << "inter language \"code\"    Run following code in specified language.\n";
      std::cout << "inter language file.ext  Read file and run it.\n";
      std::cout << "\nSupported Languages:\n";
      std::cout << "brainfuck, deadfish, hq9efuck, hq9+, minfuck.\n";
      return 0;
   }

   if (argc != 3)
      catcher.error("Expected 2 arguments.");
   
   std::string arg1 = argv[1], arg2 = argv[2];
   if (is_file(arg2))
      arg2 = read_file(arg2, catcher);
   catcher.display();

   handle_command(arg1, arg2, catcher);
   catcher.display();
}

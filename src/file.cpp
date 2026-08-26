#include "file.hpp"

#include "catcher.hpp"
#include <filesystem>
#include <fstream>

bool is_file(const std::string& command)
{
   try { return std::filesystem::exists(command) && std::filesystem::is_regular_file(command); }
   catch (...) { return false; }
}

std::string read_file(const std::string& command, Catcher& catcher)
{
   std::ifstream file (command);

   if (!file.is_open())
   {
      catcher.insert("Could not read file.");
      return "";
   }

   std::string output, temp;
   while (std::getline(file, temp))
      output += temp;
   
   return output;
}

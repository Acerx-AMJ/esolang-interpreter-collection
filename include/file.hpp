#ifndef FILE_HPP
#define FILE_HPP

#include <string>

class Catcher;

bool is_file(const std::string& command);
std::string read_file(const std::string& file, Catcher& catcher);

#endif

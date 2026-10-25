#pragma once
#include <string>

bool is_file(const std::string& command);
std::string read_file(const std::string& file, class Catcher& catcher);

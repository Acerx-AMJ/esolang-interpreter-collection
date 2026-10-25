#pragma once
#include <string>

void handle_command(const std::string& language, std::string& command, class Catcher& catcher);
void handle_help(const std::string& language, class Catcher& catcher);
void run(const std::string& language, std::string& command, class Catcher& catcher);

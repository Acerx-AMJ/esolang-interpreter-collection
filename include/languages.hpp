#ifndef LANGUAGES_HPP
#define LANGUAGES_HPP

#include <string>

class Catcher;

void handle_command(const std::string& language, const std::string& command, Catcher& catcher);
void handle_help(const std::string& language, Catcher& catcher);
void run(const std::string& language, const std::string& command, Catcher& catcher);

#endif

#ifndef MINFUCK_HPP
#define MINFUCK_HPP

#include <string>

class Catcher;

void run_minfuck(const std::string& commmand, Catcher&);
void help_minfuck();

#endif

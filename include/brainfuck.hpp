#ifndef BRAINFUCK_HPP
#define BRAINFUCK_HPP

#include <string>

class Catcher;

void run_brainfuck(const std::string& command, Catcher& catcher);
void help_brainfuck();

#endif

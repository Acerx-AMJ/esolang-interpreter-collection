#include "languages.hpp"

#include "brainfuck.hpp"
#include "catcher.hpp"
#include "deadfish.hpp"
#include "hq9efuck.hpp"
#include "hq9plus.hpp"
#include "minfuck.hpp"
#include <functional>
#include <unordered_map>
#include <utility>

using namespace std::string_literals;

static std::unordered_map<std::string, std::pair<std::function<void()>, std::function<void(const std::string&, Catcher&)>>> language_map {
   {"brainfuck"s, {help_brainfuck, run_brainfuck}},
   {"deadfish"s, {help_deadfish, run_deadfish}},
   {"hq9efuck"s, {help_hq9efuck, run_hq9efuck}},
   {"hq9+"s, {help_hq9plus, run_hq9plus}},
   {"minfuck"s, {help_minfuck, run_minfuck}}
};

void handle_command(const std::string& language, const std::string& command, Catcher& catcher)
{
   if (command == "-h")
      handle_help(language, catcher);
   else
      run(language, command, catcher);
}

void handle_help(const std::string& language, Catcher& catcher)
{
   auto it = language_map.find(language);

   if (it == language_map.end())
      catcher.error("Could not find the given language. See -h for a list of commands.");
   it->second.first();
}

void run(const std::string& language, const std::string& command, Catcher& catcher)
{
   auto it = language_map.find(language);

   if (it == language_map.end())
      catcher.error("Could not find the given language. See -h for a list of commands.");
   it->second.second(command, catcher);
}

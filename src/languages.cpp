#include "languages.hpp"
#include "beergolf.hpp"
#include "brainfuck.hpp"
#include "catcher.hpp"
#include "deadfish.hpp"
#include "hq9efuck.hpp"
#include "hq9plus.hpp"
#include "minfuck.hpp"
#include <unordered_map>

struct Language {
   void (*help)();
   void (*run)(std::string&, Catcher&);
};

static const std::unordered_map<std::string, Language> languageMap {
   {"brainfuck", {help_brainfuck, run_brainfuck}},
   {"deadfish", {help_deadfish, run_deadfish}},
   {"hq9efuck", {help_hq9efuck, run_hq9efuck}},
   {"hq9+", {help_hq9plus, run_hq9plus}},
   {"minfuck", {help_minfuck, run_minfuck}},
   {"beergolf", {help_beergolf, run_beergolf}}
};

void handle_command(const std::string& language, std::string& command, Catcher& catcher) {
   if (command == "-h") {
      handle_help(language, catcher);
   }
   else {
      run(language, command, catcher);
   }
}

void handle_help(const std::string& language, Catcher& catcher) {
   if (auto it = languageMap.find(language); it != languageMap.end()) {
      it->second.help();
   }
   else {
      catcher.error("Could not find the given language. See -h for a list of commands.");
   }
}

void run(const std::string& language, std::string& command, Catcher& catcher) {
   if (auto it = languageMap.find(language); it != languageMap.end()) {
      it->second.run(command, catcher);
   }
   else {
      catcher.error("Could not find the given language. See -h for a list of commands.");
   }
}

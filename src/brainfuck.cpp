#include "brainfuck.hpp"

#include "catcher.hpp"
#include <unordered_map>
#include <iostream>

enum Token : char
{ right, left, increment, decrement, output, input, forward, back };

static std::unordered_map<char, Token> token_map
{
   {'>', right}, {'<', left}, {'+', increment}, {'-', decrement}, {'.', output},
   {',', input}, {'[', forward}, {']', back}
};

void run_brainfuck(const std::string& command, Catcher& catcher)
{
   std::vector<Token> tokens;
   for (const auto& ch : command)
   {
      auto it = token_map.find(ch);
      if (it != token_map.end())
         tokens.push_back(it->second);
   }

   std::unordered_map<long, unsigned char> memory;
   long pointer = 0;

   for (long index = 0; index < tokens.size(); ++index)
   {
      const auto& command = tokens[index];

      if (command == Token::right)
         ++pointer;
      else if (command == Token::left)
         --pointer;
      else if (command == Token::increment)
         ++memory[pointer];
      else if (command == Token::decrement)
         --memory[pointer];
      else if (command == Token::output)
         std::cout << memory[pointer] << std::flush;
      else if (command == Token::input)
      {
         int c = std::cin.get();
         if (c != EOF)
            memory[pointer] = static_cast<unsigned char>(c);
      }
      else if (command == Token::forward)
      {
         if (memory[pointer] != 0)
            continue;
         
         size_t depth = 1;
         for (++index; index < tokens.size(); ++index)
         {
            if (tokens[index] == Token::forward)
               ++depth;
            else if (tokens[index] == Token::back)
               --depth;

            if (depth == 0)
               break;
         }

         if (depth != 0)
         {
            catcher.insert("Could not find a matching ']' token.");
            return;
         }
      }
      else if (command == Token::back)
      {
         if (memory[pointer] == 0)
            continue;
         
         size_t depth = 1;
         for (--index; index >= 0; --index)
         {
            if (tokens[index] == Token::forward)
               --depth;
            else if (tokens[index] == Token::back)
               ++depth;
            
            if (depth == 0)
               break;
         }

         if (depth != 0)
         {
            catcher.insert("Could not find a matching '[' token.");
            return;
         }
      }
   }
}

void help_brainfuck()
{
   std::cout << "+ - Increment at pointer.\n";
   std::cout << "- - Decrement at pointer.\n";
   std::cout << "> - Move pointer right.\n";
   std::cout << "< - Move pointer left.\n";
   std::cout << ". - Output memory at pointer as ASCII.\n";
   std::cout << ", - Store user input at pointer as ASCII.\n";
   std::cout << "[ - If memory is zero, jump forward to a matching ']'.\n";
   std::cout << "] - If memory is nonzero, jump backwards to a matching '['.\n";
   std::cout << "Other characters are ignored.\n";
}

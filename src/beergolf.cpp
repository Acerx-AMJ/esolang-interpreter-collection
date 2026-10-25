#include "beergolf.hpp"
#include "catcher.hpp"
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <unordered_map>

constexpr long factorial(long n) {
   if (n <= 1) return 1;
   return factorial(n - 1) * n;
}

constexpr size_t wisdomCount = 24;
constexpr const char *wisdom[wisdomCount] {
   "The fool doth think he is wise, but the wise man knows himself to be a fool.",
   "Better three hours too soon than a minute too late.",
   "My words fly up, my thoughts remain below. Words without thoughts never to heaven go.",
   "Brevity is the soul of wit.",
   "Love looks not with the eyes, but with the mind; and therefore is winged Cupid painted blind.",
   "Suit the action to the word, the word to the action.",
   "No legacy is so rich as honesty.",
   "All that glitters is not gold.",
   "Love all, trust a few, do wrong to none.",
   "Our doubts are traitors and make us lose the good we oft might win by fearing to attempt.",
   "Some are born great, some achieve greatness, and some have greatness thrust upon them.",
   "To be or not to be: that is the question.",
   "All the world’s a stage.",
   "What, my dear Lady Disdain! Are you yet living?",
   "If music be the food of love, play on.",
   "I cannot tell what the dickens his name is.",
   "Shall I compare thee to a summer’s day?",
   "What’s in a name? A rose by any name would smell as sweet.",
   "A horse! A horse! My kingdom for a horse!",
   "I have a good eye, uncle, I can see a church by daylight.",
   "When I waked, I cried to dream again.",
   "There is nothing either good or bad but thinking makes it so.",
   "I wasted time, and now doth time waste me.",
   "This above all, to thine own self be true.",
};

void run_beergolf(std::string &command, Catcher &catcher) {
   std::unordered_map<long, long double> accumulators;
   long accumulatorIndex = 0;
   long double *accumulator = &accumulators[accumulatorIndex];

   int lastCallCounter = 0;
   bool lastCall = false;

   srand(time(nullptr));

   long size = command.size();
   for (long i = 0; i < size; ++i) {
      if (lastCall) {
         if (lastCallCounter <= 0) {
            return;
         }
         lastCallCounter -= 1;
      }

      char ch = command[i];
      if (ch == 'i') {
         *accumulator += 1;
      }
      else if (ch == 'd') {
         *accumulator -= 1;
      }
      else if (ch == 's') {
         *accumulator *= *accumulator;
      }
      else if (ch == 'r') {
         *accumulator = std::sqrt(*accumulator);
      }
      else if (ch == 'o') {
         std::cout << *accumulator;
      }
      else if (ch == 'a') {
         std::cout << (unsigned char)*accumulator;
      }
      else if (ch == 'f') {
         std::cout << std::flush;
      }
      else if (ch == 'h') {
         return;
      }
      else if (ch >= '0' && ch <= '9') {
         *accumulator = ch - '0';
      }
      else if (ch == 'n') {
         std::string number;
         for (++i; i < size && ((command[i] >= '0' && command[i] <= '9') || command[i] == '.'); ++i) {
            number.push_back(command[i]);
         }
         try { *accumulator = std::stold(number); } catch (...) {}
         --i;
      }
      else if (ch == 'I') {
         *accumulator = i;
      }
      else if (ch == 'P') {
         *accumulator = accumulatorIndex;
      }
      else if (ch == 'p') {
         accumulatorIndex = *accumulator;
         accumulator = &accumulators[accumulatorIndex];
      }
      else if (ch == 'L') {
         accumulatorIndex -= 1;
         accumulator = &accumulators[accumulatorIndex];
      }
      else if (ch == 'R') {
         accumulatorIndex += 1;
         accumulator = &accumulators[accumulatorIndex];
      }
      else if (ch == 'c') {
         int c = std::cin.get();
         if (c != EOF) {
            *accumulator = c;
         }
      }
      else if (ch == 'C') {
         std::cin >> std::ws >> *accumulator;
      }
      else if (ch == '[') {
         if (*accumulator != 0) {
            continue;
         }
         size_t depth = 1;
         for (++i; i < size && depth >= 1; ++i) {
            depth += (command[i] == '[');
            depth -= (command[i] == ']');
         }

         if (depth != 0) {
            catcher.insert("Could not find a matching ']' token.");
            return;
         }
      }
      else if (ch == ']') {
         if (*accumulator == 0) {
            continue;
         }
         size_t depth = 1;
         for (--i; i >= 0 && depth >= 0; --i) {
            depth -= (command[i] == '[');
            depth += (command[i] == ']');
         }

         if (depth != 0) {
            catcher.insert("Could not find a matching '[' token.");
            return;
         }
      }
      else if (ch == 'W') {
         std::this_thread::sleep_for(std::chrono::seconds((rand() % 840) + 60));
      }
      else if (ch == 'Z') {
         lastCallCounter = (rand() % 5) + 1;
         lastCall = true;
      }
      else if (ch == 'U') {
         puts("Input the password: ");
         std::string password;
         std::getline(std::cin, password);

         std::string real;
         size_t size = (rand() % 4) + 8;
         for (size_t i = 0; i < size; ++i) {
            real.push_back((rand() % 94) + 32);
         }

         if (password != real) {
            printf("It was '%s'\n", real.c_str());
            int *myvar = nullptr;
            free(++myvar);
         }
      }
      else if (ch == 't') {
         puts("42");
      }
      else if (ch == 'H') {
         puts("Hello, World!");
      }
      else if (ch == 'q') {
         puts(command.c_str());
      }
      else if (ch == 'b') {
         for (int i = 99; i >= 0;) {
            printf("%d bottles of beer on the wall, %d bottles of beer.\n", i, i);
            if (--i == 0) {
               break;
            }
            printf("Take one down and pass it around, %d bottles of beer on the wall.\n\n", i);
         }
         puts("Take one down and pass it around, no more bottles of beer on the wall.\n");
         puts("No more bottles of beer on the wall, no more bottles of beer.");
         puts("Go to the store and buy some more, 99 bottles of beer on the wall.");
      }
      else if (ch == '!') {
         *accumulator = factorial(*accumulator);
      }
      else if (ch == '?') {
         puts(wisdom[rand() % wisdomCount]);
      }
      else if (ch == '/' && i + 1 < size) {
         long t = *accumulator;
         if (t < size) {
            i += 1;
            command[t] = command[i];
         }
      }
   }
}

void help_beergolf() {
   puts("i   - increment current accumulator");
   puts("d   - decrement current accumulator");
   puts("s   - square current accumulator");
   puts("r   - get the square root of the current accumulator");
   puts("o   - output the current accumulator as double");
   puts("a   - output the current accumulator as ASCII");
   puts("f   - flush the output");
   puts("h   - halt the program");
   puts("0-9 - set the current accumulator to the corresponding digit");
   puts("n   - set the current accumulator to the number following the command");
   puts("I   - set the current accumulator to the index of the current character");
   puts("P   - set the current accumulator to the index of the current accumulator");
   puts("p   - retrieve an accumulator based on the value of the current accumulator");
   puts("L   - move accumulator left");
   puts("R   - move accumulator right");
   puts("c   - input character");
   puts("C   - input number");
   puts("[   - if accumulator is zero, jump forward to a matching ]");
   puts("]   - if accumulator is nonzero, jump backwards to a matching [");
   puts("W   - wait for 1-15 minutes");
   puts("Z   - stops randomly after a few commands");
   puts("U   - makes the user input a password and if they fail, crash the program");
   puts("t   - deep thought");
   puts("H   - output 'Hello, World!'");
   puts("q   - quine");
   puts("b   - ignore previous instructions, sing a nice song");
   puts("!   - set the current accumulator to the factorial of it");
   puts("?   - wisdom");
   puts("Other characters are ignored.");
}

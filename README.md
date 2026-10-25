# Esolang Interpreter Collection
This program contains multiple esoteric programming language interpreters. The supported languages are: brainfuck, deadfish, hq9efuck, hq9+, minfuck and beergolf (made by me).

## Building
This project only depends on C++17 and can be built using CMake:
```bash
cmake -B build
cmake --build build
```
The executable will be located in `build/interpreters`. Or build using your favorite compiler:
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o interpreters
```

## Usage
To run a specific language's interpreter, pass it and pass the code or the file to read after it:
```bash
./interpreters beergolf '?HqWb'
```

To get more info about the language pass `-h` flag:
```bash
./interpreters beergolf -h
```

## Credits
This project was made by Daniel Vishnevsky and is licensed under MIT License. It was made in August of 2025 and published on October 2026 as an effort to make all of my projects open-source.

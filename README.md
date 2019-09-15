# CMPE152_LexicalAnalyzer
Lexical analyzer in C++

**By**: Austin Tran, Tiffany Nguyen, Hanna Oh, & Tien Tran

Instructions on how to build it:
1. Make sure you have an IDE or use Terminal to run the analyzer
2. For IDE: Just make sure your IDE supports C/C++, download our files and put it into one project, build it, and the output should show in the console. If you want to test different test files: go to lexer.h, find  **in_stream.open("test.txt");**, and change test.txt to the file name you want to test -- make sure your files are outside the src folder in the project. (We used Eclipse C/C++ to run our code)

For terminal:
We installed a g++ compiler using the command: sudo apt-get install build-essential

** Then, we compiled our file main.cpp in the command: gcc+ lexer.h main.cpp token.h

** Just type "./a.out" and the output will show up on the terminal

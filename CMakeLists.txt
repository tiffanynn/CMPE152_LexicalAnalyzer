cmake_minimum_required(VERSION 3.14)
project(CMPE152_LexicalAnalyzer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)

add_executable(CMPE152_LexicalAnalyzer
        .idea/\$CACHE_FILE\$
        .idea/.gitignore
        .idea/CMPE152_LexicalAnalyzer.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        lexer.h
        lexertest.cpp
        main.cpp
        test.txt
        token.h)

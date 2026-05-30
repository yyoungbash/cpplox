SRC_FILES=$(find src -name "*.cpp")

clang++ -std=c++20 -Wall -Wextra -g $SRC_FILES -I include -o bin/cpplox

./bin/cpplox

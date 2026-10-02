#ifndef LOX_SCANNER_H
#define LOX_SCANNER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include "lox/token.h"

class Scanner {
  public:
    Scanner(std::string source);
    std::vector scanTokens();
  private:
    std::string source;
    std::vector tokens;
    int line = 1;
    size_t start = 0;
    size_t current = 0;

    bool isAtEnd();
    void scanToken();
    void addToken(TokenType type);
    void addToken(TokenType type, std::any literal);
};
#endif // !LOX_SCANNER_H

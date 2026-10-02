#ifndef LOX_TOKEN_H
#define LOX_TOKEN_H

#include "lox/token_type.h"
#include <any>
#include <string>

class Token {
public:
  TokenType type;
  std::string lexeme;
  std::any literal;
  int line;

  Token(TokenType type, std::string lexeme, std::any literal, int line);

  std::string toString() const;
};

#endif // LOX_TOKEN_H

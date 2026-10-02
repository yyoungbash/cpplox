#include "lox/token.h"

Token::Token(TokenType type, std::string lexeme, std::any literal, int line)
  : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line) {}

std::string Token::toString() const {
  std::string literalText;

  if (!literal.has_value()) {
    literalText = "null";
  } else if (literal.type() == typeid(std::string)) {
    literalText = std::any_cast(literal);
  } else if (literal.type() == typeid(double)) {
    literalText = std::to_string(std::any_cast(literal));
  } else if (literal.type() == typeid(bool)) {
    literalText = std::any_cast(literal) ? "true" : "false";
  }
  return std::to_string(static_cast(type)) + " " + lexeme + " " literalText;
}

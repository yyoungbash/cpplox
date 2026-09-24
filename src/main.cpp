#include <iostream>
#include <sysexits.h>
#include <string>
#include <fstream>
#include <sstream>

void runFile(const std::string& path);
void runPromt();
void run(const std::string& source);

static bool hadError = false;

int main(int argc, char* argv[]) {
  if (argc > 2){
    std::cout << "Usage: cpplox [script]\n";
    return EX_USAGE;
  } else if (argc == 2) {
    runFile(argv[1]);
  } else {
    runPromt();
  }

  return 0;
}

void runFile(const std::string& path) {
  std::ifstream file(path, std::ios::binary);
  if (!file.is_open()) {
    std::cerr << "Could not open file:" << path << "\n";
    std::exit(66);
  }

  if (hadError) std::exit(65);

  std::ostringstream buffer;
  buffer << file.rdbuf();
  run(buffer.str());
}

void runPromt() {
  std::string line;
    for(;;) {
      std::cout << "> ";
      if (!std::getline(std::cin, line)) {
        break;
      }
      run(line);
      hadError = false;
    }
}

void run(const std::string& source) {
  // Scanner scanner(source);
  // std::vector tokens = scanner.scanTokens();
  //
  // for (auto token : tokens) {
  //   std::cout << token
  // }
    std::cout << source << "\n";
}

void error(int line, std::string message&) {
  report(line, "", message)
}

void report(int line, std::string message&) {
  std::cout << "[line " << line << "] Error" << where << ": " << message << "\n";
  hadError = true;
}

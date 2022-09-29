#include "vector_strings.hpp"

#include <iostream>
#include <vector>

void Adder(std::vector<std::string>& names) {
  std::string s;
  std::cout << "Enter a name:" << std::endl;
  std::cin >> s;
  names.push_back(s);
  std::cout << "Number of names in the vector: " << names.size() << std::endl;
}

void Remover(std::vector<std::string>& names) {
  std::cout << "Removing the last element:" << std::endl;
  std::cout << names.back() << std::endl;
  names.pop_back();
}

void Printer(std::vector<std::string>& names) {
  for (const auto& s : names) {
    std::cout << s << std::endl;
  }
}

void CMDReader() {
  std::vector<std::string> names;
  while (true) {
    std::cout << "Commands: ADD, PRINT, REMOVE, QUIT" << std::endl;
    std::cout << "Enter a command:" << std::endl;
    std::string cmd;
    std::cin >> cmd;
    if (cmd == "ADD")
      Adder(names);
    else if (cmd == "REMOVE")
      Remover(names);
    else if (cmd == "PRINT")
      Printer(names);
    else if (cmd == "QUIT")
      return;
  }
}

#include "list.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

std::istream& GetLines(std::istream& is, std::list<std::string>& list) {
  list.clear();
  std::string s;
  do {
    std::getline(is, s);
    list.push_back(s);
  } while (is);
  return is;
}

void Print(const std::list<std::string>& list) {
  for (const auto& item : list) {
    std::cout << item << std::endl;
  }
}

void SortAndUnique(std::list<std::string>& list) {
  list.sort();
  list.unique();
}

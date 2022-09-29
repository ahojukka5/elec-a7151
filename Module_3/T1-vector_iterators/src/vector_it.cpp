#include "vector_it.hpp"

#include <iostream>
#include <vector>

// Implement the functions here

std::vector<int> ReadVector() {
  std::vector<int> v;
  int value;
  while (std::cin >> value) v.push_back(value);
  return v;
}

void PrintSum1(const std::vector<int>& v) {
  for (int i = 1, N = v.size(); i < N; i++) {
    std::cout << v[i - 1] + v[i] << " ";
  }
  std::cout << std::endl;
}

void PrintSum2(const std::vector<int>& v) {
  for (int i = 0, N = v.size() / 2; i < N; i++) {
    std::cout << v[i] + v[v.size() - 1 - i] << " ";
  }
  std::cout << std::endl;
}

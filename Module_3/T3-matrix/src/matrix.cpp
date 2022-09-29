#include "matrix.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

// Implement the functions here
// Remember to use auto and ranged for-loops when they can be used!

// Assumes 'm' is a square matrix
Matrix ReadMatrix(int n) {
  Matrix matrix(n);
  int value;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      std::cin >> value;
      matrix[j].push_back(value);
    }
  }
  return matrix;
}

Matrix Rotate90Deg(const Matrix &m) {
  Matrix n(m.size());
  for (int j = 0, M = m.size(); j < M; j++) {
    for (int i = 0, N = n.size(); i < N; i++) {
      n[j].push_back(m[i][j]);
    }
    std::reverse(n[j].begin(), n[j].end());
  }
  return n;
}

void Print(const Matrix &m) {
  int s = m.size();
  std::cout << "Printing out a " << s << " x " << s << " matrix:" << std::endl;
  for (int j = 0; j < s; j++) {
    for (int i = 0; i < s; i++) {
      std::cout << m[j][i] << " ";
    }
    std::cout << std::endl;
  }
}

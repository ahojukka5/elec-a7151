#include "vector.hpp"

#include <cmath>
#include <limits>
#include <vector>

int GetMin(std::vector<int> v) {
  int val = std::numeric_limits<int>::max();
  for (const int &a : v) val = std::min(val, a);
  return val;
}

int GetMax(std::vector<int> v) {
  int val = std::numeric_limits<int>::min();
  for (const int &a : v) val = std::max(val, a);
  return val;
}

double GetAvg(std::vector<int> v) {
  double val = 0.0;
  for (const int &a : v) val += a;
  return val / v.size();
}

#include "poly.hpp"

#include <sstream>

int Poly::operator[](int exp) const {
  auto it = values_.find(exp);
  return it == values_.end() ? 0 : it->second;
}

std::ostream &operator<<(std::ostream &os, const Poly &p) {
  bool first = true;
  for (auto item = p.rbegin(); item != p.rend(); item++) {
    auto [exp, mul] = *item;
    if (mul > 0 && !first) os << "+";
    os << mul << "x" << exp;
    first = false;
  }
  return os;
}

std::istream &operator>>(std::istream &is, Poly &p) {
  std::string polystring;
  is >> polystring;
  std::stringstream polystream(polystring);
  int mul, exp;
  char x;
  p -= p;
  while (polystream >> mul >> x >> exp) p[exp] = mul;
  return is;
}

Poly operator-(const Poly &p) {
  Poly c;
  for (auto [exp, mul] : p) c[exp] = -mul;
  return c;
}

Poly &Poly::operator+=(const Poly &b) {
  for (auto [exp, mul] : b) values_[exp] += mul;
  return *this;
}

Poly operator+(const Poly &a, const Poly &b) {
  Poly c = a;
  c += b;
  return c;
}

Poly &Poly::operator-=(const Poly &b) {
  for (auto [exp, mul] : b) values_[exp] -= mul;
  return *this;
}

Poly operator-(const Poly &a, const Poly &b) {
  Poly c = a;
  c -= b;
  return c;
}

bool operator==(const Poly &a, const Poly &b) {
  for (auto [exp, mul] : a) {
    if (a[exp] != b[exp]) return false;
  }
  return true;
}

bool operator!=(const Poly &a, const Poly &b) { return !(a == b); }

int get_order(const Poly &p) { return p.end()->first; }

bool operator<(const Poly &a, const Poly &b) {
  return get_order(a) < get_order(b);
}

bool operator>(const Poly &a, const Poly &b) {
  return get_order(a) > get_order(b);
}

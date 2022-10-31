#include "diagonal_printer.hpp"

DiagonalPrinter *DiagonalPrinter::Clone() const {
  return new DiagonalPrinter(first_, last_, os_);
}

StringPrinter &DiagonalPrinter::operator()(const std::string &str) {
  os_ << first_ << std::endl;
  for (int i = 0, N = str.size(); i < N; i++) {
    std::string line(N, ' ');
    line[i] = str[i];
    os_ << line << std::endl;
  }
  os_ << last_ << std::endl;
  return *this;
}

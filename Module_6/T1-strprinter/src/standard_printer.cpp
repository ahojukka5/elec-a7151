#include "standard_printer.hpp"

StringPrinter &StandardPrinter::operator()(const std::string &str) {
  this->os_ << str << std::endl;
  return *this;
}

StandardPrinter *StandardPrinter::Clone() const {
  return new StandardPrinter(this->os_);
}

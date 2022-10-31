#include "printers.hpp"

Printers::Printers(const Printers &printers) {
  for (auto [printer_name, printer] : printers.printers_) {
    Add(printer_name, printer->Clone());
  }
}

Printers::~Printers() {
  for (auto [printer_name, printer] : printers_) delete printer;
  printers_.clear();
}

void Printers::Add(std::string name, StringPrinter *printer) {
  if (printer == nullptr) throw std::invalid_argument("Invalid printer");
  if (printers_.count(name)) throw std::invalid_argument("Duplicate index");
  printers_[name] = printer;
}

StringPrinter &Printers::operator[](std::string name) {
  auto printer = printers_.find(name);
  if (printer == printers_.end()) throw std::invalid_argument("Unknown index");
  return *printer->second;
}

Printers &Printers::operator=(Printers &printers) {
  for (auto [printer_name, printer] : printers.printers_) {
    Add(printer_name, printer->Clone());
  }
  return *this;
}

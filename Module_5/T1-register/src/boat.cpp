#include "boat.hpp"

Boat::Boat(std::string register_number, std::string owner, std::string name,
           double draft, double power)
    : Vehicle(register_number, owner),
      name_(name),
      draft_(draft),
      power_(power) {}

void Boat::Write(std::ostream &stream) {
  stream << "B;" << GetRegisterNumber() << ";" << GetOwner() << ";" << name_
         << ";" << draft_ << ";" << power_ << std::endl;
}

void Boat::Print() { Write(std::cout); }

std::vector<std::string> BoatParseStream(std::istream &linestream, char sep) {
  std::vector<std::string> record;
  while (linestream) {
    std::string token;
    if (!std::getline(linestream, token, sep)) break;
    record.push_back(token);
  }
  return record;
}

Boat *Boat::Read(std::istream &stream) {
  auto a = BoatParseStream(stream, ';');
  return new Boat(a[1], a[2], a[3], std::stod(a[4]), std::stod(a[5]));
}

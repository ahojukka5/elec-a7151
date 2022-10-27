#include "aircraft.hpp"

Aircraft::Aircraft(std::string register_number, std::string owner,
                   std::string model, double wingspan,
                   unsigned int cruise_speed)
    : Vehicle(register_number, owner),
      model_(model),
      wingspan_(wingspan),
      cruise_speed_(cruise_speed) {}

void Aircraft::Write(std::ostream &os) {
  os << "A;" << GetRegisterNumber() << ";" << GetOwner() << ";" << model_ << ";"
     << wingspan_ << ";" << cruise_speed_ << std::endl;
}

void Aircraft::Print() { Write(std::cout); }

Aircraft *Aircraft::Read(std::istream &stream) {
  auto a = ParseStream(stream, ';');
  return new Aircraft(a[1], a[2], a[3], std::stod(a[4]), std::stoul(a[5]));
}

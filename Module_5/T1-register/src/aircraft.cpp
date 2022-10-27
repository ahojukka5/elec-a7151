#include "aircraft.hpp"

Aircraft::Aircraft(std::string register_number, std::string owner,
                   std::string model, double wingspan,
                   unsigned int cruise_speed)
    : Vehicle(register_number, owner),
      m_model(model),
      m_wingspan(wingspan),
      m_cruise_speed(cruise_speed) {}

void Aircraft::Write(std::ostream &os) {
  os << "A;" << GetRegisterNumber() << ";" << GetOwner() << ";" << m_model
     << ";" << m_wingspan << ";" << m_cruise_speed << std::endl;
}

void Aircraft::Print() { Write(std::cout); }

Aircraft *Aircraft::Read(std::istream &stream) {
  auto a = ParseStream(stream, ';');
  return new Aircraft(a[1], a[2], a[3], std::stod(a[4]), std::stoul(a[5]));
}

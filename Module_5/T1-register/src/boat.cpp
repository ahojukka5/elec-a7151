#include "boat.hpp"

Boat::Boat(std::string register_number, std::string owner, std::string name,
           double draft, double power)
    : Vehicle(register_number, owner),
      m_name(name),
      m_draft(draft),
      m_power(power) {}

void Boat::Write(std::ostream &stream) {
  stream << "B;" << GetRegisterNumber() << ";" << GetOwner() << ";" << m_name
         << ";" << m_draft << ";" << m_power << std::endl;
}

void Boat::Print() { Write(std::cout); }

Boat *Boat::Read(std::istream &stream) {
  auto a = ParseStream(stream, ';');
  return new Boat(a[1], a[2], a[3], std::stod(a[4]), std::stod(a[5]));
}

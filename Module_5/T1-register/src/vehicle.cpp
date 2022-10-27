#include "vehicle.hpp"

#include <iostream>
#include <sstream>
#include <vector>

Vehicle::Vehicle(std::string register_number, std::string owner)
    : m_register_number(register_number), m_owner(owner) {}

std::string Vehicle::GetRegisterNumber() const { return m_register_number; }

std::string Vehicle::GetOwner() const { return m_owner; }

std::vector<std::string> Vehicle::ParseStream(std::istream &linestream,
                                              char sep) {
  std::vector<std::string> record;
  while (linestream) {
    std::string token;
    if (!std::getline(linestream, token, sep)) break;
    record.push_back(token);
  }
  return record;
}

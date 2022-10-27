#include "vehicle.hpp"

#include <iostream>
#include <sstream>
#include <vector>

Vehicle::Vehicle(std::string register_number, std::string owner)
    : register_number_(register_number), owner_(owner) {}

std::string Vehicle::GetRegisterNumber() const { return register_number_; }

std::string Vehicle::GetOwner() const { return owner_; }

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

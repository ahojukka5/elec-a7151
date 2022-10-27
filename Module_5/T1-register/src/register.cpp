#include "register.hpp"

#include <fstream>
#include <sstream>

#include "aircraft.hpp"
#include "boat.hpp"

Register::~Register() {
  for (auto vehicle : m_vehicles) delete vehicle;
  m_vehicles.clear();
}

void Register::Add(Vehicle *vehicle) {
  if (vehicle != nullptr) m_vehicles.push_back(vehicle);
}

void Register::Save(const std::string &filename) const {
  std::ofstream os(filename);
  for (auto vehicle : m_vehicles) {
    vehicle->Write(os);
  }
  os.close();
}

bool Register::ReadLine(std::istream &stream) {
  if (!stream) {
    stream.clear((stream.rdstate() & ~std::ios::goodbit) | std::ios::failbit);
    return false;
  }
  std::string line;
  if (!std::getline(stream, line)) return false;
  std::istringstream linestream(line);
  switch (line[0]) {
    case 'A':
      Add(Aircraft::Read(linestream));
      return true;
    case 'B':
      Add(Boat::Read(linestream));
      return true;
    default:
      return false;
  }
}

int Register::Load(const std::string &filename) {
  std::ifstream stream(filename);
  if (stream.rdstate() & (stream.failbit | stream.badbit)) return -1;
  int count = 0;
  while (!stream.eof()) {
    if (ReadLine(stream)) count++;
  }
  return count;
}

void Register::Print() {
  for (auto vehicle : m_vehicles) vehicle->Print();
}

size_t Register::Size() const { return m_vehicles.size(); }

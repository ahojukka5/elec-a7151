#include "dragon.hpp"

Dragon::Dragon(const std::string &name, size_t age, size_t size)
    : m_name(name), m_age(age), m_size(size) {}

const std::string &Dragon::GetName() const { return m_name; }
size_t Dragon::GetAge() const { return m_age; }
size_t Dragon::GetSize() const { return m_size; }
const std::list<Treasure> &Dragon::GetTreasures() const { return m_treasures; }

std::ostream &operator<<(std::ostream &os, const Dragon &cave) {
  os << "Dragon named: " << cave.GetName() << ", age: " << cave.GetAge()
     << ", size: " << cave.GetSize() << std::endl;
  os << "Treasures:" << std::endl;
  for (const auto treasure : cave.GetTreasures()) {
    os << treasure.name << std::endl;
  }
  return os;
}

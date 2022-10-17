#include "dragon_cave.hpp"

DragonCave::~DragonCave() {
  for (const auto& dragon : m_dragons) {
    delete dragon;
  }
  // m_dragons.clear();
}

const std::list<Dragon*>& DragonCave::GetDragons() const { return m_dragons; }

void DragonCave::Accommodate(Dragon* dragon) { m_dragons.push_back(dragon); }

void DragonCave::Evict(const std::string& name) {
  for (auto dragon = m_dragons.begin(); dragon != m_dragons.end(); dragon++) {
    if ((*dragon)->GetName() == name) {
      m_dragons.erase(dragon);
      return;
    }
  }
}

std::ostream& operator<<(std::ostream& out, const DragonCave& dc) {
  out << "DragonCave dwellers:" << std::endl;
  for (const auto& dragon : dc.GetDragons()) {
    out << std::endl << *dragon;
  }
  return out;
}

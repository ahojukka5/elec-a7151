#include "aviary.hpp"

template <class T>
inline void check_bounds(std::vector<T> v, size_t i) {
  if (i >= v.size()) {
    throw std::out_of_range("not enough birds!");
  }
}

void Aviary::Add(Bird* bird) {
  if (bird) {
    m_birds.push_back(bird);
  } else {
    throw std::logic_error("bird died");
  }
}

void Aviary::SpeakAll(std::ostream& os) const {
  for (const auto& bird : m_birds) {
    bird->Speak(os);
  }
}

size_t Aviary::Size() const { return m_birds.size(); }

const Bird* Aviary::operator[](size_t idx) const {
  check_bounds(m_birds, idx);
  return m_birds[idx];
}

Bird* Aviary::operator[](size_t idx) {
  check_bounds(m_birds, idx);
  return m_birds[idx];
}

Aviary::~Aviary() {
  for (const auto& bird : m_birds) {
    delete bird;
  }
}

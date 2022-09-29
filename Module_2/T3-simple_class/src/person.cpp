#include "person.hpp"

class Person {
 private:
  const std::string &m_name;
  const int m_birth_year;

 public:
  Person(const std::string &name, int birth_year)
      : m_name(name), m_birth_year(birth_year) {}
  const std::string &GetName() const { return m_name; }
  int GetAge(int year) const { return year - m_birth_year; };
};

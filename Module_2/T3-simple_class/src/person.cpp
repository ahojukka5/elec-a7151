#include "person.hpp"

Person::Person(const std::string &name, int birth_year)
    : m_name(name), m_birth_year(birth_year) {}

const std::string &Person::GetName() const { return m_name; }

int Person::GetAge(int year) const { return year - m_birth_year; };

#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON

#include <iostream>

class Person {
 private:
  const std::string &m_name;
  const int m_birth_year;

 public:
  Person(const std::string &name, int birth_year);
  const std::string &GetName() const;
  int GetAge(int year) const;
};

#endif

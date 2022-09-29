#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON

#include <iostream>

class Person {
 public:
  Person(const std::string &name, int birth_year);
  const std::string &GetName() const;
  int GetAge() const;
};

#endif

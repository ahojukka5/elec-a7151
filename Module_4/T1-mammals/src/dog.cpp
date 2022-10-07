#include "dog.hpp"

Dog::Dog(const std::string &name, int weight) : Mammal(weight), name_(name) {}
const std::string &Dog::GetName() const { return name_; }
std::string Dog::MakeSound() { return "Wuff!"; }

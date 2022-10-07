#include "cat.hpp"

Cat::Cat(const std::string &name, int weight) : Mammal(weight), name_(name) {}
const std::string &Cat::GetName() const { return name_; }
std::string Cat::MakeSound() { return "Meow"; }

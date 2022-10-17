#include "magic_dragon.hpp"

MagicDragon::MagicDragon(const std::string &name, size_t age, size_t size)
    : Dragon(name, age, size) {}

MagicDragon::~MagicDragon() {}

void MagicDragon::Eat(std::list<Food> &foods) {
  for (auto food = foods.begin(); food != foods.end();) {
    if (food->type == Herbs) {
      m_size++;
      std::cout << "Magic dragon ate: " << food->name << std::endl;
      food = foods.erase(food);
    } else {
      ++food;
    }
  }
}

void MagicDragon::Hoard(std::list<Treasure> &treasures) {
  for (auto treasure = treasures.begin(); treasure != treasures.end();) {
    if (treasure->type == Potions) {
      m_treasures.push_back(*treasure);
      std::cout << "Magic dragon received: " << treasure->name << std::endl;
      treasure = treasures.erase(treasure);
    } else {
      ++treasure;
    }
  }
}

#include "fantasy_dragon.hpp"

FantasyDragon::FantasyDragon(const std::string& name, size_t age, size_t size)
    : Dragon(name, age, size) {}

FantasyDragon::~FantasyDragon() {}

void FantasyDragon::Eat(std::list<Food>& foods) {
  for (auto food = foods.begin(); food != foods.end();) {
    if ((food->type == People) || (food->type == PeopleFood)) {
      m_size++;
      std::cout << "Fantasy dragon ate: " << food->name << std::endl;
      food = foods.erase(food);
    } else {
      ++food;
    }
  }
}

void FantasyDragon::Hoard(std::list<Treasure>& treasures) {
  for (auto treasure = treasures.begin(); treasure != treasures.end();) {
    if (treasure->type == Jewellery) {
      m_treasures.push_back(*treasure);
      std::cout << "Fantasy dragon received: " << treasure->name << std::endl;
      treasure = treasures.erase(treasure);
    } else {
      ++treasure;
    }
  }
}

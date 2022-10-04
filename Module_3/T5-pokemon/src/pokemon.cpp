#include "pokemon.hpp"

#include <algorithm>

using Pokemon = std::pair<std::string, size_t>;

PokemonCollection::PokemonCollection(PokemonCollection collection,
                                     PokemonCollection collection2) {
  for (const auto &p : collection) Add(p.first, p.second);
  for (const auto &p : collection2) Add(p.first, p.second);
  pokemons_.sort();
  pokemons_.unique();
}

void PokemonCollection::Add(const std::string &name, size_t id) {
  pokemons_.push_back({name, id});
}

bool PokemonCollection::Remove(const std::string &name, size_t id) {
  auto poke = Pokemon(name, id);
  auto it = std::find(pokemons_.begin(), pokemons_.end(), poke);
  bool found = it != pokemons_.end();
  if (found) pokemons_.remove(poke);
  return found;
}

void PokemonCollection::Print() const {
  for (const auto &p : pokemons_) {
    std::cout << "id: " << p.first << ", name: " << p.second << std::endl;
  }
}

bool byName(const Pokemon &A, const Pokemon &B) { return A.first < B.first; }
bool byId(const Pokemon &A, const Pokemon &B) { return A.second < B.second; }
void PokemonCollection::SortByName() { pokemons_.sort(byName); }
void PokemonCollection::SortById() { pokemons_.sort(byId); }

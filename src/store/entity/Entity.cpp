#include "Entity.hpp"
#include <functional>

Entity &Entity::setId(unsigned long id) {
  this->id = id;
  return *this;
}

unsigned long Entity::getId() const { return id; }

bool Entity::operator==(Entity const &other) const { return id == other.id; }

std::size_t Entity::Hash::operator()(Entity const &entity) const {
  return std::hash<unsigned long>()(entity.getId());
}
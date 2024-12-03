#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <cstddef>

unsigned long const constexpr INITIAL_ID = 0; ///< The initial id of the entity

/**
 * @class Entity
 *
 * @brief Abstract class that represents an entity.
 *
 * @details This class is used as a base class for all entities in the system.
 * It provides a unique identifier for each entity.
 */
class Entity {
protected:
  unsigned long id;

public:
  /**
   * @brief Sets the id of the entity.
   *
   * @param id the identifier of the entity.
   * @return a reference to the entity.
   */
  Entity &setId(unsigned long id);

  /**
   * @brief Gets the id of the entity.
   *
   * @return the identifier of the entity.
   */
  unsigned long getId() const;

  /**
   * @brief Equality operator for Entity.
   *
   * @param other The other Entity to compare with.
   * @return true if both entities have the same id, false otherwise.
   */
  bool operator==(Entity const &other) const;

  /**
   * @brief Hash function for Entity.
   *
   * @details This function is used to insert the Entity into an unordered
   * container.
   *
   * @param entity The Entity to be hashed.
   * @return The hash value of the entity.
   */
  struct Hash {
    std::size_t operator()(Entity const &entity) const;
  };
};

#endif // ENTITY_HPP_
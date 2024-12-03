#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_

#include "Entity.hpp"
#include <string>

float const constexpr MINIMUM_PRICE = 0; ///< The minimum price of a product

/**
 * @class Product
 *
 * @brief Class that represents a product.
 *
 * @details This class is used to represent a product.
 * It provides the name and price of the product.
 */
class Product : public Entity {
private:
  std::string name;
  float price;

public:
  /**
   * @brief Constructor.
   *
   * @param name the name of the product.
   * @param price the price of the product.
   */
  Product(std::string const &name, float price);

  /**
   * @brief Destructor.
   */
  ~Product();

  /**
   * @brief Gets the name of the product.
   *
   * @return the name of the product.
   */
  std::string getName() const;

  /**
   * @brief Gets the price of the product.
   *
   * @return the price of the product.
   */
  float getPrice() const;

  /**
   * @brief Sets the name of the product.
   *
   * @param name the name of the product.
   * @return a reference to the product.
   *
   * @throw std::invalid_argument if the name is empty.
   */
  Product &setName(std::string const &name);

  /**
   * @brief Sets the price of the product.
   *
   * @param price the price of the product.
   * @return a reference to the product.
   *
   * @throw std::invalid_argument if the price is less than the minimum price.
   */
  Product &setPrice(float price);

  /**
   * @brief Equality operator for Product.
   *
   * @param other The other Entity to compare with.
   * @return true if both products have the same name and price, false
   * otherwise.
   */
  bool operator==(Entity const &other) const override;
};

#endif // PRODUCT_HPP_
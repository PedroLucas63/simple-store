#ifndef ORDER_HPP_
#define ORDER_HPP_

#include "Product.hpp"
#include <string>
#include <unordered_map>

float const constexpr INITIAL_TOTAL_PRICE =
    0.0f; ///< The initial total price of the order
float const constexpr PRICE_TO_DISCOUNT =
    100.0f; ///< The minimum price to apply the discount
float const constexpr DISCOUNT = 0.1f; ///< The discount to apply
unsigned const constexpr INITIAL_QUANTITY =
    1; ///< The initial quantity of a product

/**
 * @class Order
 *
 * @brief Class that represents an order.
 *
 * @details This class is used to represent an order.
 * It provides the client name, total price and order items of the order.
 */
class Order : public Entity {
private:
  using OrderMap = std::unordered_map<Product, unsigned, Product::Hash>;

  std::string clientName;
  float totalPrice;
  OrderMap orderItems;

  /**
   * @brief Calculates the total price with discount.
   *
   * @return the total price with discount.
   */
  float calculatePriceWithDiscount() const;

  /**
   * @brief Adds a product quantity to the order.
   *
   * @param product the product to be added.
   * @param quantity the quantity of the product to be added.
   */
  void addProductQuantify(Product const &product, unsigned quantity);

  /**
   * @brief Removes a product quantity from the order.
   *
   * @param product the product to be removed.
   * @param quantity the quantity of the product to be removed.
   */
  void removeProductQuantify(Product const &product, unsigned quantity);

public:
  /**
   * @brief Constructs an Order with the given client name.
   *
   * @param clientName The name of the client.
   */
  Order(std::string const &clientName);

  /**
   * @brief Destructor for the Order.
   */
  ~Order();

  /**
   * @brief Gets the client's name for the order.
   *
   * @return The client name.
   */
  std::string getClientName() const;

  /**
   * @brief Gets the total price of the order.
   *
   * @return The total price after applicable discounts.
   */
  float getTotalPrice() const;

  /**
   * @brief Gets the list of order items.
   *
   * @return The order items.
   */
  OrderMap getOrderItems() const;

  /**
   * @brief Sets the client's name for the order.
   *
   * @param clientName The name of the client.
   * @return A reference to the order.
   *
   * @throw std::invalid_argument if the name is empty.
   */
  Order &setClientName(std::string const &clientName);

  /**
   * @brief Adds a product to the order with the specified quantity.
   *
   * @param product The product to add.
   * @param quantity The quantity of the product.
   * @return A reference to the order.
   */
  Order &addProduct(Product const &product, unsigned quantity);

  /**
   * @brief Removes a specified quantity of a product from the order.
   *
   * @param product The product to remove.
   * @param quantity The quantity to remove.
   * @return A reference to the order.
   */
  Order &removeProduct(Product const &product, unsigned quantity);

  /**
   * @brief Equality operator for Order.
   *
   * @param other The other Order to compare with.
   * @return true if both orders have the same id, false otherwise.
   */
  bool operator==(Entity const &other) const override;
};

#endif // ORDER_HPP_
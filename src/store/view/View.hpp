#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "../entity/Order.hpp"
#include "../entity/Product.hpp"
#include <unordered_map>
#include <vector>

/**
 * @class View
 *
 * @brief Class responsible for the user interface.
 *
 * @details This class is responsible for displaying the user interface.
 */
class View {
public:
  /**
   * @brief Displays the main menu.
   *
   * @details Prints the main menu to the console.
   */
  static void menu();

  /**
   * @brief Prints a product.
   *
   * @details Prints the product information to the console.
   *
   * @param product The product to print.
   */
  static void printProduct(Product const &product);

  /**
   * @brief Prints a map of products.
   *
   * @details Prints all products information from the given map to the console.
   *
   * @param products The map of products to print.
   */
  static void
  printProducts(std::unordered_map<unsigned long, Product> const &products);

  /**
   * @brief Prints an order.
   *
   * @details Prints the order information to the console.
   *
   * @param order The order to print.
   */
  static void printOrder(Order const &order);

  /**
   * @brief Prints a vector of orders.
   *
   * @details Prints all orders information from the given vector to the
   * console.
   *
   * @param orders The vector of orders to print.
   */
  static void printOrders(std::vector<Order> const &orders);
};

#endif // VIEW_HPP_
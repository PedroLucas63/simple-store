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

  static void printProduct(Product const &product);

  static void
  printProducts(std::unordered_map<unsigned long, Product> const &products);

  static void printOrder(Order const &order);
  static void printOrders(std::vector<Order> const &orders);
};

#endif // VIEW_HPP_
/**
 * @mainpage Store
 * @author Pedro Lucas Medeiros do Nascimento
 * @date 2024
 * @brief A simple store system.
 *
 * This is a simple store system that allows the user to add, remove and view
 * products and orders.
 *
 * The system uses a console-based interface to interact with the user.
 *
 * The system is composed of the following components:
 * - @link store::AppController AppController @endlink: The main class of the
 * system.
 * - @link store::Catalog Catalog @endlink: The class responsible for managing
 * the products.
 * - @link store::Product Product @endlink: The class that represents a product.
 * - @link store::Order Order @endlink: The class that represents an order.
 */
#include "store/AppController.hpp"
#include <iostream>

int main(int, char **) {
  AppController &app = AppController::getInstance();
  app.initialize();

  while (!app.exit()) {
    app.process();
    app.update();
    app.render();
  }

  app.deleteInstance();

  return EXIT_SUCCESS;
}

#include "View.hpp"
#include <iostream>

void View::menu() {
  std::cout << std::string(80, '-') << std::endl;
  std::cout << "Welcome to the store!" << std::endl;
  std::cout << std::string(80, '-') << std::endl;
  std::cout << "1. Add product" << std::endl;
  std::cout << "2. Remove product" << std::endl;
  std::cout << "3. List products" << std::endl;
  std::cout << "4. Get product by id" << std::endl;
  std::cout << "5. Add order" << std::endl;
  std::cout << "6. List orders" << std::endl;
  std::cout << "7. Exit" << std::endl;
  std::cout << std::string(80, '-') << std::endl;
  std::cout << "Enter your choice: ";
}

void View::printProduct(Product const &product) {
  std::cout << "Id: " << product.getId() << std::endl;
  std::cout << "Name: " << product.getName() << std::endl;
  std::cout << "Price: $" << product.getPrice() << std::endl;
}

void View::printProducts(
    std::unordered_map<unsigned long, Product> const &products) {
  std::cout << std::string(80, '-') << std::endl;
  std::cout << "Products:" << std::endl;
  std::cout << std::string(80, '-') << std::endl;

  if (products.empty()) {
    std::cout << "No products found" << std::endl;
    return;
  }

  for (auto const &[id, product] : products) {
    printProduct(product);
    std::cout << std::string(80, '-') << std::endl;
  }
}

void View::printOrder(Order const &order) {
  std::cout << "Id: " << order.getId() << std::endl;
  std::cout << "Client name: " << order.getClientName() << std::endl;
  std::cout << "Total price: $" << order.getTotalPrice() << std::endl;
}

void View::printOrders(std::vector<Order> const &orders) {
  std::cout << std::string(80, '-') << std::endl;
  std::cout << "Orders:" << std::endl;
  std::cout << std::string(80, '-') << std::endl;

  if (orders.empty()) {
    std::cout << "No orders found" << std::endl;
    return;
  }

  for (auto const &order : orders) {
    printOrder(order);
    std::cout << std::string(80, '-') << std::endl;
  }
}

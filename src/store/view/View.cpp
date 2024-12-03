#include "View.hpp"
#include <iostream>

void View::menu() {
  std::cout << std::string(80, '-') << std::endl;
  std::cout << "Welcome to the store!" << std::endl;
  std::cout << std::string(80, '-') << std::endl;
  std::cout << "1. Add product" << std::endl;
  std::cout << "2. Remove product" << std::endl;
  std::cout << "3. List products" << std::endl;
  std::cout << "4. Add order" << std::endl;
  std::cout << "5. Remove order" << std::endl;
  std::cout << "6. List orders" << std::endl;
  std::cout << "7. Exit" << std::endl;
  std::cout << std::string(80, '-') << std::endl;
  std::cout << "Enter your choice: ";
}

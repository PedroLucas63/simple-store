#include "Product.hpp"
#include <stdexcept>

Product::Product(std::string const &name, float price) {
  setName(name);
  setPrice(price);
}

Product::~Product() = default;

std::string Product::getName() const { return name; }
float Product::getPrice() const { return price; }

Product &Product::setName(std::string const &name) {
  if (name.empty()) {
    throw std::invalid_argument("Invalid name");
  }

  this->name = name;
  return *this;
}

Product &Product::setPrice(float price) {
  if (price < MINIMUM_PRICE) {
    throw std::invalid_argument("Invalid price");
  }

  this->price = price;
  return *this;
}
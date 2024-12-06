#include "Order.hpp"
#include <spdlog/spdlog.h>
#include <stdexcept>

Order::Order(std::string const &clientName) : totalPrice(INITIAL_TOTAL_PRICE) {
  setClientName(clientName);
}
Order::~Order() = default;

std::string Order::getClientName() const { return clientName; }
float Order::getTotalPrice() const { return calculatePriceWithDiscount(); }
Order::OrderMap Order::getOrderItems() const { return orderItems; }

Order &Order::setClientName(std::string const &clientName) {
  if (clientName.empty()) {
    throw std::invalid_argument("Invalid name");
  }

  this->clientName = clientName;
  return *this;
}

Order &Order::addProduct(Product const &product, unsigned quantity) {
  addProductQuantify(product, quantity);
  return *this;
}

Order &Order::removeProduct(Product const &product, unsigned quantity) {
  removeProductQuantify(product, quantity);
  return *this;
}

float Order::calculatePriceWithDiscount() const {
  spdlog::debug("Calculating price with discount: {}", totalPrice);
  if (totalPrice > PRICE_TO_DISCOUNT) {
    return totalPrice * (1 - DISCOUNT);
  } else {
    return totalPrice;
  }
}

void Order::addProductQuantify(Product const &product, unsigned quantity) {
  if (quantity < INITIAL_QUANTITY) {
    throw std::invalid_argument("Invalid quantity");
  }

  if (orderItems.find(product) == orderItems.end()) {
    orderItems[product] = quantity;
  } else {
    orderItems[product] += quantity;
  }

  totalPrice += product.getPrice() * quantity;
}

void Order::removeProductQuantify(Product const &product, unsigned quantity) {
  unsigned itemQuantity = orderItems[product];

  if (quantity < itemQuantity) {
    orderItems[product] -= quantity;
    totalPrice -= product.getPrice() * quantity;
  } else {
    totalPrice -= product.getPrice() * itemQuantity;
    orderItems.erase(product);
  }
}

bool Order::operator==(Entity const &other) const {
  if (typeid(*this) == typeid(other)) {
    Order const &otherOrder = static_cast<Order const &>(other);

    return id == otherOrder.id && clientName == otherOrder.clientName &&
           orderItems == otherOrder.orderItems;
  }

  return false;
}
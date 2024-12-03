#include "../src/store/entity/Order.hpp"
#include <gtest/gtest.h>

TEST(OrderTest, Constructor) {
  Order order("John Doe");
  EXPECT_EQ(order.getClientName(), "John Doe");
  EXPECT_EQ(order.getTotalPrice(), 0.0f);
}

TEST(OrderTest, SetClientName) {
  Order order("John Doe");
  order.setClientName("Jane Doe");
  EXPECT_EQ(order.getClientName(), "Jane Doe");

  EXPECT_THROW(order.setClientName(""), std::invalid_argument);
}

TEST(OrderTest, GetTotalPrice) {
  Order order("John Doe");
  Product product1 = Product("Smartphone", 10.0f);
  Product product2 = Product("Tablet", 5.0f);

  order.addProduct(product1, 4);
  EXPECT_EQ(order.getTotalPrice(), 40.0f);

  order.addProduct(product2, 3);
  EXPECT_EQ(order.getTotalPrice(), 55.0f);

  order.addProduct(product1, 4);
  EXPECT_EQ(order.getTotalPrice(), 95.0f);

  order.addProduct(product2, 3);
  EXPECT_EQ(order.getTotalPrice(), 99.0f);

  order.removeProduct(product1, 2);
  EXPECT_EQ(order.getTotalPrice(), 90.0f);

  order.removeProduct(product2, 3);
  EXPECT_EQ(order.getTotalPrice(), 75.0f);

  order.addProduct(product2, 5);
  EXPECT_EQ(order.getTotalPrice(), 100.0f);
}

TEST(OrderTest, AddProduct) {
  Order order("John Doe");
  Product product1("Smartphone", 10.0f);
  Product product2("Tablet", 5.0f);

  order.addProduct(product1, 2);
  auto orderItems = order.getOrderItems();
  auto it = orderItems.find(product1);

  EXPECT_EQ(orderItems.size(), 1);
  EXPECT_EQ(it->first, product1);
  EXPECT_EQ(it->second, 2);

  order.addProduct(product2, 3);
  orderItems = order.getOrderItems();
  it = orderItems.find(product2);

  EXPECT_EQ(orderItems.size(), 2);
  EXPECT_EQ(it->first, product2);
  EXPECT_EQ(it->second, 3);

  order.addProduct(product1, 2);
  orderItems = order.getOrderItems();
  it = orderItems.find(product1);

  EXPECT_EQ(orderItems.size(), 2);
  EXPECT_EQ(it->first, product1);
  EXPECT_EQ(it->second, 4);

  EXPECT_THROW(order.addProduct(product1, 0), std::invalid_argument);
}

TEST(OrderTest, RemoveProduct) {
  Order order("John Doe");
  Product product1("Smartphone", 10.0f);
  Product product2("Tablet", 5.0f);

  order.addProduct(product1, 2);
  order.addProduct(product2, 3);

  order.removeProduct(product1, 2);
  auto orderItems = order.getOrderItems();
  auto it = orderItems.find(product1);

  EXPECT_EQ(orderItems.size(), 1);
  EXPECT_EQ(it, orderItems.end());

  order.removeProduct(product2, 2);
  orderItems = order.getOrderItems();
  it = orderItems.find(product2);

  EXPECT_EQ(orderItems.size(), 1);
  EXPECT_EQ(it->first, product2);
  EXPECT_EQ(it->second, 1);
}
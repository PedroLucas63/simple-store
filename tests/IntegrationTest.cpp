#include "../src/store/entity/Order.hpp"
#include "../src/store/entity/Product.hpp"
#include "../src/store/service/Catalog.hpp"
#include <gtest/gtest.h>

TEST(IntegrationTest, AddProductToOrder) {
  Catalog catalog;
  Product product1("Smartphone", 10.0f);
  Product product2("Tablet", 5.0f);
  Product product3("Laptop", 20.0f);

  product1.setId(catalog.addProduct(product1));
  product2.setId(catalog.addProduct(product2));
  product3.setId(catalog.addProduct(product3));

  Order order("John Doe");
  order.addProduct(catalog.getProductById(product1.getId()), 4);
  order.addProduct(catalog.getProductById(product2.getId()), 3);
  order.addProduct(catalog.getProductById(product3.getId()), 2);

  EXPECT_EQ(order.getTotalPrice(), 95.0f);

  order.removeProduct(catalog.getProductById(product1.getId()), 2);

  EXPECT_EQ(order.getTotalPrice(), 75.0f);
}

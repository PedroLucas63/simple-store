#include "../src/store/entity/Product.hpp"
#include <gtest/gtest.h>

TEST(ProductTest, Constructor) {
  Product product("Smartphone", 10.0f);
  EXPECT_EQ(product.getName(), "Smartphone");
  EXPECT_EQ(product.getPrice(), 10.0f);
}

TEST(ProductTest, SetName) {
  Product product("Smartphone", 10.0f);
  product.setName("Tablet");
  EXPECT_EQ(product.getName(), "Tablet");

  EXPECT_THROW(product.setName(""), std::invalid_argument);
}

TEST(ProductTest, SetPrice) {
  Product product("Smartphone", 10.0f);
  product.setPrice(20.0f);
  EXPECT_EQ(product.getPrice(), 20.0f);

  EXPECT_THROW(product.setPrice(-1.0f), std::invalid_argument);
}
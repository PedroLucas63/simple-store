#include "../src/store/service/Catalog.hpp"
#include <gtest/gtest.h>

TEST(CatalogTest, Constructor) {
  Catalog catalog;
  EXPECT_EQ(catalog.getProducts().size(), 0);
}

TEST(CatalogTest, AddProduct) {
  Catalog catalog;
  Product product1("Smartphone", 10.0f);
  Product product2("Tablet", 5.0f);

  product1.setId(catalog.addProduct(product1));
  auto catalogItems = catalog.getProducts();
  auto it = catalogItems.find(product1.getId());

  EXPECT_EQ(catalog.getProducts().size(), 1);
  EXPECT_NE(it, catalogItems.end());
  EXPECT_EQ(it->first, product1.getId());
  EXPECT_EQ(it->second, product1);

  product2.setId(catalog.addProduct(product2));
  catalogItems = catalog.getProducts();
  it = catalogItems.find(product2.getId());

  EXPECT_EQ(catalog.getProducts().size(), 2);
  EXPECT_NE(it, catalogItems.end());
  EXPECT_EQ(it->first, product2.getId());
  EXPECT_EQ(it->second, product2);
}

TEST(CatalogTest, GetProductById) {
  Catalog catalog;
  Product product1("Smartphone", 10.0f);
  Product product2("Tablet", 5.0f);

  product1.setId(catalog.addProduct(product1));
  product2.setId(catalog.addProduct(product2));

  EXPECT_EQ(catalog.getProductById(product1.getId()), product1);
  EXPECT_EQ(catalog.getProductById(product2.getId()), product2);

  EXPECT_THROW(catalog.getProductById(product2.getId() + 1),
               std::runtime_error);

  catalog.deleteProduct(product1.getId());
  EXPECT_THROW(catalog.getProductById(product1.getId()), std::runtime_error);
}

TEST(CatalogTest, UpdateProduct) {
  Catalog catalog;
  Product product1("Smartphone", 10.0f);
  Product product2("Tablet", 5.0f);

  product1.setId(catalog.addProduct(product1));
  product2.setId(catalog.addProduct(product2));

  EXPECT_EQ(catalog.getProductById(product1.getId()), product1);
  EXPECT_EQ(catalog.getProductById(product2.getId()), product2);

  product1.setPrice(20.0f);
  catalog.updateProduct(product1);
  EXPECT_EQ(catalog.getProductById(product1.getId()), product1);

  product2.setPrice(15.0f);
  catalog.updateProduct(product2);
  EXPECT_EQ(catalog.getProductById(product2.getId()), product2);

  catalog.deleteProduct(product1.getId());
  EXPECT_THROW(catalog.updateProduct(product1), std::runtime_error);
}

TEST(CatalogTest, DeleteProduct) {
  Catalog catalog;
  Product product1("Smartphone", 10.0f);
  Product product2("Tablet", 5.0f);

  product1.setId(catalog.addProduct(product1));
  product2.setId(catalog.addProduct(product2));

  EXPECT_EQ(catalog.getProducts().size(), 2);

  catalog.deleteProduct(product1.getId());
  EXPECT_EQ(catalog.getProducts().size(), 1);

  catalog.deleteProduct(product2.getId());
  EXPECT_EQ(catalog.getProducts().size(), 0);
}
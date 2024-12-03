#include "Catalog.hpp"
#include <stdexcept>

Catalog::Catalog() : currentId(INITIAL_ID) {}
Catalog::~Catalog() = default;

Catalog &Catalog::addProduct(Product product) {
  product.setId(currentId++);
  products.emplace(product.getId(), product);

  return *this;
}

Catalog::CatalogMap Catalog::getProducts() const { return products; }
Product Catalog::getProductById(unsigned long id) const {
  if (products.contains(id)) {
    return products.at(id);
  } else {
    throw std::runtime_error("Product not found");
  }
}

Catalog &Catalog::updateProduct(unsigned long id, Product product) {
  products.erase(id);
  addProduct(product);

  return *this;
}

Catalog &Catalog::deleteProduct(unsigned long id) {
  products.erase(id);
  return *this;
}
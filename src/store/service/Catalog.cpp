#include "Catalog.hpp"
#include <stdexcept>

Catalog::Catalog() : currentId(INITIAL_ID) {}
Catalog::~Catalog() = default;

unsigned long Catalog::addProduct(Product const &product) {
  Product newProduct(product);
  newProduct.setId(currentId++);

  products.emplace(newProduct.getId(), newProduct);

  return newProduct.getId();
}

Catalog::CatalogMap Catalog::getProducts() const { return products; }
Product Catalog::getProductById(unsigned long id) const {
  if (products.contains(id)) {
    return products.at(id);
  } else {
    throw std::runtime_error("Product not found");
  }
}

Catalog &Catalog::updateProduct(Product const &product) {
  if (!products.contains(product.getId())) {
    throw std::runtime_error("Product not found");
  }

  products.insert_or_assign(product.getId(), product);

  return *this;
}

Catalog &Catalog::deleteProduct(unsigned long id) {
  products.erase(id);
  return *this;
}

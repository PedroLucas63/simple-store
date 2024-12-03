#ifndef CATALOG_HPP_
#define CATALOG_HPP_

#include "../entity/Product.hpp"
#include <unordered_map>

/**
 * @class Catalog
 *
 * @brief Class that represents a catalog.
 *
 * @details This class is used to represent a catalog.
 * It provides the products of the catalog and allows to add, update and remove
 * products.
 */
class Catalog {
private:
  using CatalogMap = std::unordered_map<unsigned long, Product>;

  CatalogMap products;
  unsigned long currentId;

public:
  /**
   * @brief Constructs a Catalog.
   */
  Catalog();

  /**
   * @brief Destructor for the Catalog.
   */
  ~Catalog();

  /**
   * @brief Adds a product to the catalog.
   *
   * @param product The product to add.
   * @return A reference to the catalog.
   */
  Catalog &addProduct(Product product);

  /**
   * @brief Retrieves all products in the catalog.
   *
   * @return A map of products with their IDs.
   */
  CatalogMap getProducts() const;

  /**
   * @brief Retrieves a product by its ID.
   *
   * @param id The ID of the product.
   * @return The product with the specified ID.
   *
   * @throw std::runtime_error if the product is not found.
   */
  Product getProductById(unsigned long id) const;

  /**
   * @brief Updates a product in the catalog.
   *
   * @param id The ID of the product to update.
   * @param product The updated product.
   * @return A reference to the catalog.
   */
  Catalog &updateProduct(unsigned long id, Product product);

  /**
   * @brief Deletes a product from the catalog.
   *
   * @param id The ID of the product to delete.
   * @return A reference to the catalog.
   */
  Catalog &deleteProduct(unsigned long id);
};

#endif // CATALOG_HPP_

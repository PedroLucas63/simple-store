#ifndef APPCONTROLLER_HPP_
#define APPCONTROLLER_HPP_

#include "entity/Order.hpp"
#include "service/Catalog.hpp"
#include <vector>

/**
 * @class AppController
 *
 * @brief Class that controls the program flow.
 *
 * @details This class is responsible for controlling the program flow.
 * It provides the methods to interact with the user and the data storage.
 */
class AppController {
private:
  enum State {
    Starting,
    Menu,
    AddProduct,
    RemoveProduct,
    ListProducts,
    GetProductById,
    ViewProduct,
    AddOrder,
    ListOrders,
    Ending,
  };

  static AppController *instance;

  Catalog catalog;
  unsigned long currentOrderId;
  std::vector<Order> orders;

  State state;
  int menuOption;
  long unsigned productId;

  /**
   * @brief Default constructor.
   */
  AppController();

  /**
   * @brief Destructor.
   */
  ~AppController();

  /**
   * @brief Gets the option from the menu.
   */
  void getMenuOption();

  /**
   * @brief Adds a product to the catalog.
   */
  void addProduct();

  /**
   * @brief Removes a product from the catalog.
   */
  void removeProduct();

  /**
   * @brief Retrieves a product by its id from the catalog.
   */
  void getProductById();

  /**
   * @brief Adds an order.
   */
  void addOrder();

  /**
   * @brief Adds products to an order.
   *
   * @param[in,out] order The order to add the products.
   */
  void addProductsToOrder(Order &order);

  /**
   * @brief Updates the state from the product ID.
   */
  void updateStateFromProductId();

  /**
   * @brief Updates the state from the menu option.
   */
  void updateStateFromMenuOption();

public:
  /**
   * @brief Copy constructor.
   *
   * @details This constructor is deleted to prevent the copying of the
   * AppController object.
   *
   * @param[in] other The other AppController object.
   */
  AppController(AppController const &other) = delete;

  /**
   * @brief Copy assignment operator.
   *
   * @details This operator is deleted to prevent the copying of the
   * AppController object.
   *
   * @param[in] other The other AppController object.
   *
   * @return The AppController object.
   */
  AppController &operator=(AppController const &other) = delete;

  /**
   * @brief Retrieves the singleton instance of the AppController.
   *
   * @details This method returns a reference to the singleton instance of the
   * AppController, creating it if it does not exist.
   *
   * @return A reference to the AppController instance.
   */
  static AppController &getInstance();

  /**
   * @brief Deletes the singleton instance of the AppController.
   *
   * @details This method deletes the singleton instance of the AppController
   * if it exists, and sets the instance pointer to nullptr.
   */
  static void deleteInstance();

  /**
   * @brief Initializes the AppController.
   *
   * @details This method initializes the AppController.
   */
  void initialize();

  /**
   * @brief Processes the user request.
   *
   * @details This method processes the user request.
   */
  void process();

  /**
   * @brief Updates the state of the AppController.
   *
   * @details This method updates the state of the AppController.
   */
  void update();

  /**
   * @brief Renders the user interface.
   *
   * @details This method renders the user interface.
   */
  void render();

  /**
   * @brief Checks if the AppController should exit.
   *
   * @details This method checks if the AppController should exit.
   *
   * @return true if the AppController should exit, false otherwise.
   */
  bool exit();
};

#endif // APPCONTROLLER_HPP_
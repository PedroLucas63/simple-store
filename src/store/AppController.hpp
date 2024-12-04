#ifndef APPCONTROLLER_HPP_
#define APPCONTROLLER_HPP_

#include "entity/Order.hpp"
#include "service/Catalog.hpp"
#include <vector>

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

  AppController();
  ~AppController();

  void getMenuOption();
  void addProduct();
  void removeProduct();
  void getProductById();
  void addOrder();

  void addProductsToOrder(Order &order);

  void updateStateFromProductId();
  void updateStateFromMenuOption();

public:
  AppController(AppController const &other) = delete;
  AppController &operator=(AppController const &other) = delete;

  static AppController &getInstance();
  static void deleteInstance();

  void initialize();

  void process();
  void update();
  void render();

  bool exit();
};

#endif // APPCONTROLLER_HPP_
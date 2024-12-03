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
    Ending,
  };

  static AppController *instance;

  Catalog catalog;
  unsigned long currentOrderId;
  std::vector<Order> orders;

  State state;

  AppController();
  ~AppController();

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
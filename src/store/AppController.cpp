#include "AppController.hpp"
#include "../utils/Input.hpp"
#include "view/View.hpp"
#include <iostream>
#include <spdlog/spdlog.h>

AppController::AppController() = default;
AppController::~AppController() = default;

AppController *AppController::instance = nullptr;

AppController &AppController::getInstance() {
  if (!instance) {
    instance = new AppController();
  }

  return *instance;
}

void AppController::deleteInstance() {
  if (instance) {
    delete instance;
    instance = nullptr;
  }
}

void AppController::initialize() {
  spdlog::set_level(spdlog::level::debug);
  spdlog::info("AppController initialized");
  state = State::Starting;
  currentOrderId = INITIAL_ID;
}

void AppController::process() {
  switch (state) {
  case State::Menu:
    getMenuOption();
    break;
  case State::AddProduct:
    addProduct();
    break;
  case State::RemoveProduct:
    removeProduct();
    break;
  case State::GetProductById:
    getProductById();
    break;
  case State::AddOrder:
    addOrder();
    break;
  default:
    break;
  }
}
void AppController::update() {
  switch (state) {
  case State::Starting:
    state = State::Menu;
    break;
  case State::Menu:
    updateStateFromMenuOption();
    break;
  case State::GetProductById:
    updateStateFromProductId();
    break;
  default:
    state = State::Menu;
    break;
  }
}
void AppController::render() {
  switch (state) {
  case State::Menu:
    View::menu();
    break;
  case State::ListProducts:
    View::printProducts(catalog.getProducts());
    break;
  case State::ViewProduct:
    View::printProduct(catalog.getProductById(productId));
    break;
  case State::ListOrders:
    View::printOrders(orders);
    break;
  default:
    break;
  }
}

bool AppController::exit() { return state == State::Ending; }

void AppController::getMenuOption() {
  try {
    menuOption = Input::getInt();
  } catch (std::invalid_argument &e) {
    menuOption = -1;
    spdlog::error("Invalid menu option");
  }
}

void AppController::updateStateFromMenuOption() {
  switch (menuOption) {
  case 1:
    state = State::AddProduct;
    break;
  case 2:
    state = State::RemoveProduct;
    break;
  case 3:
    state = State::ListProducts;
    break;
  case 4:
    state = State::GetProductById;
    break;
  case 5:
    state = State::AddOrder;
    break;
  case 6:
    state = State::ListOrders;
    break;
  case 7:
    state = State::Ending;
    break;
  default:
    break;
  }
}

void AppController::addProduct() {
  int id;
  std::string name;
  float price;

  name = Input::getString("Enter the name of the product: ");

  try {
    price = Input::getFloat("Enter the price of the product: $");

    id = catalog.addProduct(Product(name, price));

    spdlog::info("Product added with id {}", id);
  } catch (std::invalid_argument &e) {
    spdlog::error("Invalid product: {}", e.what());
  }
}

void AppController::removeProduct() {
  int id;

  try {
    id = Input::getInt("Enter the id of the product to remove: ");

    catalog.deleteProduct(id);

    spdlog::info("Product removed");
  } catch (std::invalid_argument &e) {
    spdlog::error("Invalid id: {}", e.what());
  }
}

void AppController::getProductById() {
  try {
    productId = Input::getInt("Enter the id of the product: ");
  } catch (std::invalid_argument &e) {
    spdlog::error("Invalid id: {}", e.what());
  }
}

void AppController::updateStateFromProductId() {
  try {
    catalog.getProductById(productId);
    state = State::ViewProduct;
  } catch (std::runtime_error &e) {
    state = State::Menu;
    spdlog::error("Product not found: {}", e.what());
  }
}

void AppController::addOrder() {
  std::string clientName = Input::getString("Enter the client name: ");

  try {
    Order order(clientName);
    order.setId(currentOrderId++);

    addProductsToOrder(order);

    if (order.getTotalPrice() > 0) {
      orders.push_back(order);
      spdlog::info("Order added with id {}", order.getId());
    } else {
      spdlog::error("Invalid order");
    }
  } catch (std::invalid_argument &e) {
    spdlog::error("Invalid order: {}", e.what());
  }
}

void AppController::addProductsToOrder(Order &order) {
  int id;
  unsigned quantity;

  do {
    id = -1;

    try {
      id = Input::getInt("Enter the id of the product (-1 to exit): ");
    } catch (std::invalid_argument &e) {
      spdlog::error("Invalid id: {}", e.what());
      continue;
    }

    try {
      quantity = Input::getInt("Enter the quantity of the product: ");
    } catch (std::invalid_argument &e) {
      spdlog::error("Invalid quantity: {}", e.what());
      continue;
    }

    try {
      order.addProduct(catalog.getProductById(id), quantity);
    } catch (std::runtime_error &e) {
      spdlog::error("Product not found: {}", e.what());
    }
  } while (id != -1);
}
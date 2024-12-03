#include "AppController.hpp"
#include "view/View.hpp"
#include <iostream>

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
  state = State::Starting;
  currentOrderId = INITIAL_ID;
}

void AppController::process() {
  switch (state) {
  default:
    break;
  }
}
void AppController::update() {
  switch (state) {
  case State::Starting:
    state = State::Menu;
    break;
  default:
    break;
  }
}
void AppController::render() {
  switch (state) {
  case State::Menu:
    View::menu();
    break;
  default:
    break;
  }
}

bool AppController::exit() { return state == State::Ending; }
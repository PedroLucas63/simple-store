#include "store/AppController.hpp"
#include <iostream>

int main(int, char **) {
  AppController &app = AppController::getInstance();
  app.initialize();

  while (!app.exit()) {
    app.process();
    app.update();
    app.render();
  }

  app.deleteInstance();

  return EXIT_SUCCESS;
}

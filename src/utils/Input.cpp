#include "Input.hpp"
#include <iostream>

#include <stdexcept>

int Input::getInt() { return getInt(""); }

int Input::getInt(std::string const &message) {
  std::string input;

  std::cout << message;
  std::getline(std::cin, input);

  try {
    return std::stoi(input);
  } catch (std::invalid_argument &e) {
    throw std::invalid_argument("Invalid input");
  }
}

std::string Input::getString() { return getString(""); }

std::string Input::getString(std::string const &message) {
  std::string input;

  std::cout << message;
  std::getline(std::cin, input);

  return input;
}

float Input::getFloat() { return getFloat(""); }

float Input::getFloat(std::string const &message) {
  std::string input;

  std::cout << message;
  std::getline(std::cin, input);

  try {
    return std::stof(input);
  } catch (std::invalid_argument &e) {
    throw std::invalid_argument("Invalid input");
  }
}
#ifndef INPUT_HPP_
#define INPUT_HPP_

#include <string>

class Input {
public:
  static int getInt();
  static int getInt(std::string const &message);

  static std::string getString();
  static std::string getString(std::string const &message);

  static float getFloat();
  static float getFloat(std::string const &message);
};

#endif // INPUT_HPP_
#include "controller.h"

namespace s21 {

void Controller::openFile(std::string& filename) { facade_->open(filename); }

void Controller::modify(char c, float value, char axi) {
  facade_->modify(c, value, axi);
}

}  // namespace s21

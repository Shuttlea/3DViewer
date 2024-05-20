#include "facade.h"

namespace s21 {

void Facade::open(std::string& fileName) {
  OpenFile* file = new OpenFile();
  file->open(fileName);
}

void Facade::modify(char c, float value, char axi) {
  MovingContext context;
  switch (c) {
    case ('m'):
      context.setStrategy(std::make_unique<s21::MoveVertex>(), value, axi);
      break;
    case ('r'):
      context.setStrategy(std::make_unique<s21::RotateVertex>(), value, axi);
      break;
    case ('s'):
      context.setStrategy(std::make_unique<s21::ScaleVertex>(), value, axi);
      break;
  }
  context.strategy();
}

}  // namespace s21

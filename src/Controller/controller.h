#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/facade.h"

namespace s21 {
/*!
          \brief Класс контроллера MVC, вызывает одноименные методы класса
   Facade в модели
  */
class Controller {
 private:
  Facade* facade_;

 public:
  Controller(Facade* f) : facade_(f) {}
  void openFile(std::string& filename);
  void modify(char c, float value, char axi);
};

}  // namespace s21

#endif

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/facade.h"

namespace s21 {

class Controller {
private:
  Facade* facade;
 public:
  Controller(Facade* f):facade(f){}
  void openFile(std::string& filename);
};

}  // namespace s21

#endif
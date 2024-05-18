#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/facade.h"

namespace s21 {

class Controller {
private:
  Facade* facade_;
 public:
  Controller(Facade* f):facade_(f){}
  void openFile(std::string& filename);
  void scale(float value,char axi);
};

}  // namespace s21

#endif

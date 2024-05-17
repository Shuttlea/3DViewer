#include "controller.h"

namespace s21{

void Controller::openFile(std::string& filename){
  facade->open(filename);
}

}//namespace s21
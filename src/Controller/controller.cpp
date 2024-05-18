#include "controller.h"

namespace s21{

void Controller::openFile(std::string& filename){
  facade_->open(filename);
}

void Controller::scale(float value,char axi){
    facade_->scale(value,axi);
}

}//namespace s21

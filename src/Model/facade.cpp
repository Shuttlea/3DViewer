#include "facade.h"

namespace s21{

void Facade::open(std::string & fileName){
  OpenFile * file = new OpenFile();
  file->open(fileName);
}

void Facade::scale(float value,char axi){
    MovingContext context;
    context.setStrategy(std::make_unique<ScaleVertex>(),value,axi);
    context.strategy();
}

}

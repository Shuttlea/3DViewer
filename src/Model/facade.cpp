#include "facade.h"

namespace s21{

void Facade::open(std::string & fileName){
  OpenFile * file = new OpenFile();
  file->open(fileName);
}

}
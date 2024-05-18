#ifndef FACADE_H
#define FACADE_H

#include "openFile.h"
#include "../movingClasses/movingClasses.h"


namespace s21{

class Facade{
  public:
    void open(std::string& fileName);
    void scale(float value,char axi);
};

}//namespace s21

#endif

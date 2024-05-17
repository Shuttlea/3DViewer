#ifndef FACADE_H
#define FACADE_H

#include "openFile.h"


namespace s21{

class Facade{
  public:
    void open(std::string& fileName);
};

}//namespace s21

#endif
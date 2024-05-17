#ifndef OPENFILE_H
#define OPENFILE_H

// #include <fstream>
// #include <iostream>
// #include <sstream>
// #include <string>

#include "reader.h"
#include "singleton.h"

namespace s21 {
class OpenFile {
  // private:
  //   std::string fileName_;
  //   OpenFile(std::string file):fileName_(file){}
  // Strategy* reader;

 public:
  void open(std::string fileName);
  void calculateVertCount(std::ifstream& in);
};

}  // namespace s21

#endif
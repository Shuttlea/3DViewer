#ifndef READER_H
#define READER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "singleton.h"

namespace s21 {

class Reader {
 public:
  void read(std::ifstream& in);
  void readV(std::string s, int& count);
  void readF(std::string s,int& countV);
};

}  // namespace s21

#endif

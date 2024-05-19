#ifndef READER_H
#define READER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "singleton.h"
#include "../movingClasses/movingClasses.h"


namespace s21 {

class Reader {
private:
  float max_coord_[2][3];
  void readV(std::string s, int& count);
  void readF(std::string s,int& countV);
  void centering();
 public:
  void read(std::ifstream& in);
};

}  // namespace s21

#endif

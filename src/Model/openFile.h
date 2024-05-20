#ifndef OPENFILE_H
#define OPENFILE_H

#include "reader.h"
// #include "singleton.h"

namespace s21 {
class OpenFile {
 private:
  void calculateVertCount(std::ifstream& in);

 public:
  void open(std::string fileName);
};

}  // namespace s21

#endif

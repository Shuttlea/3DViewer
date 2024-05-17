#include "openFile.h"

namespace s21 {

void OpenFile::open(std::string fileName) {
  std::ifstream in(fileName);
  Singleton& singl = Singleton::getInstance();
  if (in.is_open()) {
    Reader* reader = new Reader();
    calculateVertCount(in);
    in.clear();
    in.seekg(0);
    reader->read(in);
    in.close();
  }
}

void OpenFile::calculateVertCount(std::ifstream& in) {
  Singleton& singl = Singleton::getInstance();
  char first, second;
  singl.vertCount() = 0;
  std::string s;
  while (in.get(first) && in.get(second)) {
    if (first == 'v' && second == ' ') ++singl.vertCount();
    std::getline(in, s);
  }
  singl.CreateMatrix(singl.vertCount());
}

}  // namespace s21
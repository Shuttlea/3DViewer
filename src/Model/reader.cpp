#include "reader.h"

#include <iostream>

namespace s21 {

void Reader::readV(std::string s, int& count) {
  Singleton& singl = Singleton::getInstance();
  std::istringstream ins(s);
  float** matrix = singl.vertMatrix();
  for (int i = 0; i < 3; ++i) ins >> matrix[count][i];
}

void Reader::readF(std::string s) {
  Singleton& singl = Singleton::getInstance();
  std::istringstream ins(s);
  int count = 0, k;
  char c;
  while (ins >> k) {
    ++count;
    while (ins.get(c) && c != ' ')
      ;
  }
  side* newSide = singl.addSide(count);
  count = 0;
  ins.clear();
  ins.seekg(0);
  while (ins >> newSide->edges[count]) {
    if (newSide->edges[count] < 0)
      newSide->edges[count] = singl.vertCount() + newSide->edges[count];
    ++count;
    while (ins.get(c) && c != ' ')
      ;
  }
}

void Reader::read(std::ifstream& in) {
  char first, second;
  std::string s;
  int countV = 0;
  while (in.get(first) && in.get(second)) {
    if (first == 'f') {
      std::getline(in, s);
      readF(s);
    } else if (first == 'v' && second == ' ') {
      std::getline(in, s);
      readV(s, countV);
      ++countV;
    } else
      std::getline(in, s);
  }
}

}  // namespace s21

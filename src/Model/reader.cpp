#include "reader.h"

#include <iostream>

namespace s21 {

void Reader::readV(std::string s, int& count) {
  Singleton& singl = Singleton::getInstance();
  std::istringstream ins(s);
  float** matrix = singl.vertMatrix();
  for (int i = 0; i < 3; ++i) {
      ins >> matrix[count][i];
      if (count == 0) {
          max_coord_[0][i] = matrix[count][i];
          max_coord_[1][i] = matrix[count][i];
      }
      else {
          if (max_coord_[0][i]>matrix[count][i]) max_coord_[0][i] = matrix[count][i];
          if (max_coord_[1][i]<matrix[count][i]) max_coord_[1][i] = matrix[count][i];
      }
  }
}

void Reader::readF(std::string s,int& countV) {
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
      newSide->edges[count] = countV + newSide->edges[count]+1;
    ++count;
    while (ins.get(c) && c != ' ')
      ;
  }
}

void Reader::read(std::ifstream& in) {
  char first, second;
  std::string s;
  int countV = 0;
  while (in>>first && in.get(second)) {
      if (first == 'v' && second == ' ') {
          std::getline(in, s);
          readV(s, countV);
          ++countV;
        }
    else if (first == 'f') {
      std::getline(in, s);
      readF(s,countV);
    }
      else
      std::getline(in, s);
  }
  centering();
}

void Reader::centering(){
//    std::cout << max_coord_[0][0] << " " << max_coord_[0][1] << " " << max_coord_[0][2] << " " << std::endl;
//    std::cout << max_coord_[1][0] << " " << max_coord_[1][1] << " " << max_coord_[1][2] << " " << std::endl;
    MovingContext context;
    context.setStrategy(std::make_unique<s21::MoveVertex>(),-(max_coord_[0][0] + max_coord_[1][0]) / 2,'x');
    context.strategy();
    context.setStrategy(std::make_unique<s21::MoveVertex>(),-(max_coord_[0][1] + max_coord_[1][1]) / 2,'y');
    context.strategy();
    context.setStrategy(std::make_unique<s21::MoveVertex>(),-(max_coord_[0][2] + max_coord_[1][2]) / 2,'z');
    context.strategy();
    float max_lenth;
    max_lenth = abs(max_coord_[0][0] - max_coord_[1][0]);
    if (max_lenth < abs(max_coord_[0][1] - max_coord_[1][1]))
      max_lenth = abs(max_coord_[0][1] - max_coord_[1][1]);
    if (max_lenth < abs(max_coord_[0][2] - max_coord_[1][2]))
      max_lenth = abs(max_coord_[0][2] - max_coord_[1][2]);
    context.setStrategy(std::make_unique<s21::ScaleVertex>(),2/max_lenth,'x');
    context.strategy();
}

}  // namespace s21

#include <iostream>

#include "singleton.h"
#include "../movingClasses/movingClasses.h"
#include "../movingClasses/movingStrategy.h"

void create(int count);
void modding();
void print();

int main() { 
  create(10);
  print();
  modding();
  std::cout<<std::endl;
  print();
  return 0; }

void create(int count) {
  Singleton& singl = Singleton::getInstance();
  singl.CreateMatrix(count);
  for (int i = 0; i < count; i++) {
    singl.vertMatrix()[i][0] = i + 1;
    singl.vertMatrix()[i][1] = i + 2;
    singl.vertMatrix()[i][2] = i + 3;
  }
}

void modding(){
  Singleton& singl = Singleton::getInstance();
  singl.vertMatrix()[2][1] = 8888;
}

void print() {
  Singleton& singl = Singleton::getInstance();
  for (int i = 0; i < singl.vertCount(); ++i) {
    std::cout << singl.vertMatrix()[i][0] << " ";
    std::cout << singl.vertMatrix()[i][1] << " ";
    std::cout << singl.vertMatrix()[i][2] << " " << std::endl;
  }
}
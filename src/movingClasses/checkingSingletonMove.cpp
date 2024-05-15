#include <iostream>

#include "../Model/singleton.h"
#include "movingClasses.h"
#include "movingStrategy.h"
// #include ""


void create(int count);
void modding();
void print();

int main() { 
  create(10);
  print();
  //modding();

  std::cout<<std::endl;

  s21::MovingContext context;

  context.setStrategy(std::make_unique<s21::ScaleVertex>(), 2, 'c');
  context.strategy();
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
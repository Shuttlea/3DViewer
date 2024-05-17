#include <iostream>

#include "openFile.h"
#include "singleton.h"

void create(int count);
void modding();
void print();
void newSide();
void printSides();

int main() {
  s21::Singleton& singl = s21::Singleton::getInstance();
  s21::OpenFile o;
  // o.open("models/cuberubik.obj");
  // o.open("models/pyramid.obj");
  // o.open("models/skull.obj");
  o.open("Model/check.txt");
  // create(10);
  // print();
  // modding();
  // std::cout<<std::endl;
  // print();
  // newSide();
  // newSide();
  // newSide();
  // printSides();

  // PRINT SIDES:
  std::cout << "PRINT SIDES:" << std::endl;
  s21::side* qwer = singl.getSides();
  while (qwer != nullptr) {
    for (int i = 0; i < qwer->edge_count; ++i)
      std::cout << qwer->edges[i] << " ";
    std::cout << std::endl;
    qwer = qwer->ptr;
  }
  // PTINT VERTEX:
  std::cout << "PRINT VERTEX:" << std::endl;
  float** matrix = singl.vertMatrix();
  for (int i = 0; i < singl.vertCount(); ++i) {
    std::cout << matrix[i][0] << " " << matrix[i][1] << " " << matrix[i][2]
              << " " << std::endl;
  }
  std::cout << "VERTEX COUNT: " << singl.vertCount() << std::endl;

  return 0;
}

void create(int count) {
  s21::Singleton& singl = s21::Singleton::getInstance();
  singl.CreateMatrix(count);
  for (int i = 0; i < count; i++) {
    singl.vertMatrix()[i][0] = i + 1;
    singl.vertMatrix()[i][1] = i + 2;
    singl.vertMatrix()[i][2] = i + 3;
  }
}

void modding() {
  s21::Singleton& singl = s21::Singleton::getInstance();
  singl.vertMatrix()[2][1] = 8888;
}

void print() {
  s21::Singleton& singl = s21::Singleton::getInstance();
  for (int i = 0; i < singl.vertCount(); ++i) {
    std::cout << singl.vertMatrix()[i][0] << " ";
    std::cout << singl.vertMatrix()[i][1] << " ";
    std::cout << singl.vertMatrix()[i][2] << " " << std::endl;
  }
}

void newSide() {
  s21::Singleton& singl = s21::Singleton::getInstance();
  int count = 8;
  s21::side* k = singl.addSide(count);
  for (int i = 0; i < 8; ++i) k->edges[i] = i + 6;
}

void printSides() {
  s21::Singleton& singl = s21::Singleton::getInstance();
  s21::side* ptr = singl.getSides();
  while (ptr != nullptr) {
    std::cout << ptr->edge_count << ":" << std::endl << " ";
    for (int i = 0; i < ptr->edge_count; ++i) std::cout << ptr->edges[i] << " ";
    std::cout << std::endl;
    ptr = ptr->ptr;
  }
}
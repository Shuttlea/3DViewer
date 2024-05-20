#include <gtest/gtest.h>
#include <string>
#include <iostream>

#include "../Model/facade.h"

TEST(Reader, true){
  std::string filename = "./models/pyramid.obj";
  std::ifstream in(filename);
  s21::Singleton& singl = s21::Singleton::getInstance();

  s21::Reader* reader = new s21::Reader();
  singl.CreateMatrix(5);
  reader -> read(in);
  in.close();
  delete reader;

  ASSERT_TRUE(singl.edgesCount() == 18);

}

TEST(OpenFile, true){
  std::string filename = "./models/pyramid.obj";
  s21::Singleton& singl = s21::Singleton::getInstance();
  s21::OpenFile* o = new s21::OpenFile(); 
  o->open(filename);

  ASSERT_TRUE(singl.edgesCount() == 9);
  ASSERT_TRUE(singl.vertCount() == 5);
}

TEST(OpenFile, false){
  std::string filename = "./models/nofile.obj";
  s21::Singleton& singl = s21::Singleton::getInstance();
  singl.CreateMatrix(0);
  s21::OpenFile* o = new s21::OpenFile(); 
  o->open(filename);

  ASSERT_TRUE(singl.edgesCount() == 0);
  ASSERT_TRUE(singl.vertCount() == 0);
}

TEST(FacadeRotateX, true){
  std::string filename = "./models/pyramid.obj";
  s21::Singleton& singl = s21::Singleton::getInstance();
  s21::Facade f;

  f.open(filename);
  f.modify('r', 90, 'x');
  ASSERT_NEAR(singl.vertMatrix()[0][2], 0.50, 0.01);
}

TEST(FacadeRotateY, true){
  std::string filename = "./models/pyramid.obj";
  s21::Singleton& singl = s21::Singleton::getInstance();
  s21::Facade f;

  f.open(filename);
  f.modify('r', 90, 'y');
  ASSERT_NEAR(singl.vertMatrix()[0][1], 0.5, 0.01);
}
TEST(FacadeRotateZ, true){
  std::string filename = "./models/pyramid.obj";
  s21::Singleton& singl = s21::Singleton::getInstance();
  s21::Facade f;

  f.open(filename);
  f.modify('r', 90, 'z');
  ASSERT_NEAR(singl.vertMatrix()[0][1], 3.06162e-17, 1e-6);
}

TEST(FacadeScale, true){
  std::string filename = "./models/pyramid.obj";
  s21::Singleton& singl = s21::Singleton::getInstance();
  s21::Facade f;

  f.open(filename);
  f.modify('s', 90, 'z');
  ASSERT_NEAR(singl.vertMatrix()[0][1], 45.00, 0.001);
}

TEST(FacadeMove, true){
  std::string filename = "./models/pyramid.obj";
  s21::Singleton& singl = s21::Singleton::getInstance();
  s21::Facade f;

  f.open(filename);
  f.modify('m', 90, 'z');
  ASSERT_NEAR(singl.vertMatrix()[0][1], 0.5, 0.01);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
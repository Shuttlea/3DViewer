#include "openFile.h"

namespace s21 {

void OpenFile::open(std::string fileName) {
  std::ifstream in(fileName);
  Singleton& singl = Singleton::getInstance();
  if (in.is_open()) {
    Reader* reader = new Reader();
//    cleanSingleton();
    calculateVertCount(in);
    in.clear();
    in.seekg(0);
    reader->read(in);
    in.close();
    delete reader;
  }
}

void OpenFile::calculateVertCount(std::ifstream& in) {
  Singleton& singl = Singleton::getInstance();
  char first, second;
//  singl.vertCount() = 0;
  int count=0;
  std::string s;
  while (in.get(first) && in.get(second)) {
    if (first == 'v' && second == ' ') ++count;
    std::getline(in, s);
  }
  singl.CreateMatrix(count);
}

//void OpenFile::cleanSingleton(){
//    Singleton& singl = Singleton::getInstance();
//    if (singl.getSides()!=nullptr){
//        for (int i = 0; i < singl.vertCount(); ++i) delete singl.vertMatrix()[i];
//              delete singl.vertMatrix();
//        singl.vertCount() = 0;
//        side* s = singl.getSides();
//        while (s!=nullptr){
//            s = s->ptr;
//            delete singl.getSides();
//        }
//        singl.getSides() = nullptr;
//    }
//}

}  // namespace s21

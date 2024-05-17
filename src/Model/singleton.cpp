#include "singleton.h"

Singleton* Singleton::singleton_ = nullptr;

Singleton& Singleton::getInstance() {
  if (singleton_ == nullptr) singleton_ = new Singleton();
  return *singleton_;
}

float** Singleton::CreateMatrix(int count) {
  vertCount_ = count;
  vertMat_ = new float*[count];
  for (int i = 0; i < count; ++i) vertMat_[i] = new float[3];
  return vertMat_;
}

float** Singleton::vertMatrix() { return vertMat_; }

int& Singleton::vertCount() { return vertCount_; }

// Singleton::~Singleton(){
//   for (int i = 0;i<vertCount_;++i)
//     delete vertMat_[i];
//   delete vertMat_;
// }
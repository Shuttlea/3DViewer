#include "singleton.h"

namespace s21 {

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

side* Singleton::addSide(int& count) {
  if (firstSide_ == nullptr) {
    firstSide_ = new side;
    lastSide_ = firstSide_;
  } else {
    lastSide_->ptr = new side;
    lastSide_ = lastSide_->ptr;
  }
  lastSide_->ptr = nullptr;
  lastSide_->edge_count = count;
  lastSide_->edges = new int[count];
  return lastSide_;
}

side* Singleton::getSides() { return firstSide_; }

}  // namespace s21
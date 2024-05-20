#ifndef MOVINGSTRATEGY_H
#define MOVINGSTRATEGY_H

#include <cmath>

#include "../Model/singleton.h"

namespace s21 {
class MovingStrategy {
 public:
  virtual ~MovingStrategy(){};

  virtual void movingVertex(float moveValue, char axi) const = 0;
};

class MoveVertex : public MovingStrategy {
 public:
  void movingVertex(float moveValue, char axi) const override {
    Singleton& sing = Singleton::getInstance();
    int count = sing.vertCount();
    float** vertex = sing.vertMatrix();
    if (axi == 'x') {
      for (int i = 0; i < count; ++i) {
        vertex[i][0] += moveValue;
      }
    } else if (axi == 'y') {
      for (int i = 0; i < count; ++i) {
        vertex[i][1] += moveValue;
      }
    } else if (axi == 'z') {
      for (int i = 0; i < count; ++i) {
        vertex[i][2] += moveValue;
      }
    }
  }
};

class RotateVertex : public MovingStrategy {
 public:
  void movingVertex(float moveValue, char axi) const override {
    Singleton& sing = Singleton::getInstance();
    int count = sing.vertCount();
    float** vertex = sing.vertMatrix();
    float sina = sin((M_PI / 180) * moveValue);
    float cosa = cos((M_PI / 180) * moveValue);
    if (axi == 'x' || axi == 'X') {
      for (int i = 0; i < count; i++) {
        float vertexTmp[3] = {vertex[i][0], vertex[i][1], vertex[i][2]};
        vertex[i][0] = vertexTmp[0];
        vertex[i][1] = vertexTmp[1] * cosa + vertexTmp[2] * (-sina);
        vertex[i][2] = vertexTmp[1] * sina + vertexTmp[2] * cosa;
      }
    } else if (axi == 'y' || axi == 'Y') {
      for (int i = 0; i < count; i++) {
        float vertexTmp[3] = {vertex[i][0], vertex[i][1], vertex[i][2]};
        vertex[i][0] = vertexTmp[0] * cosa + vertexTmp[2] * sina;
        vertex[i][1] = vertexTmp[1];
        vertex[i][2] = vertexTmp[0] * (-sina) + vertexTmp[2] * cosa;
      }
    } else if (axi == 'z' || axi == 'Z') {
      for (int i = 0; i < count; i++) {
        float vertexTmp[3] = {vertex[i][0], vertex[i][1], vertex[i][2]};
        vertex[i][0] = vertexTmp[0] * cosa + vertexTmp[1] * (-sina);
        vertex[i][1] = vertexTmp[0] * sina + vertexTmp[1] * cosa;
        vertex[i][2] = vertexTmp[2];
      }
    }
  }
};

class ScaleVertex : public MovingStrategy {
 public:
  void movingVertex(float moveValue, char axi) const override {
    Singleton& sing = Singleton::getInstance();
    int count = sing.vertCount();
    float** vertex = sing.vertMatrix();
    static_cast<void>(axi);
    for (int i = 0; i < count; i++) {
      vertex[i][0] = vertex[i][0] * moveValue;
      vertex[i][1] = vertex[i][1] * moveValue;
      vertex[i][2] = vertex[i][2] * moveValue;
    }
  }
};
}  // namespace s21

#endif  // MOVINGSTRATEGY_H
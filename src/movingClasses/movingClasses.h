#ifndef MOVINGCLASSES_H
#define MOVINGCLASSES_H

#include <memory>

#include "movingStrategy.h"

namespace s21 {
 class MovingContext{
  private:
    std::unique_ptr<s21::MovingStrategy> movingStrategy{};
    float moveValue_;
    char axi_;

  public:
    void setStrategy(std::unique_ptr<MovingStrategy> &&movingStrategy_) {
      movingStrategy = std::move(movingStrategy_);
    }
    
    void strategy() {
      if(movingStrategy) movingStrategy-> movingVertex(moveValue_, axi_);
    }
 };
}


#endif // MOVINGCLASSES_H
#ifndef MOVINGCLASSES_H
#define MOVINGCLASSES_H

#include <memory>

#include "movingStrategy.h"

namespace s21 {
class MovingContext {
 private:
  std::unique_ptr<s21::MovingStrategy> movingStrategy{};
  float moveValue_;
  char axi_;

 public:
  void setStrategy(std::unique_ptr<MovingStrategy> &&movingStrategy_,
                   float moveValue, char axi) {
    movingStrategy = std::move(movingStrategy_);
    moveValue_ = moveValue;
    axi_ = axi;
  }

  void strategy() {
    if (movingStrategy) movingStrategy->movingVertex(moveValue_, axi_);
  }
};
}  // namespace s21

#endif  // MOVINGCLASSES_H
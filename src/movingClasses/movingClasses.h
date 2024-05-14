#ifndef MOVINGCLASSES_H
#define MOVINGCLASSES_H

#include <memory>

#include "movingStrategy.h"

namespace s21 {
 class MovingContext{
  private:
    std::unique_ptr<s21::MovingStrategy> movingStrategy_;
  public:
    
 }
}


#endif // MOVINGCLASSES_H
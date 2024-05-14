#ifndef MOVINGSTRATEGY_H
#define MOVINGSTRATEGY_H

namespace s21{
  class MovingStrategy{
    public:
      virtual ~MovingStrategy(){};

      virtual void movingVertex(float** vertMatr, 
                                int vertexCount, float moveValue, char axi);
  }
}

#endif // MOVINGSTRATEGY_H
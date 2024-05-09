#ifndef 3D_VIEWER_V_2_MOVING_INTERFACE
#define 3D_VIEWER_V_2_MOVING_INTERFACE

namespace s21{
  class MovingInterface{
    public:
      virtual ~MovingInterface(){};

      virtual void movingVertex(float** vertMatr, 
                                int vertexCount, float moveValue, char axi);
  }
}

#endif // 3D_VIEWER_V_2_MOVING_INTERFACE
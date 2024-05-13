#ifndef SINGLETON_H
#define SINGLETON_H

// #include <vector>

typedef struct side {
  int edge_count;
  int *edges;
  struct side *ptr;
} side;

// typedef struct objData {
//   side edge;
//   float** vertMatr;
//   int vertCount;
// }objData;

class Singleton {
 private:
  static Singleton *singleton_;
  float **vertMat_;
  int vertCount_;

  Singleton(){};
  ~Singleton(){};

 public:
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &) = delete;

  static Singleton &getInstance();
  float **CreateMatrix(int count);
  float **vertMatrix();
  int &vertCount();
  // void create(int size);
};

#endif

// float** vert_matrix = Singleton.getVertex();
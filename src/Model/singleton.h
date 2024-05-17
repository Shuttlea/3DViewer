#ifndef SINGLETON_H
#define SINGLETON_H

namespace s21 {

typedef struct side {
  int edge_count;
  int *edges;
  struct side *ptr;
} side;

class Singleton {
 private:
  static Singleton *singleton_;
  float **vertMat_;
  int vertCount_;
  side *firstSide_ = nullptr;
  side *lastSide_;

  Singleton(){};
  ~Singleton(){};

 public:
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &) = delete;

  static Singleton &getInstance();
  float **CreateMatrix(int count);
  float **vertMatrix();
  int &vertCount();
  side *addSide(int &count);
  side *getSides();
};

}  // namespace s21

#endif
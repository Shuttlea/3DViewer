#ifndef SINGLETON_H
#define SINGLETON_H

namespace s21 {

typedef struct side {
  int edge_count;
  int *edges;
  struct side *ptr;
} side;

/*!
          \brief Класс, реализующий паттерн Синглтон
  */
class Singleton {
 private:
  static Singleton *singleton_;
  float **vertMat_ = nullptr;
  int vertCount_;
  int edgesCount_ = 0;
  side *firstSide_ = nullptr;
  side *lastSide_;

  Singleton(){};
  ~Singleton(){};

 public:
  Singleton(Singleton &other) = delete;
  void operator=(const Singleton &) = delete;

  /*!
          \brief Метод, создающий экземпляр класса Singleton
  */
  static Singleton &getInstance();
  /*!
          \brief Метод, выделяющий память для координар вершин
  */
  float **CreateMatrix(int count);
  /*!
          \brief Метод, позволяющий присваивать и считывать координаты
     конкретных вершин
  */
  float **vertMatrix();
  int &vertCount();
  int &edgesCount();
  side *addSide(int &count);
  side *getSides();
};

}  // namespace s21

#endif

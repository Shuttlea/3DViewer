#ifndef READER_H
#define READER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "../movingClasses/movingClasses.h"
#include "singleton.h"

namespace s21 {

/*!
        \brief Класс для считывания координат вершин и граней модели
*/

class Reader {
 private:
  float max_coord_[2][3];

  /*!
          \brief Метод считывания координат вершин
  */
  void readV(std::string s, int& count);

  /*!
          \brief Метод опрделения граней
  */
  void readF(std::string s, int& countV);

  /*!
          \brief Метод центрирования изображения
  */
  void centering();

 public:
  /*!
          \brief Метод, объединяющий считывание вершин и граней
  */
  void read(std::ifstream& in);
};

}  // namespace s21

#endif

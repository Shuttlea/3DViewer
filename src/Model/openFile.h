#ifndef OPENFILE_H
#define OPENFILE_H

#include "reader.h"
// #include "singleton.h"

namespace s21 {
/*!
        \brief Класс для открытия файла
*/
class OpenFile {
 private:
  /*!
           \brief Метод подсчёта количества вершин в модели
   */
  void calculateVertCount(std::ifstream& in);

 public:
  /*!
           \brief Метод для открытия файла, создающий класс Reader
   */
  void open(std::string fileName);
};

}  // namespace s21

#endif

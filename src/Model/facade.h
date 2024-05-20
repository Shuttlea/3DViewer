#ifndef FACADE_H
#define FACADE_H

#include "openFile.h"
//#include "../movingClasses/movingClasses.h"

namespace s21 {

/*!
          \brief Класс, реализующий патерн Фасад
  */

class Facade {
 public:
  /*!
           \brief Метод для открытия файла посредствм класса OpenFile
   */
  void open(std::string& fileName);
  /*!
          \brief Метод вызывающий смену контекста MovingContext, для реализации
     паттерна Стратегия
  */
  void modify(char c, float value, char axi);
};

}  // namespace s21

#endif

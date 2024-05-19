#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#define GL_SILENCE_DEPRECATION

//extern "C" {
//#include "../Model/viewer.h"
//}

#include <OpenGl/gl.h>
#include <OpenGl/glu.h>

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QTimer>

#include "mainwindow.h"

namespace s21{

/*!
        \brief Класс окна отображения модели

        Реагирует на сигналы от класса MainWindow
*/
class MyOpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 private:
  side* ptr = NULL;

 public slots:
  /*!
        \brief Метод поворота модели
*/
  void Rotate();
  /*!
        \brief Метод сдвига модели
*/
  void Move(float value, int axi);
  /*!
          \brief Метод масштабирования модели
  */
  void Scale(float scale_change);
  /*!
          \brief Метод изменения проекции отображения
  */
  void ChangeProjection();
  /*!
          \brief Метод изменения отображение вершин на квадраты
  */
  void SquarePoints();
  /*!
          \brief Метод изменения отображения вершин на круги
  */
  void CirclePoints();
  /*!
        \brief Метод включения и отключения отображения вершин
*/
  void ShowHidePoints();
  /*!
        \brief Метод изменения размеров вершин
*/
  void PointSizeChange(int size_value);
  /*!
        \brief Метод меняющиий отображение линий на пунктир
*/
  void DashingLines();
  /*!
          \brief Метод изменения толщины линий
  */
  void LinesWidthChange(int change_value);

 public:
  MyOpenGLWidget(QWidget* parent = nullptr);
  void MakeFace(side* face_ptr, float arr[20]);
  void ChangeBackgroundColor(QColor c);
  void ChangeLineColor(QColor c);
  void ChangePointColor(QColor c);
  float scale_value;
  QColor color_;
  QColor lcolor_;
  QColor pcolor_;
  bool projection;
  bool circle_points;
  bool show_point;
  bool dashed_line;
  int line_width;
  int point_size;

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;
};

}//namespace s21

#endif  // MYOPENGLWIDGET_H

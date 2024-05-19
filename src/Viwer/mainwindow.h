#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFileDialog>
#include <QMainWindow>
#include <QSettings>
#include <QTimer>
#include <QIntValidator>

#include "./gifmaker/gif_hash.h"
#include "./gifmaker/gif_lib.h"
#include "./gifmaker/gif_lib_private.h"
#include "./gifmaker/qgifglobal.h"
#include "./gifmaker/qgifimage.h"
#include "./gifmaker/qgifimage_p.h"
#include "../Controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21{

/*!
        \brief Класс основного окна

        Класс содержит меню нвстроек и виджет с отображением модели
*/
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(Controller * controller,QWidget *parent = nullptr);
  ~MainWindow();

 public slots:
  void Info(int edges_count, int vertex_count);

 private:
  Controller* controller_;
  int imagecounter;
  int screenshotcounter;
  int gifcounter;
  QTimer timer;
  QList<QImage> jiff;
  QDir dir;

 signals:
  void signal(QString);
  void StopTimer();
  void Rotate();
  void Move(float value, int axi);
  void ScalePlus(float scale_change);
  void ChangeProjection();
  void SquaredPoint();
  void CircledPoint();
  void ShowedPoints();
  void VertPlus();
  void VertMinus();
  void DashedLine();
  void LineWidthPlus();
  void LineWidthMinus();

 private slots:
  /*!
          \brief Метод для открытия файла
  */
  void on_OpenFileButton_clicked();
  /*!
          \brief Метод вызова метода остановки вращения
  */
  void on_StopButton_clicked();
  /*!
          \brief Метод вызова метода поворота
  */
  void on_RotateButton_clicked();
  /*!
          \brief Метод вызова метода сдвига
  */
  void on_MoveButton_clicked();
  /*!
          \brief Метод вызова метода масштабировния для увеличения
  */
  void scalePlusClicked();
  /*!
          \brief Метод вызова метода масштабировния для уменьшения
  */
  void scaleMinusClicked();
  /*!
          \brief Метод вызова метода изменения цвета фона
  */
  void ChangeBackgroundColor();
  /*!
          \brief Метод вызова метода изменения цвета линий
  */
  void ChangeLineColor();
  /*!
          \brief Метод для сохранения настроек отображения
  */
  void SaveSettings();
  /*!
          \brief Метод для загрузки настроек отображения
  */
  void LoadSettings();
  /*!
          \brief Метод вызова метода изменения цвета вершин
  */
  void ChangePointColor();
  void SquarePoints();
  void CirclePoints();
  void ShowPoints();
  void VertPlusClicked();
  void VertMinusClicked();
  void DashLine();
  void LineWidthPlusClicked();
  void LineWidthMinusClicked();
  void MakeScreenShoot();
  void NeedJpeg();
  void NeedBmp();
  void MakeGif();
  void NeedGif();

  void on_ProjectionButton_clicked();

 private:
  Ui::MainWindow *ui;

  QSettings *settings;
};

}//namecpace s21
#endif  // MAINWINDOW_H

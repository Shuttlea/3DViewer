#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Facade *facade;
  facade = new s21::Facade;
  s21::Controller *controller = new s21::Controller(facade);
  s21::MainWindow w(controller);
  w.show();
  return a.exec();
}

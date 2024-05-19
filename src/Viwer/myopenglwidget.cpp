#include "myopenglwidget.h"

#include "../Model/viewer.h"

namespace s21{

MyOpenGLWidget::MyOpenGLWidget(QWidget* parent) : QOpenGLWidget{parent} {
  circle_points = false;
  show_point = false;
  point_size = 5;
  projection = true;
  dashed_line = false;
  line_width = 1;
//  connect(&tmr, SIGNAL(timeout()), this, SLOT(changeZ()));
}

void MyOpenGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glClearColor(color_.redF(), color_.greenF(), color_.blueF(), color_.alphaF());
}

void MyOpenGLWidget::resizeGL(int w, int h) {
  glViewport(10, 10, w - 100, h - 100);
}

void MyOpenGLWidget::paintGL() {
  Singleton& singl = Singleton::getInstance();
  s21::side* sides = singl.getSides();
  side* tmp;
  side* ptmp;
  float arr[20];
  // std::array<float,10> arr1;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if (projection) {
    glOrtho(-1.5, 1.5, -1.5, 1.5, 1, 20);
  } else {
    glFrustum(-0.5, 0.5, -0.5, 0.5, 1, 20);
  }
  gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);
  glClearColor(color_.redF(), color_.greenF(), color_.blueF(), color_.alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (sides!=nullptr) {
    glColor3d(lcolor_.redF(), lcolor_.greenF(), lcolor_.blueF());
    glLineWidth(line_width);
    glLineStipple(20, 0x0333);
    tmp = ptr;
    ptmp = ptr;
//    rotate(vertex_matrix, 80 * z, 'y', vertex_count);
//    rotate(vertex_matrix, 80 * z, 'x', vertex_count);
//    rotate(vertex_matrix, 80 * z, 'z', vertex_count);
    if (dashed_line) {
      glEnable(GL_LINE_STIPPLE);
    } else if (!dashed_line) {
      glDisable(GL_LINE_STIPPLE);
    }
    while (sides!=nullptr) {
      // arr = (float*)malloc(3 * tmp->edge_count * sizeof(float));
      MakeFace(sides, arr);
      glVertexPointer(3, GL_FLOAT, 0, arr);
      glEnableClientState(GL_VERTEX_ARRAY);
      glDrawArrays(GL_LINE_LOOP, 0, sides->edge_count);
      glDisableClientState(GL_VERTEX_ARRAY);
      // free(arr);
      sides = sides->ptr;
    }
    glColor3d(pcolor_.redF(), pcolor_.greenF(), pcolor_.blueF());
    glPointSize(point_size);
    if (!circle_points) {
      glDisable(GL_POINT_SMOOTH);
    } else {
      glEnable(GL_POINT_SMOOTH);
    }
    if (show_point) {
        s21::side* sides = singl.getSides();
      while (sides!=nullptr) {
        //        arr = (float*)malloc(3 * ptmp->edge_count * sizeof(float));
        MakeFace(sides, arr);
        glVertexPointer(3, GL_FLOAT, 0, arr);
        glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_POINTS, 0, sides->edge_count);
        glDisableClientState(GL_VERTEX_ARRAY);
        //        free(arr);
       sides = sides->ptr;
      }
    }
  }
}

//void MyOpenGLWidget::changeZ() {
//  tmr.start(100);
//  z = 0.01;
//  update();
//}

void MyOpenGLWidget::MakeVertexArray(QString filename) {
//  side* tmp = ptr;
//  if (tmp) {
//    while (tmp) {
//      tmp = ptr->ptr;
//      free(ptr);
//      ptr = tmp;
//    }
//    free(vertex_matrix);
//  }
//  QByteArray filename_char = filename.toLatin1();
//  vertex_matrix =
//      open_obj(filename_char.data(), &vertex_count, &edges_count, &ptr);
    Singleton& singl = Singleton::getInstance();
  emit Info(singl.vertCount(), singl.vertCount());
  update();
}

//void MyOpenGLWidget::StopTimer() {
//  z = 0;
//  tmr.stop();
//}

void MyOpenGLWidget::Rotate() {
//  rotate(vertex_matrix, value, axi, vertex_count);
  update();
}

void MyOpenGLWidget::Move(float value, int axi) {
//  float x = 0, y = 0, z = 0;
//  if (axi == 1) x = value;
//  if (axi == 2) y = value;
//  if (axi == 3) z = value;
//  moveVertex(vertex_matrix, vertex_count, x, y, z);
  update();
}

void MyOpenGLWidget::Scale(float scale_change) {
//  scale(vertex_matrix, scale_change, vertex_count);
  update();
}

void MyOpenGLWidget::ChangeProjection() {
  projection = !projection;
  update();
}

void MyOpenGLWidget::SquarePoints() {
//  z = 0;
  circle_points = false;
  update();
}

void MyOpenGLWidget::CirclePoints() {
//  z = 0;
  circle_points = true;
  update();
}

void MyOpenGLWidget::ShowHidePoints() {
//  z = 0;
  if (show_point) {
    show_point = false;
  } else {
    show_point = true;
  }
  update();
}

void MyOpenGLWidget::PointSizeChange(int size_value) {
//  z = 0;
  point_size += size_value;
  if (point_size <= 0)
    point_size = 1;
  else if (point_size > 50)
    point_size = 50;
  update();
}

void MyOpenGLWidget::DashingLines() {
//  z = 0;
  if (dashed_line) {
    dashed_line = false;
  } else {
    dashed_line = true;
  }
  update();
}

void MyOpenGLWidget::LinesWidthChange(int change_value) {
//  z = 0;
  line_width += change_value;
  if (line_width <= 0)
    line_width = 1;
  else if (line_width > 50)
    line_width = 50;
  update();
}

void MyOpenGLWidget::MakeFace(side* face_ptr, float arr[20]) {
    Singleton& singl = Singleton::getInstance();
    float** matrix = singl.vertMatrix();
  int counter = 0, number;
  for (int i = 0; i < face_ptr->edge_count; i++) {
//    number = (face_ptr->edges[i] > 0) ? (face_ptr->edges[i] - 1)
//                                      : (singl.vertCount() + face_ptr->edges[i]);
      number = face_ptr->edges[i]-1;
    for (int j = 0; j < 3; j++) {
      arr[counter] = matrix[number][j];
      counter++;
    }
  }
}

void MyOpenGLWidget::ChangeBackgroundColor(QColor c) {
  color_ = c;
  update();
}

void MyOpenGLWidget::ChangeLineColor(QColor c) {
  lcolor_ = c;
  update();
}

void MyOpenGLWidget::ChangePointColor(QColor c) {
  pcolor_ = c;
  update();
}

}//namespace s21

#include "myopenglwidget.h"

namespace s21 {

MyOpenGLWidget::MyOpenGLWidget(QWidget* parent) : QOpenGLWidget{parent} {
  circle_points = false;
  show_point = false;
  point_size = 5;
  projection = true;
  dashed_line = false;
  line_width = 1;
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
  float arr[20];
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
  if (sides != nullptr) {
    glColor3d(lcolor_.redF(), lcolor_.greenF(), lcolor_.blueF());
    glLineWidth(line_width);
    glLineStipple(20, 0x0333);
    if (dashed_line) {
      glEnable(GL_LINE_STIPPLE);
    } else if (!dashed_line) {
      glDisable(GL_LINE_STIPPLE);
    }
    while (sides != nullptr) {
      MakeFace(sides, arr);
      glVertexPointer(3, GL_FLOAT, 0, arr);
      glEnableClientState(GL_VERTEX_ARRAY);
      glDrawArrays(GL_LINE_LOOP, 0, sides->edge_count);
      glDisableClientState(GL_VERTEX_ARRAY);
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
      while (sides != nullptr) {
        MakeFace(sides, arr);
        glVertexPointer(3, GL_FLOAT, 0, arr);
        glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_POINTS, 0, sides->edge_count);
        glDisableClientState(GL_VERTEX_ARRAY);
        sides = sides->ptr;
      }
    }
  }
}

void MyOpenGLWidget::Rotate() { update(); }

void MyOpenGLWidget::Move(float value, int axi) { update(); }

void MyOpenGLWidget::Scale(float scale_change) { update(); }

void MyOpenGLWidget::ChangeProjection() {
  projection = !projection;
  update();
}

void MyOpenGLWidget::SquarePoints() {
  circle_points = false;
  update();
}

void MyOpenGLWidget::CirclePoints() {
  circle_points = true;
  update();
}

void MyOpenGLWidget::ShowHidePoints() {
  if (show_point) {
    show_point = false;
  } else {
    show_point = true;
  }
  update();
}

void MyOpenGLWidget::PointSizeChange(int size_value) {
  point_size += size_value;
  if (point_size <= 0)
    point_size = 1;
  else if (point_size > 50)
    point_size = 50;
  update();
}

void MyOpenGLWidget::DashingLines() {
  if (dashed_line) {
    dashed_line = false;
  } else {
    dashed_line = true;
  }
  update();
}

void MyOpenGLWidget::LinesWidthChange(int change_value) {
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
    number = face_ptr->edges[i] - 1;
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

}  // namespace s21

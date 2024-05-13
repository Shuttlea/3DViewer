#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  gifcounter = 1;
  connect(this, &MainWindow::signal, ui->widget,
          &MyOpenGLWidget::MakeVertexArray);
  connect(this, &MainWindow::StopTimer, ui->widget, &MyOpenGLWidget::StopTimer);
  connect(this, &MainWindow::Rotate, ui->widget, &MyOpenGLWidget::Rotate);
  connect(this, &MainWindow::Move, ui->widget, &MyOpenGLWidget::Move);
  connect(ui->ScalePlus, SIGNAL(clicked()), this, SLOT(scalePlusClicked()));
  connect(ui->ScaleMinus, SIGNAL(clicked()), this, SLOT(scaleMinusClicked()));
  connect(this, &MainWindow::ScalePlus, ui->widget, &MyOpenGLWidget::Scale);
  connect(ui->BackColor, &QPushButton::clicked, this,
          &MainWindow::ChangeBackgroundColor);
  connect(ui->LineColor, &QPushButton::clicked, this,
          &MainWindow::ChangeLineColor);
  connect(ui->VerticesColor, &QPushButton::clicked, this,
          &MainWindow::ChangePointColor);
  connect(ui->widget, &MyOpenGLWidget::Info, this, &MainWindow::Info);
  connect(this, &MainWindow::ChangeProjection, ui->widget,
          &MyOpenGLWidget::ChangeProjection);
  settings = new QSettings("21school", "3D_viewer", this);
  LoadSettings();
  connect(ui->SquareVert, SIGNAL(clicked()), this, SLOT(SquarePoints()));
  connect(ui->CircleVert, SIGNAL(clicked()), this, SLOT(CirclePoints()));
  connect(ui->DisablePoints, SIGNAL(clicked()), this, SLOT(ShowPoints()));
  connect(ui->VertPlus, SIGNAL(clicked()), this, SLOT(VertPlusClicked()));
  connect(ui->VertMinus, SIGNAL(clicked()), this, SLOT(VertMinusClicked()));
  connect(ui->DashedLine, SIGNAL(clicked()), this, SLOT(DashLine()));
  connect(ui->LineWidthPlus, SIGNAL(clicked()), this,
          SLOT(LineWidthPlusClicked()));
  connect(ui->LineWidthMinus, SIGNAL(clicked()), this,
          SLOT(LineWidthMinusClicked()));
  dir = QDir::homePath();
  connect(ui->MakeJpeg, SIGNAL(clicked()), this, SLOT(NeedJpeg()));
  connect(ui->MakeBmp, SIGNAL(clicked()), this, SLOT(NeedBmp()));
  connect(ui->MakeGifButt, SIGNAL(clicked()), this, SLOT(NeedGif()));
}

MainWindow::~MainWindow() {
  SaveSettings();
  delete settings;
  delete ui;
}

void MainWindow::on_OpenFileButton_clicked() {
  QFileDialog *qOpenFile = new QFileDialog;

  QString fileName;
  fileName = qOpenFile->getOpenFileName(this, tr("Open Model"), "./models/",
                                        "file (*.obj)", 0,
                                        QFileDialog::DontUseNativeDialog);
  ui->FileNamelineEdit->setText(fileName);
  ui->FileNameInfLineEdit->setText(QFileInfo(fileName).fileName());
  emit signal(fileName);
  delete (qOpenFile);
}

void MainWindow::on_StopButton_clicked() { emit StopTimer(); }

void MainWindow::on_RotateButton_clicked() {
  emit Rotate(ui->RotatelineEdit->text().toFloat(),
              ui->XRotateRB->isChecked()   ? 'x'
              : ui->YRotateRB->isChecked() ? 'y'
                                           : 'z');
}

void MainWindow::on_MoveButton_clicked() {
  emit Move(ui->MovelineEdit->text().toFloat() / 10,
            ui->XMoveRB->isChecked()   ? 1
            : ui->YMoveRB->isChecked() ? 2
                                       : 3);
}

void MainWindow::scalePlusClicked() {
  float scale_change = ui->ScalelineEdit->text().toFloat()
                           ? (1 * ui->ScalelineEdit->text().toFloat())
                           : 1.1;
  emit ScalePlus(scale_change);
}

void MainWindow::scaleMinusClicked() {
  float scale_change = ui->ScalelineEdit->text().toFloat()
                           ? (1 / ui->ScalelineEdit->text().toFloat())
                           : 0.9;
  emit ScalePlus(scale_change);
}

void MainWindow::ChangeBackgroundColor() {
  QColorDialog colorDialog(this);
  auto new_background_color = colorDialog.getColor(Qt::white, this);
  if (new_background_color.isValid()) {
    ui->widget->ChangeBackgroundColor(new_background_color);
  }
}

void MainWindow::ChangeLineColor() {
  QColorDialog colorDialog(this);
  auto new_line_color = colorDialog.getColor(Qt::white, this);
  if (new_line_color.isValid()) {
    ui->widget->ChangeLineColor(new_line_color);
  }
}

void MainWindow::ChangePointColor() {
  QColorDialog colorDialog(this);
  auto new_point_color = colorDialog.getColor(Qt::white, this);
  if (new_point_color.isValid()) {
    ui->widget->ChangePointColor(new_point_color);
  }
}

void MainWindow::SquarePoints() {
  ui->widget->SquarePoints();
  emit SquaredPoint();
}

void MainWindow::CirclePoints() {
  ui->widget->CirclePoints();
  emit CircledPoint();
}

void MainWindow::ShowPoints() {
  ui->widget->ShowHidePoints();
  emit ShowedPoints();
}

void MainWindow::VertPlusClicked() {
  ui->widget->PointSizeChange(1);
  emit VertPlus();
}

void MainWindow::VertMinusClicked() {
  ui->widget->PointSizeChange(-1);
  emit VertMinus();
}

void MainWindow::DashLine() {
  ui->widget->DashingLines();
  emit DashedLine();
}

void MainWindow::LineWidthPlusClicked() {
  ui->widget->LinesWidthChange(1);
  emit LineWidthPlus();
}

void MainWindow::LineWidthMinusClicked() {
  ui->widget->LinesWidthChange(-1);
  emit LineWidthMinus();
}

void MainWindow::MakeScreenShoot() {
  QPixmap pixmap = ui->widget->grab();
  QImage image = pixmap.toImage();
  jiff.append(
      image.scaled(640, 480, Qt::KeepAspectRatio, Qt::SmoothTransformation));
  imagecounter++;
  if (imagecounter >= 50) {
    timer.stop();
    MakeGif();
  } else if (imagecounter == 0 || imagecounter == -1) {
    image.save(dir.absolutePath() + "/Desktop/" +
               QString::number(screenshotcounter++) +
               (imagecounter == 0 ? ".jpeg" : ".bmp"));
    imagecounter = 0;
  }
}

void MainWindow::NeedJpeg() {
  imagecounter = -1;
  MakeScreenShoot();
}

void MainWindow::NeedBmp() {
  imagecounter = -2;
  MakeScreenShoot();
}

void MainWindow::MakeGif() {
  QGifImage *gifim = new QGifImage();
  gifim->setDefaultDelay(100);
  for (const QImage &img : jiff) {
    gifim->addFrame(img);
  }
  gifim->save(dir.absolutePath() + "/Desktop/viewer" +
              QString::number(gifcounter++) + ".gif");
  delete gifim;
  imagecounter = 0;
  jiff.clear();
}

void MainWindow::NeedGif() {
  imagecounter = 0;
  connect(&timer, SIGNAL(timeout()), this, SLOT(MakeScreenShoot()));
  timer.start(100);
}

void MainWindow::SaveSettings() {
  settings->setValue("are_settings", 1);
  settings->setValue("background_color", ui->widget->color_);
  settings->setValue("lines_color", ui->widget->lcolor_);
  settings->setValue("points_color", ui->widget->pcolor_);
  settings->setValue("disable_point", ui->widget->show_point);
  settings->setValue("line_width", ui->widget->line_width);
  settings->setValue("circle_points", ui->widget->circle_points);
  settings->setValue("point_size", ui->widget->point_size);
  settings->setValue("projection", ui->widget->projection);
  settings->setValue("dashed_line", ui->widget->dashed_line);
}

void MainWindow::LoadSettings() {
  if (settings->value("are_settings").toInt()) {
    ui->widget->color_ = settings->value("background_color").value<QColor>();
    ui->widget->lcolor_ = settings->value("lines_color").value<QColor>();
    ui->widget->pcolor_ = settings->value("points_color").value<QColor>();
    ui->widget->show_point = settings->value("disable_point").value<bool>();
    ui->widget->line_width = settings->value("line_width").toInt();
    ui->widget->circle_points = settings->value("circle_points").value<bool>();
    ui->widget->point_size = settings->value("point_size").toInt();
    ui->widget->projection = settings->value("projection").value<bool>();
    ui->widget->dashed_line = settings->value("dashed_line").value<bool>();
  } else {
    ui->widget->color_.setRgb(0, 0, 0, 255);
    ui->widget->lcolor_.setRgb(255, 255, 255, 255);
    ui->widget->pcolor_.setRgb(255, 255, 255, 255);
  }
}

void MainWindow::Info(int edges_count, int vertex_count) {
  ui->EdgeCountLineEdit->setText(QString::number(edges_count));
  ui->VertCountLineEdit->setText(QString::number(vertex_count));
}

void MainWindow::on_ProjectionButton_clicked() { emit ChangeProjection(); }

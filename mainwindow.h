#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <complex>
#include <memory>
#include <stdexcept>

#include "simplemandelbrotframe.h"
#include "fractalcolorizer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_draw_button_clicked();

private:
    Ui::MainWindow *ui;

    std::shared_ptr<MandelbrotFrame> frame;
    std::shared_ptr<FractalColorizer> colorizor;

    std::shared_ptr<QGraphicsScene> scene;
    //std::shared_ptr<QGraphicsView> view;
    std::shared_ptr<QGraphicsPixmapItem> pixmap;
};

#endif // MAINWINDOW_H

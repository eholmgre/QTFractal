#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_draw_button_clicked()
{
    try {
        QString pt1_real_qstr = MainWindow::ui->point1_real_edit->text();
        QString pt1_imag_qstr = MainWindow::ui->point1_imag_edit->text();
        QString pt2_real_qstr = MainWindow::ui->point2_real_edit->text();
        QString pt2_imag_qstr = MainWindow::ui->point2_imag_edit->text();

        bool numeric_parse_sucess = true;

        double pt1_real = pt1_real_qstr.toDouble(&numeric_parse_sucess);
        double pt1_imag = pt1_imag_qstr.toDouble(&numeric_parse_sucess);
        double pt2_real = pt2_real_qstr.toDouble(&numeric_parse_sucess);
        double pt2_imag = pt2_imag_qstr.toDouble(&numeric_parse_sucess);

        if (not numeric_parse_sucess) {
            throw std::runtime_error("Invalid complex points "
                                     + pt1_real_qstr.toStdString() + "+"
                                     + pt1_imag_qstr.toStdString() + "i, "
                                     + pt2_real_qstr.toStdString() + "+"
                                     + pt2_imag_qstr.toStdString() + "i");
        }

        int graphics_width = MainWindow::ui->fractal_graphics->width();
        int graphics_height = MainWindow::ui->fractal_graphics->height();

        SimpleMandelbrotFrame frame(std::complex<double>(pt1_real, pt1_imag),
                    std::complex<double>(pt2_real, pt2_imag),
                    graphics_width, graphics_height);

        auto matrix = frame.computeFrame(64);

        QImage render(QSize(graphics_width, graphics_height),
                      QImage::Format_RGB32);

        for (int i = 0; i < graphics_width; ++i) {
            for (int j = 0; j < graphics_height; ++j) {
                render.setPixel(i, j, matrix[i][j]);
            }
        }

        scene = std::make_shared<QGraphicsScene>();
        //view = std::make_shared<QGraphicsView>(scene.get());
        pixmap = std::make_shared<QGraphicsPixmapItem>(QPixmap::fromImage(render));

        scene.get()->addItem(pixmap.get());
        //view.get()->show();

        MainWindow::ui->fractal_graphics->setScene(scene.get());

    } catch(std::runtime_error e) {
        QMessageBox::critical(this, "Runtime Error", e.what());
    }
}

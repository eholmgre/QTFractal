#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

/*
#include <iostream>

#include "simplemandelbrotframe.h"

int main(int argc, char *argv[])
{

    SimpleMandelbrotFrame m(std::complex<double>(-2, 2),
                            std::complex<double>(2, -2) ,100, 100);

    auto f = m.computeFrame(50);

    std::cout << f << "\n";

    return 0;
}
*/

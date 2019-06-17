#ifndef FRACTALCOLORIZER_H
#define FRACTALCOLORIZER_H

#include <stdexcept>
#include <cmath>


class FractalColorizer
{
    unsigned rng;
    double r_center, r_sdev;
    double g_center, g_sdev;
    double b_center, b_sdev;

    bool rangeCheck(double);
    unsigned gaussCurve(double val, double center, double sdev);

public:
    FractalColorizer(unsigned range, double red_center, double red_sdev,
                     double green_center, double green_sdev,
                     double blue_center, double blue_sdev);

    void setRange(unsigned range) {rng = range;}

    void setRed(double red_center, double red_sdev);
    void setGreen(double green_center, double green_sdev);
    void setBlue(double blue_center, double blue_sdev);

    unsigned operator()(unsigned val);
};

#endif // FRACTALCOLORIZER_H

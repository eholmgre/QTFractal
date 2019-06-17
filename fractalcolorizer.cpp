#include "fractalcolorizer.h"

#include <iostream>

using std::runtime_error, std::exp, std::pow;

FractalColorizer::FractalColorizer(unsigned range, double red_center, double red_sdev,
                     double green_center, double green_sdev,
                     double blue_center, double blue_sdev)
    : rng(range), r_center(red_center), r_sdev(red_sdev), g_center(green_center),
      g_sdev(green_sdev), b_center(blue_center), b_sdev(blue_sdev)
{
    if (not (rangeCheck(r_center) or rangeCheck(r_sdev)
           or rangeCheck(g_center) or rangeCheck(g_sdev)
             or rangeCheck(b_center) or rangeCheck(b_sdev))) {
        throw runtime_error("invalid bounds for fractalColorizer, "
                            "all center and sdev values must be between "
                            "0.0 and 1.0.");
    }
}

void
FractalColorizer::setRed(double red_center, double red_sdev)
{
    if (not (rangeCheck(red_center) or rangeCheck(red_sdev)))
    {
        throw runtime_error("Invalid bounds for red range or sdev."
                            " Values must be between 0.0 and 1.0");
    }

    r_center = red_center;
    r_sdev = red_sdev;
}

void
FractalColorizer::setGreen(double green_center, double green_sdev)
{
    if (not (rangeCheck(green_center) or rangeCheck(green_sdev)))
    {
        throw runtime_error("Invalid bounds for green range or sdev."
                            " Values must be between 0.0 and 1.0");
    }

    g_center = green_center;
    g_sdev = green_sdev;
}

void
FractalColorizer::setBlue(double blue_center, double blue_sdev)
{
    if (not (rangeCheck(blue_center) or rangeCheck(blue_sdev)))
    {
        throw runtime_error("Invalid bounds for blue range or sdev."
                            " Values must be between 0.0 and 1.0");
    }

    g_center = blue_center;
    g_sdev = blue_sdev;
}

unsigned
FractalColorizer::operator()(unsigned val)
{
    if (val == rng) {
        return 0;
    }

    double x = double(val) / double(rng);
    unsigned r = gaussCurve(x, r_center, r_sdev);
    unsigned g = gaussCurve(val, g_center, g_sdev);
    unsigned b = gaussCurve(val, b_center, b_sdev);

    unsigned rgb = 0 | (r << 4) | (g << 2) | b;

    //std::cout << std::hex << rgb << std::dec << std::endl;

    return rgb;

}

bool
FractalColorizer::rangeCheck(double val)
{
    if (val < 0 || val > 1) {
        return false;
    }

    return true;
}

unsigned
FractalColorizer::gaussCurve(double val, double center, double sdev)
{
    return unsigned(255 * exp(pow(-1 * (val - center), 2)
                              / (2 * pow(sdev, 2))));
}

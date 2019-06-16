#ifndef SIMPLEMANDELBROTFRAME_H
#define SIMPLEMANDELBROTFRAME_H

#include "mandelbrotframe.h"


class SimpleMandelbrotFrame : public MandelbrotFrame
{
public:

    SimpleMandelbrotFrame(std::complex<double> pt_1,
                          std::complex<double> pt_2, int width, int height) :
    MandelbrotFrame(pt_1, pt_2, width, height) {};

    array_type computeFrame(uint max_iterations) override;
};

#endif // SIMPLEMANDELBROTFRAME_H

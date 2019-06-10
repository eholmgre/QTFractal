#ifndef MANDELBROTFRAME_H
#define MANDELBROTFRAME_H

#include <complex>
#include <cmath>
#include <stdexcept>

#include "simplematrix.h"

class MandelbrotFrame
{
protected:
    std::complex<double> frame_pt_1;
    std::complex<double> frame_pt_2;

    std::complex<double> frame_stride;

    int frame_width;
    int frame_height;


public:
    MandelbrotFrame(std::complex<double> pt_1,
                    std::complex<double> pt_2, int width, int height);
    
    virtual SimpleMatrix<int> computeFrame(int max_iterations) = 0;
};

#endif // MANDELBROTFRAME_H

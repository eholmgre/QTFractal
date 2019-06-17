#ifndef MANDELBROTFRAME_H
#define MANDELBROTFRAME_H

#include <complex>
#include <cmath>
#include <stdexcept>
#include <boost/multi_array.hpp>


class MandelbrotFrame
{
protected:
    std::complex<double> frame_pt_1;
    std::complex<double> frame_pt_2;

    std::complex<double> frame_stride;

    int frame_width;
    int frame_height;


public:
    typedef boost::multi_array<uint, 2> array_type;

    MandelbrotFrame(std::complex<double> pt_1,
                    std::complex<double> pt_2, int width, int height);

    void setFrame(std::complex<double> pt_1,
                    std::complex<double> pt_2,
                    int width, int height);
    
    virtual array_type computeFrame(uint max_iterations) = 0;
};

#endif // MANDELBROTFRAME_H

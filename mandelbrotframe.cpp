#include "mandelbrotframe.h"

using std::complex, std::runtime_error;

MandelbrotFrame::MandelbrotFrame(complex<double> pt_1, complex<double> pt_2,
                                 int width, int height)
                : frame_pt_1(pt_1), frame_pt_2(pt_2),
                  frame_width(width), frame_height(height)
{
    if (frame_width < 1) {
        throw runtime_error("width must be one or greater");
    }

    if (frame_height < 1) {
        throw runtime_error("height must be one or greater");
    }

    if (frame_pt_1.real() >= frame_pt_2.real()
            or frame_pt_1.imag() <= frame_pt_2.imag()) {
        throw runtime_error("please provide pt_1 that is above\
 and left of pt_2 on the complex plane");
    }

    frame_stride = complex<double>((pt_2.real() - pt_1.real()) / frame_width,
                                   (pt_1.imag() - pt_2.imag()) / frame_height);
}

void
MandelbrotFrame::setFrame(complex<double> pt_1, complex<double> pt_2,
                          int width, int height)
{
    if (frame_width < 1) {
        throw runtime_error("width must be one or greater");
    }

    if (frame_height < 1) {
        throw runtime_error("height must be one or greater");
    }

    if (frame_pt_1.real() >= frame_pt_2.real()
            or frame_pt_1.imag() <= frame_pt_2.imag()) {
        throw runtime_error("please provide pt_1 that is above\
 and left of pt_2 on the complex plane");
    }

    frame_pt_1 = pt_1;
    frame_pt_2 = pt_2;

    frame_width = width;
    frame_height = height;

    frame_stride = complex<double>((pt_2.real() - pt_1.real()) / frame_width,
                                   (pt_1.imag() - pt_2.imag()) / frame_height);
}

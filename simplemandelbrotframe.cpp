#include "simplemandelbrotframe.h"

using std::complex;

MandelbrotFrame::array_type
SimpleMandelbrotFrame::computeFrame(uint max_iterations) {

    array_type matrix(boost::extents[frame_width][frame_height]);

    for (int i = 0; i < frame_width; ++i) {
        for (int j = 0; j < frame_height; ++j) {
            complex<double> c(frame_pt_1.real() + (i * frame_stride.real()),
                              frame_pt_1.imag() - (j * frame_stride.imag()));
            complex<double> z(0, 0);
            uint iter = 0;
            while (std::abs(z) < 2 and iter < max_iterations) {
                z = z * z + c;
                ++iter;
            }
            matrix[i][j] = iter;
        }
    }

    return matrix;
}

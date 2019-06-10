#include "simplemandelbrotframe.h"

using std::complex;

SimpleMatrix<int>
SimpleMandelbrotFrame::computeFrame(int max_iterations) {

    SimpleMatrix<int> frame(frame_width, frame_height);

    for (int i = 0; i < frame_width; ++i) {
        for (int j = 0; j < frame_height; ++j) {
            complex<double> c(frame_pt_1.real() + (i * frame_stride.real()),
                              frame_pt_1.imag() - (j * frame_stride.imag()));
            complex<double> z(0, 0);
            int iter = 0;
            while (std::abs(z) < 2 and iter < max_iterations) {
                z = z * z + c;
                ++iter;
            }
            frame.put(iter, j, i);
        }
    }

    return frame;
}

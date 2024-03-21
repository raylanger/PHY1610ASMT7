#ifndef FFT_H
#define FFT_H

#include <rarray>
#include <fftw3.h>
#include <complex>

void fft_fast(rvector<std::complex<double>>& f, rvector<std::complex<double>>& fhat, bool inverse);

#endif
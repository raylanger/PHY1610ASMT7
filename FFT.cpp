#include "FFT.h"

/* Function for computing fourier transform of a vector f (or inverse) */
void fft_fast(rvector<std::complex<double>>& f, rvector<std::complex<double>>& fhat, bool inverse){

    // Determine size
    const int n = f.size();

    // Control forward or backward fft
    const int sign = inverse*FFTW_BACKWARD+(1-inverse)*FFTW_FORWARD;

    // Create FFT plan
    fftw_plan p = fftw_plan_dft_1d(n,
        reinterpret_cast<fftw_complex*>(f.data()),
        reinterpret_cast<fftw_complex*>(fhat.data()),
        sign,
        FFTW_ESTIMATE);

    fftw_execute(p); //Execute plan
    fftw_destroy_plan(p); //Destroy plan
}
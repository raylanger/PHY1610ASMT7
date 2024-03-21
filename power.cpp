#include "power.h"

/* Function for computing power spectra of fourier transformed vector */
rvector<double> power_spectra(rvector<std::complex<double>> fourier){

    // Initialize vector to hold power spectra
    rvector<double> spectra(fourier.extent(0));
    
    //Iterate through frequencies, add absolute value squared to spectra vector
    for (int i = 0; i < fourier.extent(0); i ++){
        spectra[i] = std::pow(std::abs(fourier[i]),2);
    }

    return spectra;
}
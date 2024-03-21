#include "power.h"

rvector<double> power_spectra(rvector<std::complex<double>> fourier){
    rvector<double> spectra(fourier.extent(0));
    
    for (int i = 0; i < fourier.extent(0); i ++){
        spectra[i] = std::pow(std::abs(fourier[i]),2);
    }

    return spectra;
}
#include "read_file.h"
#include "FFT.h"
#include "power.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace netCDF;

int main(){

    std::string filename_predict = "gwdata/GWprediction.nc";

    rvector<std::complex<double>> predict = read_file(filename_predict);
    rvector<std::complex<double>> FFT_predict(predict.size());

    fft_fast(predict, FFT_predict, false);
    
    rvector<double> predict_power = power_spectra(FFT_predict);
    for (int i = 1; i < 33; i ++){
        std::ostringstream string_setup;
        string_setup << "gwdata/detection" << std::setw(2) << std::setfill('0') << i;
        std::string filename_detect = string_setup.str();
        std::cout << filename_detect << "\n"; 

        rvector<std::complex<double>> detect = read_file(filename_detect);
        rvector<std::complex<double>> FFT_detect(detect.size());

        fft_fast(detect, FFT_detect, false);

        rvector<double> detect_power = power_spectra(FFT_detect);        
    }
    return 0;
}
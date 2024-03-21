#include "read_file.h"
#include "FFT.h"
#include "power.h"
#include "corr.h"
#include "output.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace netCDF;

int main(){

    std::string filename_predict = "gwdata/GWprediction.nc";

    rvector<std::complex<double>> predict = read_file(filename_predict);
    rvector<std::complex<double>> FFT_predict(predict.size());

    fft_fast(predict, FFT_predict, false);
    
    rvector<double> predict_power = power_spectra(FFT_predict);

    rvector<double> correlations(32);

    for (int i = 1; i < 33; i ++){
        std::ostringstream string_setup;
        string_setup << "gwdata/detection" << std::setw(2) << std::setfill('0') << i << ".nc";
        std::string filename_detect = string_setup.str();

        rvector<std::complex<double>> detect = read_file(filename_detect);
        rvector<std::complex<double>> FFT_detect(detect.size());

        fft_fast(detect, FFT_detect, false);

        rvector<double> detect_power = power_spectra(FFT_detect);   

        correlations[i - 1] = correlation(predict_power,detect_power);
    }

    rvector<double> sort_corr = correlations.copy();
    std::sort(sort_corr.begin(),sort_corr.end());

    rvector<int> positions(32);
    for (int i = 0; i < 32; i++){
        for (int j = 0; j < 32; j ++){
            if (sort_corr[i] == correlations[j]){
                positions[i] = j+1;
                break;
            }
        }
    }

    rmatrix<double> corr_matrix(32,2);

    for(int i = 0; i < 32; i++){
        corr_matrix[i][0] = sort_corr[i];
        corr_matrix[i][1] = positions[i];
    }

    output(corr_matrix, "output.txt");
    return 0;
}


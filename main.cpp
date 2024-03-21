#include "main.h"

using namespace netCDF;

int main(){

    // Get filename of prediction file
    std::string filename_predict = "gwdata/GWprediction.nc";

    // Read to rvector predict, initialize rvector for Fourier transform
    rvector<std::complex<double>> predict = read_file(filename_predict);
    rvector<std::complex<double>> FFT_predict(predict.size());

    //Fourier transform predicted signal
    fft_fast(predict, FFT_predict, false);
    
    // Get predicted power spectrum
    rvector<double> predict_power = power_spectra(FFT_predict);

    // Initialize vector to store correlations
    rvector<double> correlations(32);

    // Iterate through detection files
    for (int i = 1; i < 33; i ++){

        // Get filename string - ensure leading 0 present when working with i < 10
        std::ostringstream string_setup;
        string_setup << "gwdata/detection" << std::setw(2) << std::setfill('0') << i << ".nc";
        std::string filename_detect = string_setup.str();

        // Read detection file to vector, initialize rvector for Fourier transform
        rvector<std::complex<double>> detect = read_file(filename_detect);
        rvector<std::complex<double>> FFT_detect(detect.size());

        // Fourier transform detected signal
        fft_fast(detect, FFT_detect, false);

        // Get detected power spectrum
        rvector<double> detect_power = power_spectra(FFT_detect);   

        // Determine correlation between predicted and detected signal and store in correlations rvector
        correlations[i - 1] = correlation(predict_power,detect_power);
    }

    // Create separate rvector which is the sorted correlations vector
    rvector<double> sort_corr = correlations.copy();
    std::sort(sort_corr.begin(),sort_corr.end());

    // Intiailize vector to store positions
    rvector<int> positions(32);

    // Iterate through sorted vector
    for (int i = 0; i < 32; i++){
        // Iterate through unsorted vector
        for (int j = 0; j < 32; j ++){
            //When sorted correlation = unsorted correlation, store position in unsorted array in positions
            if (sort_corr[i] == correlations[j]){
                positions[i] = j+1;
                break;
            }
        }
    }

    //Create matrix containing sorted array and corresponding position in unsorted array
    rmatrix<double> corr_matrix(32,2);

    for(int i = 0; i < 32; i++){
        corr_matrix[i][0] = sort_corr[i];
        corr_matrix[i][1] = positions[i];
    }

    //Output 5 highest correlations and corresponding detection number to .txt file
    output(corr_matrix, "output.txt");


    //Output 5 highest correlations and corresponding detection number to cout
    std::cout << "Detection #\tCorrelation" << "\n";

    for (int i = 31; i > 26; i--){
        std::cout << corr_matrix[i][1] << "\t\t" << corr_matrix[i][0];
        std::cout << "\n"; 
    }
    return 0;
}


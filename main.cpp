#include "read_file.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace netCDF;

int main(){

    std::string filename_predict = "gwdata/GWprediction.nc";

    rvector<std::complex<double>> predict = read_file(filename_predict);

    for (int i = 1; i < 33; i ++){
        std::ostringstream string_setup;
        string_setup << "gwdata/detection" << std::setw(2) << std::setfill('0') << i;
        std::string filename_detect = string_setup.str();
        std::cout << filename_detect << "\n"; 
    }
    return 0;
}
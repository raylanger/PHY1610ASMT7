#include "read_file.h"
#include <iostream>
using namespace netCDF;

int main(){

    std::string filename = "gwdata/detection01.nc";

    rvector<std::complex<double>> detect = read_file(filename);

    std::cout << detect << "\n";
    return 0;
}
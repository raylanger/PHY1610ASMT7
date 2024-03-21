#ifndef READ_H
#define READ_H

#include <netcdf>
#include <rarray>
#include <complex>

rvector<std::complex<double>> read_file(std::string filename);

#endif
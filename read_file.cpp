#include "init.h"
using namespace netCDF;

rvector<std::complex<double>> read_file(std::string filename){
    NcFile ncfile(filename, NcFile::read);
    rvector<std::complex<double>> frvector(ncfile.getDim("nt").getSize());
    ncfile.getVar("f").getVar(frvector.data());
    ncfile.close();

    return frvector;
}
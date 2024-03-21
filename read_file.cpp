#include "read_file.h"
using namespace netCDF;

/* Function for reading gravitational .nc files to rvectors of double-precision complex numbers
*/
rvector<std::complex<double>> read_file(std::string filename){

    // Read get object corresponding to filename
    NcFile ncfile(filename, NcFile::read);

    // Initialize rvector of double-precision complex numbers
    rvector<std::complex<double>> frvector(ncfile.getDim("nt").getSize());

    // Assign data to rvector
    ncfile.getVar("f").getVar(frvector.data());

    //Close file
    ncfile.close();

    return frvector;
}
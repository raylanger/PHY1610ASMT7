#include <fstream>
#include <rarray>

/* Function for outputting 5 highest correlations and their detection numbers to .txt file. */
void output(rmatrix<double> C, const std::string filename){

    // Initialize output file under filename
    std::ofstream out(filename);

    // If the file is open, raise error
    if (!out.is_open()) {
        std::cerr << "Error: " << filename << "is already open, and cannot be used for writing." << std::endl;
        return;
    }

    // Output headers
    out << "Detection #\tCorrelation" << "\n";

    // Output values and detection numbers
    for (int i = 31; i > 26; i--){
        out << C[i][1] << "\t\t" << C[i][0];
        out << "\n"; 
    }
}
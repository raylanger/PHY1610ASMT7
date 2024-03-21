#include "corr.h"

/* Function for getting the inner product of two vectors */
double inner_product(rvector<double> F, rvector<double> G){
    double sum = 0.0; //Initialize sum
    
    // Iterate through elements, add product to sum
    for (int i = 0; i < F.size(); i ++){
        sum += F[i] * G[i];
    }

    return sum;
}

/* Function for determining correlation between two vectors */
double correlation(rvector<double> F, rvector<double> G){

    return inner_product(F,G)/(std::sqrt(inner_product(F,F)*inner_product(G,G)));
}
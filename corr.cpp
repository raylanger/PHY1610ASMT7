#include "corr.h"

double inner_product(rvector<double> F, rvector<double> G){
    double sum = 0.0;
    
    for (int i = 0; i < F.size(); i ++){
        sum += F[i] * G[i];
    }

    return sum;
}

double correlation(rvector<double> F, rvector<double> G){

    return inner_product(F,G)/(std::sqrt(inner_product(F,F)*inner_product(G,G)));
}
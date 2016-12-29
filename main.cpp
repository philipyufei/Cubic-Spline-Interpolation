//
//  main.cpp
//  Cubic-Spline-Interpolation
//
//  Created by Yufei Zhang on 2016-12-30.
//  Copyright © 2016 Yufei Zhang. All rights reserved.
//

#include "interpolation.hpp"
using namespace Interpolation;

int main(int argc, const char * argv[]) {
    // initialize enough space for all inputs
    vector<double> x(4,0);
    vector<double> y(4,0);
    vector<vector<double>> z(4, vector<double>(4,0));
    vector<double> xi(7,0);
    vector<double> yi(7,0);
    vector<vector<double>> zi(7, vector<double>(7,0));
    
    // set up x, y, z, xi, yi
    for (size_t i = 0; i < x.size(); i++) {
        x[i] = i;
        y[i] = i;
        z[3][i] = i*i;
    }
    
    for (size_t i = 0; i < xi.size(); i++) {
        xi[i] = 0.5*i;
        yi[i] = 0.5*i;
    }
    
    // call spline2 to do interpolation for 2D
    spline2(x,y,z,xi,yi,zi);
    
    
    return 0;
}

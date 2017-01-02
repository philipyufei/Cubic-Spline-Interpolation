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
    vector<double> xi(11,0);
    vector<double> yi(11,0);
    vector<vector<double>> zi(11, vector<double>(11,0));
    
    // set up x, y, z, xi, yi
    x[0] = 0;
    x[1] = 1;
    x[2] = 2;
    x[3] = 3;
    
    y[0] = 0;
    y[1] = 1;
    y[2] = 2;
    y[3] = 3;
    
    for (size_t i = 0; i < z.size(); i++) {
        for (size_t j = 0; j < z.size(); j++) {
            z[i][j] = i*i - 2*i*j + j*j;
        }
    }

    for (size_t i = 0; i < xi.size(); i++) {
        xi[i] = 0.5*i;
        yi[i] = 0.5*i;
    }

    // call spline2 to do interpolation for 2D
    spline2(x,y,z,xi,yi,zi);
    
    
    for (size_t i = 0; i < zi.size(); i++) {
        cout << zi[3][i] << " ";
    }
    cout << endl;
    
    
    return 0;
}

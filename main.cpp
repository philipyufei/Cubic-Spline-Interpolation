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
    x[2] = 3;
    x[3] = 4;
    y[0] = 0;
    y[1] = 1;
    y[2] = 3;
    y[3] = 4;
    z[3][0] = 0;
    z[3][1] = 0;
    z[3][2] = 2;
    z[3][3] = 2;
    
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

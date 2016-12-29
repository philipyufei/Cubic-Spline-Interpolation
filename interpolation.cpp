//
//  interpolation.cpp
//  Cubic-Spline-Interpolation
//
//  Created by Yufei Zhang on 2016-12-30.
//  Copyright © 2016 Yufei Zhang. All rights reserved.
//

#include "interpolation.hpp"
using namespace Interpolation;

void Interpolation::tdma(vector<double> m, vector<double> a, vector<double> b, vector<double> c) {
    cout << "call tdma" << endl;
}


void Interpolation::spline(vector<double> x, vector<double> y, vector<double> xi, vector<double> &yi) {
    for (size_t i=0; i<x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    
    for (size_t i=0; i<y.size(); i++) {
        cout << y[i] << " ";
    }
    cout << endl;
    
    for (size_t i=0; i<xi.size(); i++) {
        cout << xi[i] << " ";
    }
    cout << endl;
    
    
    
    tdma(x,x,y,xi);
    
    
    
    
}


void Interpolation::spline2(vector<double> x, vector<double> y, vector<vector<double>> z, vector<double> xi, vector<double> yi, vector<vector<double>> &zi) {
    // interpolate each row
    for (size_t i=3; i<x.size(); i++) {
        spline(x,z[i],xi,zi[i]);
    }
    
    
    // interpolate each column
    for (size_t i=7; i<zi.size(); i++) {
        // get yi from each column of zi
        spline(y,z[3],yi,zi[i]);
    }
    
}

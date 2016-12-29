//
//  interpolation.cpp
//  Cubic-Spline-Interpolation
//
//  Created by Yufei Zhang on 2016-12-30.
//  Copyright © 2016 Yufei Zhang. All rights reserved.
//

#include "interpolation.hpp"
using namespace Interpolation;


// Description: When we do spline interpolation, we usually need to solve Tridiagonal Matrices.
//              Usually, we use Thomas Algorithm (The Tridiagonal Matrix Algorithm)to solve it.
//              TDMA is an algorithm that based on Gaussian Elimination Method.
//              TDMA has two steps: 1. forward elimination; 2. backward subsitution.
// Inputs:      X -> it is the Y vector of the equation MX = Y
//              a -> it is the [m_n+1,n] vector in matrix M
//              b -> it is the [m_n,n]   vector in matrix M
//              c -> it is the [m_n,n+1] vector in matrix M
//                  b0 c0  0
//              M = a1 b1 c1
//                  0  a2 b2
// Output:      X -> it is the X vector of the equation MX = Y
void Interpolation::tdma(vector<double> &M, vector<double> a, vector<double> b, vector<double> c) {
    size_t size = M.size();
    
    // eliminate the first line
    c[0] = c[0] / b[0];
    M[0] = M[0] / b[0];
    
    // eliminate the rest part
    for (int n = 1; n < size; n++) {
        double factor = (b[n] - a[n-1]*c[n-1]);
        c[n] = c[n] / factor;
        M[n] = (M[n] - a[n-1] * M[n - 1]) / factor;
    }
    
    // substitute from the second last line because X[size-1] is already the solution
    for (size_t n = size-2; n > -1; n--) {
        M[n] = M[n] - c[n] * M[n + 1];
    }
}


// Description: this function need four inputs and it change the zi matrix when processing.
//              This function does the same thing as interp1(x,z,xi,'spline') in MATLAB.
// Inputs:      x  -> x(:,1) where x = start:old_res:end in MATLAB.
//              z  -> it is the same as z in MATLAB while doing interpolation
//              xi -> xi(:,1) where xi = start:new_res:end in MATLAB.
//              zi -> it is the return value of interp2(x,z,xi) in MATLAB
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
    
    // calculate hi
    
    // calculate a, b, c
    
    // calculate d
    
    // call tdma(d, a, b, c)
    tdma(x,x,y,xi);
    
    // get sk1, sk2, sk3, sk4 to get S(x) for eahc range
    
    // for each range of xi < x < xi+1, run S(x)
    
    
}


// Description: this function need six inputs, five of them are inputs and  zi is the output.
//              This function does the same thing as interp2(..., 'spline') in MATLAB.
// Inputs:      x  -> x(:,1) where [x,y] = meshgrid(start:res:end) in MATLAB.
//              y  -> y(1,:) where [x,y] = meshgrid(start:res:end) in MATLAB.
//              z  -> it is the same as z in MATLAB while doing interpolation
//              xi -> xi(:,1) where [xi,yi] = meshgrid(start:new_res:end) in MATLAB.
//              yi -> yi(1,:) where [xi,yi] = meshgrid(start:new_res:end) in MATLAB.
//              zi -> it is the return value of interp2(..., 'spline') in MATLAB
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

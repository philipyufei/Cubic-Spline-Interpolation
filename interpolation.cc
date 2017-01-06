//
//  interpolation.cc
//  Cubic-Spline-Interpolation
//
//  Created by Yufei Zhang on 2016-12-30.
//  Copyright © 2016 Yufei Zhang. All rights reserved.
//


#include "interpolation.h"
#include <math.h>


// Description: When we do spline interpolation, we usually need to solve
//                Tridiagonal Matrices.
//              Usually, we use Thomas Algorithm (The Tridiagonal Matrix
//                Algorithm)to solve it.
//              TDMA is an algorithm that based on Gaussian Elimination Method.
//              TDMA has two steps:
//                1. forward elimination;
//                2. backward subsitution.
// Inputs:      X -> it is the Y vector of the equation MX = Y
//              a -> it is the [m_n+1,n] vector in matrix M
//              b -> it is the [m_n,n]   vector in matrix M
//              c -> it is the [m_n,n+1] vector in matrix M
//              mfl -> the value of row 0 and column 2   of the matrix M
//              mll -> the value of row n and column n-2 of the matrix M
//                  b0 c0  0
//              M = a1 b1 c1
//                  0  a2 b2
// Output:      X -> it is the X vector of the equation MX = Y
void interpolation::TDMA(vector<double> &M, vector<double> a, vector<double> b,
                       vector<double> c, double mfl, double mll) {
  size_t size = M.size();
  
  // eliminate the first line
  c[0] = c[0] / b[0];
  mfl = mfl / b[0];
  M[0] = M[0] / b[0];
  c[1] -= mfl;
    
  // eliminate midium lines
  for (size_t n = 1; n < size-1; n++) {
    b[n] = b[n] - c[n - 1] * a[n];
    c[n] = c[n] / b[n];
    M[n] = (M[n] - a[n] * M[n - 1]) / b[n];
  }
    
  // eliminate the last line
  a[size - 1] -= c[size - 3] * mll;
  M[size - 1] -= M[size - 3] * mll;
  M[size - 1] = (M[size - 1] - M[size - 2] * a[size - 1]) /
    (b[size - 1] - c[size - 2] * a[size - 1]);
    
  // substitute from the second last line as X[size-1] is already the solution
  for (rsize_t n = size-2; n > 0; n--) {
    M[n] = M[n] - c[n] * M[n + 1];
  }
  M[0] -= (c[0] * M[1] + mfl * M[2]);
}


// Description: function needs four inputs to change zi matrix when processing.
//              It does the same thing as interp1(x,z,xi,'spline') in MATLAB.
// Inputs:      x  -> x(:,1) where x = start:old_res:end in MATLAB.
//              z  -> it is the same as z in MATLAB while doing interpolation
//              xi -> xi(:,1) where xi = start:new_res:end in MATLAB.
//              zi -> it is the return value of interp2(x,z,xi) in MATLAB
void interpolation::Spline(vector<double> x, vector<double> y, vector<double> xi,
                         vector<double> &yi) {
  // get the size of the interpolation
  size_t size, last;
  size = x.size();
  last = size - 1;
    
  // calculate hi and di
  vector<double> h(last, 0);
  vector<double> d(last, 0);
  for (size_t i = 0; i < last; i++) {
    h[i] = x[i + 1] - x[i];
    d[i] = (y[i + 1] - y[i]) / h[i];
  }
    
    // get matrix X -=> a, b, c only, and Y where XM = Y
    //     b0 c0 xx  0  0
    //     a1 b1 c1  0  0
    // X = 0  a2 b2 c2  0, where xx is some value, we need to eliminate them
    //     0  0  a3 b3 c3
    //     0  0  xx a4 b4
    vector<double> a(size, 0);
    vector<double> b(size, 0);
    vector<double> c(size, 0);
    vector<double> Y(size, 0);
    for (size_t i = 1; i < last; i++) {
        a[i] = h[i-1];
        b[i] = 2 * (h[i-1]+h[i]);
        c[i] = h[i];
        Y[i] = 6 * (d[i] - d[i-1]);
    }
    
  // convert X to a tridiagonal matrix and the coresponding vector Y
  b[0] = -h[1];
  c[0] = (h[0] + h[1]);
  a[last] = (h[last - 2] + h[last - 1]);
  b[last] = (-h[last - 2]);
  double mfl = -h[0];
  double mll = -h[last-1];
    
  // call tdma to solve M where XM = Y => M = Y because of tdma function
  TDMA(Y, a, b, c, mfl, mll);
    
  // calculate Sk(x), where k = 0, 1, ..., n-1.
  // Sk(x) = sk0 + sk1*(x - xk) + sk2*(x-xk)^2 + sk3*(x -xk)^3;
  double sk0;
  double sk1;
  double sk2;
  double sk3;
  size_t k = 0;
  for (size_t i = 0; i < xi.size(); i++) {
    if (xi[i] >= x[k+1] && k+1 < last) {
      k++;
    }
    // calculate Sk(x)
    sk0 = y[k];
    sk1 = d[k] - h[k] / 6 * (2 * Y[k] + Y[k + 1]);
    sk2 = Y[k] / 2;
    sk3 = (Y[k + 1] - Y[k]) / 6 / h[k];
    yi[i] = sk0 + sk1*(xi[i] - x[k]) + sk2*pow((xi[i] - x[k]), 2) +
      sk3*pow((xi[i] - x[k]), 3);
  }
}


// Description: Function need six inputs to change values in zi.
//              It does the same thing as interp2(..., 'spline') in MATLAB.
// Inputs:      x ->x(:,1) where [x,y] = meshgrid(start:res:end) in MATLAB.
//              y ->y(1,:) where [x,y] = meshgrid(start:res:end) in MATLAB.
//              z ->it is the same as z in MATLAB while doing interpolation
//              xi->xi(:,1) where [xi,yi]=meshgrid(start:new_res:end) in MATLAB.
//              yi->yi(1,:) where [xi,yi]=meshgrid(start:new_res:end) in MATLAB.
//              zi->it is the return value of interp2(..., 'spline') in MATLAB
void interpolation::Spline2(vector<double> x, vector<double> y,
                          vector<vector<double>> z, vector<double> xi,
                          vector<double> yi, vector<vector<double>> &zi) {
  
  // do interpolation 1D every row then every column
  vector<double> vector_current_z(z.size());
  vector<double> vector_current_zi(zi.size());
  
  // interpolate every row
  for (size_t i = 0; i < x.size(); i++) {
    Spline(x, z[i], xi, zi[i]);
  }
  
  // interpolate every column
  for (size_t i = 0; i < xi.size(); i++) {
    for (size_t j = 0; j < x.size(); j++) {
      vector_current_z[j] = zi[j][i];
    }
    Spline(y, vector_current_z, yi, vector_current_zi);
    for (size_t k = 0; k < xi.size(); k++) {
      zi[k][i] = vector_current_zi[k];
    }
  }
}

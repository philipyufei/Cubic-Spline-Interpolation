//
//  interpolation.h
//  Cubic-Spline-Interpolation
//
//  Created by Yufei Zhang on 2016-12-30.
//  Copyright © 2016 Yufei Zhang. All rights reserved.
//

#ifndef interpolation_h
#define interpolation_h


#include <iostream>
#include <vector>


using namespace std;


// This namespace includes five functions to do interpolatio.
// The first two of them are for 1D interpolation.
// The next two of them are for 2D interpolation.
// The last one is an algorithm to solve tridiagonal matrices
// 1. Linear2 -> linear interpolation 2D
// 2. Spline2 -> spline interpolation 2D
// 3. Linear  -> linear interpolation 1D
// 4. Spline  -> spline interpolation 1D
// 5. TDMA    -> Thomas Algorithm
namespace interpolation {
    void TDMA(vector<double> &M, vector<double> a, vector<double> b,
              vector<double> c, double mfl, double mll);
    void Spline(vector<double> x, vector<double> y,
                vector<double> xi, vector<double> &yi);
    void Spline2(vector<double> x, vector<double> y, vector<vector<double>> z,
                 vector<double> xi,vector<double> yi,vector<vector<double>>&zi);
}

#endif /* interpolation_hpp */

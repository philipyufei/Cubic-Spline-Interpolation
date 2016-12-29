//
//  interpolation.hpp
//  Cubic-Spline-Interpolation
//
//  Created by Yufei Zhang on 2016-12-30.
//  Copyright © 2016 Yufei Zhang. All rights reserved.
//

#ifndef interpolation_hpp
#define interpolation_hpp


#include <iostream>
#include <vector>


using namespace std;


// This namespace includes five functions to do interpolatio.
// The first two of them are for 1D interpolation and next two of them are for 2D interpolation.
// The last one is an algorithm to solve tridiagonal matrices
// 1. linear2 -> linear interpolation 2D
// 2. spline2 -> spline interpolation 2D
// 3. linear1 -> linear interpolation 1D
// 4. spline1 -> spline interpolation 1D
// 5. tama    -> Thomas Algorithm
namespace Interpolation {
    void tdma(vector<double> &M, vector<double> a, vector<double> b, vector<double> c);
    void spline(vector<double> x, vector<double> y, vector<double> xi, vector<double> &yi);
    void spline2(vector<double> x, vector<double> y, vector<vector<double>> z, vector<double> xi, vector<double> yi, vector<vector<double>> &zi);
}

#endif /* interpolation_hpp */

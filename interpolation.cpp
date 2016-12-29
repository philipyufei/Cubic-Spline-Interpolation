//
//  interpolation.cpp
//  Cubic-Spline-Interpolation
//
//  Created by Yufei Zhang on 2016-12-30.
//  Copyright © 2016 Yufei Zhang. All rights reserved.
//

#include "interpolation.hpp"
using namespace Interpolation;

void Interpolation::spline2(vector<double> x, vector<double> y, vector<vector<double>> z, vector<double> xi, vector<double> yi, vector<vector<double>> &zi) {
    spline(x,y,xi);
}

void Interpolation::spline(vector<double> x, vector<double> y, vector<double> xi) {
    tdma(x,x,y,xi);
}

void Interpolation::tdma(vector<double> m, vector<double> a, vector<double> b, vector<double> c) {
    cout << m[0] << endl;
}

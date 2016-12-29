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

namespace Interpolation {
    void tdma(vector<double> &M, vector<double> a, vector<double> b, vector<double> c);
    void spline(vector<double> x, vector<double> y, vector<double> xi, vector<double> &yi);
    void spline2(vector<double> x, vector<double> y, vector<vector<double>> z, vector<double> xi, vector<double> yi, vector<vector<double>> &zi);
}

#endif /* interpolation_hpp */

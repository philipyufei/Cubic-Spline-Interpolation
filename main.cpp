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
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<double> x(2,0);
    vector<double> y(2,0);
    vector<vector<double>> z(2, vector<double>(2,0));
    vector<double> xi(2,0);
    vector<double> yi(2,0);
    vector<vector<double>> zi(2, vector<double>(2,0));
    
    spline2(x,y,z,xi,yi,zi);
    
    return 0;
}

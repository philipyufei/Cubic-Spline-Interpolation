//
//  main.cc
//  Cubic-Spline-Interpolation
//
//  Created by Yufei Zhang on 2016-12-30.
//  Copyright © 2016 Yufei Zhang. All rights reserved.
//

#include "interpolation.h"
using namespace interpolation;

int main(int argc, const char * argv[]) {
  clock_t start, stop;
  // set bounds of input matrix and output matrix
  double num_start    = 0.00;
  double num_end      = 3.00;
  double num_old_res  = 1.00;
  double num_new_res  = 0.30;
  double num_old_size = (num_end - num_start) / num_old_res + 1;
  double num_new_size = (num_end - num_start) / num_new_res + 1;
  
  // initialize four vectors and two matrix
  vector<double> vector_x(num_old_size, 0);
  vector<double> vector_y(num_old_size, 0);
  vector<vector<double>> matrix_z(num_old_size,vector<double>(num_old_size,0));
  vector<double> vector_xi(num_new_size, 0);
  vector<double> vector_yi(num_new_size, 0);
  vector<vector<double>> matrix_zi(num_new_size,vector<double>(num_new_size,0));
  
  // set [x,y] = meshgrid(start:old_res:end), z = x^2 - 2xy + y^2
  for (int i = 0; i < num_old_size; ++i) {
    vector_x[i] = num_start + i*num_old_res;
    vector_y[i] = num_start + i*num_old_res;
    for (int j = 0; j < num_old_size; ++j) {
      matrix_z[i][j] = i*i - 2*i*j + j*j + 2*i -3 * j;
    }
  }
  
  // set [xi, yi] = meshgrid(start:new_res:end)
  for (int i = 0; i < num_new_size; ++i) {
    vector_xi[i] = num_start + i*num_new_res;
    vector_yi[i] = num_start + i*num_new_res;
  }
  
  // do linear interpolation to update zi
  //linear(vector_x, vector_y, matrix_z, vector_xi, vector_yi, matrix_zi);
  
  // do cubic spline interpolation to update zi
  
  start = clock();
  Spline2(vector_x, vector_y, matrix_z, vector_xi, vector_yi, matrix_zi);
  stop = clock();

  // print the output of zi
  for (int i = 0; i < num_new_size; ++i) {
    for (int j = 0; j < num_new_size; ++j) {
      cout << matrix_zi[i][j] << " ";
    }
    cout << endl;
  }

  std::cout << "Time spend: " << (double)(stop - start)/1000.00 << std::endl;
  
  return 0;
}

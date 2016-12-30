# Cubic-Spline-Interpolation

This is a function to show how interpolation works and how to convert a MATLAB inperp2('spline') to C++.
 
## A Note On Cubic Splines
 
 MATLAB's interp1 when you specify the spline flag assumes that the end point conditions are not-a-knot.
 
 The algorithm specified on Wikipedia is the code for a natural spline.


http://blog.csdn.net/skykingf/article/details/45536231

http://blog.csdn.net/kaitiren/article/details/38513715

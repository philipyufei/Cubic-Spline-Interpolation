# Cubic-Spline-Interpolation
This is a function to show how interpolation works and how to convert a MATLAB inperp2('spline') to C++.


## Important Note On Cubic Splines
 
 MATLAB's interp1 when you specify the spline flag assumes that the end point conditions are ***not-a-knot***.
 
 The algorithm specified on Wikipedia is the code for a ***natural*** spline.
 
 
## Compiling and Running
### 	To compile, you simply need to type 'make' on you terminal.

###		However, if you have already make once, you need to typle 'make clean' before your second compiling.


###		To run it, you need to type 'cubic-spline-interpolation' on your terminal.
 

## References

[A Note On Cubic Splines][note1]
[note1]:http://www.cs.tau.ac.il/~turkel/notes/numeng/spline_note.pdf

1. http://blog.csdn.net/skykingf/article/details/45536231

2. http://blog.csdn.net/kaitiren/article/details/38513715

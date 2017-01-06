all: cubic-spline-interpolation

cubic-spline-interpolation:
	g++ -std=c++11 -Wall main.cc interpolation.cc -o cubic-spline-interpolation

clean:
	rm -rf cubic-spline-interpolation

#include "geometry.h"
#include<cmath>

double S_circle(double R) {
	return pi * R * R;
}

double P_circle(double R) {
	return 2 * pi * R;
}

double S_rect(double a, double b) {
	return a * b;
}

double P_rect(double a, double b) {
	return 2 * (a + b);
}

double distance_between_points(double x1, double y1, double x2, double y2) {
	double dx{ x1 - x2 }; double dy{ y1 - y2 };
	double dist{ std::sqrt(pow(dx, 2) + pow(dy, 2)) };
	return dist;
}

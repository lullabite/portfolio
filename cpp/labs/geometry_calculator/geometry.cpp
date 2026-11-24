#include "geometry.h"

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
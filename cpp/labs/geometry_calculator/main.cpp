#include<iostream>
#include "geometry.h"

void clearInput() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}

int main() {
	int num{-1};
	while (num != 0) {
		std::cout << "Pick a number: 1 - circle, 2 - rectangle, 3 - distance between 2 points, 0 - exit" << "\n";
		std::cin >> num;
		while (!std::cin || num < 0 || num > 3) {
			clearInput();
			std::cout << "Wrong input. Pick 0, 1, 2 or 3: ";
			std::cin >> num;
		}
		clearInput();

		if (num == 1) {
			double R{};
			std::cout << "Enter the radius: ";
			std::cin >> R;
			while (!std::cin || R <= 0) {
				clearInput();
				std::cout << "Wrong input. Enter the radius again: ";
				std::cin >> R;
			}
			clearInput();

			std::cout << "S = " << S_circle(R) << "\n";
			std::cout << "P = " << P_circle(R) << "\n";
		}

		if (num == 2) {
			double a{};
			double b{};
			std::cout << "Enter the side a: ";
			std::cin >> a;
			while (!std::cin || a <= 0) {
				clearInput();
				std::cout << "Wrong input. Enter the side again: ";
				std::cin >> a;
			}
			clearInput();

			std::cout << "Enter the side b: ";
			std::cin >> b;
			while (!std::cin || b <= 0) {
				clearInput();
				std::cout << "Wrong input. Enter the side again: ";
				std::cin >> b;
			}
			clearInput();

			std::cout << "S = " << S_rect(a, b) << "\n";
			std::cout << "P = " << P_rect(a, b) << "\n";
		}

		if (num == 3) {
			double x1{}; double y1{};
			double x2{}; double y2{};
			std::cout << "Enter the first point (x, y): ";
			std::cin >> x1 >> y1;
			while (!std::cin) {
				clearInput();
				std::cout << "Wrong input. Enter the first point again: ";
				std::cin >> x1 >> y1;
			}
			clearInput();

			std::cout << "Enter the second point (x, y): ";
			std::cin >> x2 >> y2;
			while (!std::cin) {
				clearInput();
				std::cout << "Wrong input. Enter the second point again: ";
				std::cin >> x2 >> y2;
			}
			clearInput();

			double dist{ distance_between_points(x1, y1, x2, y2) };
			std::cout << "Distance = " << dist << "\n";
		}
	}
	return 0;
}

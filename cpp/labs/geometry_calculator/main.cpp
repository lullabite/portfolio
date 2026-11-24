#include<iostream>
#include "geometry.h"

void clearInput() {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}

int main() {
	int num{-1};
	while (num != 0) {
		std::cout << "Pick a number: 1 - circle, 2 - rectangle, 0 - exit" << "\n";
		std::cin >> num;
		while (!std::cin || num < 0 || num > 2) {
			clearInput();
			std::cout << "Wrong input. Pick 0, 1 or 2: ";
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
	}
	return 0;
}
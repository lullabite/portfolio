#include <iostream>
#include <cmath>

class Cube
{
private:
    double edge;

public:
    void input()
    {
        std::cout << "Enter cube edge: ";
        std::cin >> edge;
    }

    double surface_area()
    {
        return 6 * edge * edge;
    }
};

class Prism
{
private:
    double side;
    double height;

public:
    void input()
    {
        std::cout << "Enter prism side: ";
        std::cin >> side;

        std::cout << "Enter prism height: ";
        std::cin >> height;
    }

    double surface_area()
    {
        return 2 * side * side + 4 * side * height;
    }
};

class Parall
{
private:
    double a, b, c;

public:
    void input()
    {
        std::cout << "Enter 3 edges of parallelepiped (a b c): ";
        std::cin >> a >> b >> c;
    }

    double surface_area()
    {
        return 2 * (a * b + b * c + a * c);
    }
};

int main()
{
    Cube my_cube;
    Prism my_prism;
    Parall my_parall;

    my_cube.input();
    std::cout << "Cube surface area: "
        << my_cube.surface_area() << "\n\n";

    my_prism.input();
    std::cout << "Prism surface area: "
        << my_prism.surface_area() << "\n\n";

    my_parall.input();
    std::cout << "Parallelepiped surface area: "
        << my_parall.surface_area() << "\n";

    return 0;
}

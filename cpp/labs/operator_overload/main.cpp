#include <iostream>

struct Vector {
    double x, y, z;

    Vector operator&(const Vector& other) const {
        Vector res;
        res.x = this->y * other.z - other.y * this->z;
        res.y = this->z * other.x - other.z * this->x;
        res.z = this->x * other.y - other.x * this->y;
        return res;
    }
};

void inputVector(const char* name, Vector* v) {
    std::cout << "Enter coordinates for " << name << " (x y z): ";
    std::cin >> v->x >> v->y >> v->z;
}

void printVector(const char* name, Vector v) {
    std::cout << name << " = {"
        << v.x << ", "
        << v.y << ", "
        << v.z << "}\n";
}

int main() {
    Vector a, b, c;

    inputVector("Vector A", &a);
    inputVector("Vector B", &b);

    c = a & b;

    printVector("A", a);
    printVector("B", b);
    std::cout << "(A & B):\n";
    printVector("C", c);

    return 0;
}

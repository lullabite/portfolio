#include <iostream>
#include <fstream>
#include "matrix.h"

int main()
{
    double R[MAX_SIZE][MAX_SIZE] = {};
    double A[MAX_SIZE][MAX_SIZE] = {};
    double T[MAX_SIZE][MAX_SIZE] = {};

    double RT[MAX_SIZE][MAX_SIZE] = {};
    double temp[MAX_SIZE][MAX_SIZE] = {};
    double F[MAX_SIZE][MAX_SIZE] = {};

    int rowsR, colsR;
    int rowsA, colsA;
    int rowsT, colsT;

    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    if (!input.is_open() || !output.is_open())
    {
        std::cout << "Error opening the file.\n";
        return 1;
    }

    readMatrix(input, R, rowsR, colsR);
    readMatrix(input, A, rowsA, colsA);
    readMatrix(input, T, rowsT, colsT);

    input.close();

    transpose(R, RT, rowsR, colsR);

    multiply(RT, T, temp,
        colsR, rowsR,
        rowsT, colsT);

    multiplyByNumber(temp, 0.5, rowsR, colsT);

    subtract(temp, A, F, rowsA, colsA);

    std::cout << "Matrix F:\n";

    printMatrix(output, F, rowsA, colsA);

    output.close();

    return 0;
}

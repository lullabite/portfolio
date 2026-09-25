#include "matrix.h"
#include <iostream>

void readMatrix(std::ifstream& file,
    double matrix[MAX_SIZE][MAX_SIZE],
    int& rows, int& cols)
{
    file >> rows >> cols;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            file >> matrix[i][j];
        }
    }
}

void printMatrix(std::ofstream& file,
    double matrix[MAX_SIZE][MAX_SIZE],
    int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << "\t";
            file << matrix[i][j] << "\t";
        }

        std::cout << "\n";
        file << "\n";
    }
}

void transpose(double matrix[MAX_SIZE][MAX_SIZE],
    double result[MAX_SIZE][MAX_SIZE],
    int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

void multiply(double first[MAX_SIZE][MAX_SIZE],
    double second[MAX_SIZE][MAX_SIZE],
    double result[MAX_SIZE][MAX_SIZE],
    int rowsFirst, int colsFirst,
    int rowsSecond, int colsSecond)
{
    for (int i = 0; i < rowsFirst; i++)
    {
        for (int j = 0; j < colsSecond; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < colsFirst; k++)
            {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void multiplyByNumber(double matrix[MAX_SIZE][MAX_SIZE],
    double number,
    int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] *= number;
        }
    }
}

void subtract(double first[MAX_SIZE][MAX_SIZE],
    double second[MAX_SIZE][MAX_SIZE],
    double result[MAX_SIZE][MAX_SIZE],
    int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = first[i][j] - second[i][j];
        }
    }
}

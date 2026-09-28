#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

const int MAX_SIZE = 3;

void readMatrix(std::ifstream& file,
    double matrix[MAX_SIZE][MAX_SIZE],
    int& rows, int& cols);

void printMatrix(std::ofstream& file,
    double matrix[MAX_SIZE][MAX_SIZE],
    int rows, int cols);

void transpose(double matrix[MAX_SIZE][MAX_SIZE],
    double result[MAX_SIZE][MAX_SIZE],
    int rows, int cols);

void multiply(double first[MAX_SIZE][MAX_SIZE],
    double second[MAX_SIZE][MAX_SIZE],
    double result[MAX_SIZE][MAX_SIZE],
    int rowsFirst, int colsFirst,
    int rowsSecond, int colsSecond);

void multiplyByNumber(double matrix[MAX_SIZE][MAX_SIZE],
    double number,
    int rows, int cols);

void subtract(double first[MAX_SIZE][MAX_SIZE],
    double second[MAX_SIZE][MAX_SIZE],
    double result[MAX_SIZE][MAX_SIZE],
    int rows, int cols);

#endif

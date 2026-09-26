#include <iostream>
#include <cmath>
#include "dxf_out.cpp"

const double PI = 3.14159265358979323846;

void drawHexagonWithNodes(FILE* dxf, double cx, double cy, double R, double rSmall)
{
    double points[6][3];

    for (int i = 0; i < 6; i++)
    {
        double angle = i * (2.0 * PI / 6.0);

        points[i][0] = cx + R * cos(angle);
        points[i][1] = cy + R * sin(angle);
        points[i][2] = 0.0;

        dxf_circle(dxf, points[i], rSmall);
    }

    for (int i = 0; i < 6; i++)
    {
        int next = (i + 1) % 6;
        dxf_line(dxf, points[i], points[next]);
    }
}

int main()
{
    FILE* dxf = dxf_init("var3.dxf");

    if (dxf == nullptr)
    {
        std::cerr << "Error creating DXF file.\n";
        return 1;
    }

    dxf_color = CYAN;
    drawHexagonWithNodes(dxf, -80.0, 50.0, 70.0, 7.0);

    dxf_color = MAGENTA;
    drawHexagonWithNodes(dxf, 100.0, -60.0, 40.0, 4.0);

    dxf_color = BLUE;
    drawHexagonWithNodes(dxf, 10.0, -140.0, 55.0, 10.0);

    dxf_end(dxf);

    std::cout << "Done! Check var3.dxf.\n";

    return 0;
}

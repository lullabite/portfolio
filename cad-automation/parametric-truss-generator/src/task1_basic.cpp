#include <iostream>
#include <fstream>
#include <vector>
#include "dxf_out.cpp"

int main() {
    std::vector<double> coor;
    std::vector<int> top;

    double pt1[2], pt2[2];
    int i, nuz, kuzl, kel;

    const char* pathcoor = "coor.txt";
    const char* pathtop = "top.txt";
    const char* pathscr = "ferma.dxf";

    std::ifstream cdat(pathcoor);

    if (!cdat.is_open()) {
        std::cout << "Cannot open the file " << pathcoor << std::endl;
        return 1;
    }

    cdat >> kuzl;

    std::cout << "KUZL=" << kuzl;

    coor.resize(kuzl * 2);

    for (i = 0; i < kuzl * 2; i++) {
        cdat >> coor[i];
    }

    cdat.close();

    std::ifstream tdat(pathtop);

    if (!tdat.is_open()) {
        std::cout << "Cannot open the file " << pathtop << std::endl;
        return 1;
    }

    tdat >> kel;

    std::cout << "\nKEL=" << kel << std::endl;

    top.resize(kel * 2);

    for (i = 0; i < kel * 2; i++) {
        tdat >> top[i];
    }

    tdat.close();

    FILE* dscr = dxf_init(pathscr);

    for (i = 0; i < kel * 2; i += 2) {
        nuz = top[i];

        pt1[0] = coor[(nuz - 1) * 2];
        pt1[1] = coor[(nuz - 1) * 2 + 1];

        nuz = top[i + 1];

        pt2[0] = coor[(nuz - 1) * 2];
        pt2[1] = coor[(nuz - 1) * 2 + 1];

        dxf_line(dscr, pt1, pt2);
    }

    dxf_end(dscr);

    std::cout << "\nFile " << pathscr << " is created successfully" << std::endl;

    return 0;
}

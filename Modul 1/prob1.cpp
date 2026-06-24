#include <iostream>
#include <string>
#include "line.h"

int main() {
    Line l;
    Point p;

    std::cin >> l.a >> l.b >> l.c >> p.x >> p.y;

    double hasil_grad = gradient(&l, &p);
    std::string posisi = CheckPointPosition(hasil_grad);

    std::cout << posisi << std::endl;

    return 0;
}
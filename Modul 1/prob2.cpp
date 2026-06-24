#include <iostream>
#include <string>
#include "circle.h"

int main() {
    Circle C;
    Point P;

    std::cin >> C.centre.x >> C.centre.y >> C.radius >> P.x >> P.y;
        double d = distance(&C, &P);
        
        std::string hasil = CheckPointInCircle(d, C.radius);
        
        std::cout << hasil << std::endl;

    return 0;
}
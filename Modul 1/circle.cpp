#include "circle.h"
#include <cmath>

double distance(const Circle *c, const Point *p) {
    double dx = p->x - c->centre.x;
    double dy = p->y - c->centre.y;
    return std::sqrt(dx * dx + dy * dy);
}

std::string CheckPointInCircle(double dist, double radius) {
    double selisih = dist - radius;

    if (std::abs(selisih) < EPSILON) {
        return "On Circle";
    } 
    else if (dist < radius) {
        return "Inside";
    } 
    else {
        return "Outside";
    }
}
#include "line.h"
double gradient(const Line *l, const Point *p) {
    return (l->a * p->x) + (l->b * p->y) + l->c;
}

std::string CheckPointPosition(double grad) {
    if (grad > 1e-9) {
        return "Left";  
    } else if (grad < -1e-9) {
        return "Right"; 
    } else {
        return "On Line";
    }
}
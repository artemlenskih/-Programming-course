#include "lab10.h"
int has_min(struct Parabola p) {
    if (p.a > 0) {
        return 1;
    }
    else {
        return 0;
    }
}

float min(struct Parabola p) {
    float x;
    x = -p.b / (2.0 * p.a);
    return p.a * x * x + p.b * x + p.c;
}
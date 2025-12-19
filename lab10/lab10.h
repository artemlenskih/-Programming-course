#define PARABOLA_H

struct Parabola {
    int a;
    int b; 
    int c;
};

int has_min(struct Parabola p);
float min(struct Parabola p);
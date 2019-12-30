//
// Created by root on 12/28/19.
//

#ifndef CPPSSWIMPL_SAMPLE_H
#define CPPSSWIMPL_SAMPLE_H
#include <math.h>

extern int gcd(int, int);
extern int in_mandel(double x0, double y0, int n);
extern int divide(int a, int b, int *remainder);
extern double avg(double *a, int n);

typedef struct Point {
    double x,y;
} Point;

extern double distance(Point *p1, Point *p2);
#endif //CPPSSWIMPL_SAMPLE_H

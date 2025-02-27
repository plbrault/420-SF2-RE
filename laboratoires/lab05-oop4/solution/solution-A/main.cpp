#include <iostream>
#include <iomanip>
#include <cmath>

#include "point.h"
#include "triangle.h"

#include <iostream>
#include <iomanip>

#include "forme2d.h"
#include "point.h"
#include "triangle.h"
#include "quadrilatere.h"

int main () {
    Triangle a;
    a[0][0] = 0.0;
    a[0][1] = 0.0;
    a[1][0] = 0.0;
    a[1][1] = 1.0;
    a[2][0] = 1.0;
    a[2][1] = 0.0;

    Quadrilatere b;
    b[0][0] = 0.0;
    b[0][1] = 0.0;
    b[1][0] = 0.0;
    b[1][1] = 1.0;
    b[2][0] = 1.0;
    b[2][1] = 1.0;
    b[3][0] = 1.0;
    b[3][1] = 0.0;

    return 0;
}
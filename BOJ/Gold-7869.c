#include <stdio.h>
// not working in BOJ
// #define _USE_MATH_DEFINES
#include <math.h>

#define M_PI 3.14159265358979323846

int main( void )
{
    double x1, y1, r1, x2, y2, r2;
    scanf( "%lf%lf%lf%lf%lf%lf", &x1, &y1, &r1, &x2, &y2, &r2 );

    double dist = sqrt( pow( (x1 - x2), 2.0 ) + pow( (y1 - y2), 2.0 ) );
    double rMin = r1 > r2 ? r2 : r1;
    double rMax = r1 > r2 ? r1 : r2;

    double ans;
    if ( dist >= r1 + r2 )
    {
        ans = 0.0;
    }
    else if ( dist + rMin <= rMax )
    {
        ans = M_PI * rMin * rMin;
    }
    else
    {
        double theta1 = 2 * acos( (r1*r1 + dist*dist - r2*r2) / ( 2 * r1 * dist ) );
        double tri1 = r1 * r1 * sin( theta1 ) / 2;
        double theta2 = 2 * acos( (r2*r2 + dist*dist - r1*r1) / ( 2 * r2 * dist ) );
        double tri2 = r2 * r2 * sin( theta2 ) / 2;

        double circularSector1 = theta1 * r1 * r1 / 2;
        double circularSector2 = theta2 * r2 * r2 / 2;

        ans = circularSector1 + circularSector2 - tri1 - tri2;
    }

    printf( "%.3lf", ans );
    return 0;
}
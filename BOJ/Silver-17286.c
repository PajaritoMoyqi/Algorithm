#include <stdio.h>
#include <math.h>

char Tower[1 + 100 + 1][1 + 100 + 1];

int main( void )
{
    int x, y;
    scanf( "%d%d", &x, &y );

    int x1, y1, x2, y2, x3, y3;
    scanf( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3 );

    double route1 = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)) + sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)) + sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)); // 1 2 3
    double route2 = sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)) + sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)) + sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2)); // 1 3 2
    double route3 = sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2)) + sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3)) + sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)); // 2 3 1
    double route4 = sqrt((x-x2)*(x-x2) + (y-y2)*(y-y2)) + sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) + sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3)); // 2 1 3
    double route5 = sqrt((x-x3)*(x-x3) + (y-y3)*(y-y3)) + sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)) + sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); // 3 1 2
    double route6 = sqrt((x-x3)*(x-x3) + (y-y3)*(y-y3)) + sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2)) + sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)); // 3 2 1
    double route = 9999;
    route = route < route1 ? route : route1;
    route = route < route2 ? route : route2;
    route = route < route3 ? route : route3;
    route = route < route4 ? route : route4;
    route = route < route5 ? route : route5;
    route = route < route6 ? route : route6;

    printf( "%d", (int)route );

    return 0;
}
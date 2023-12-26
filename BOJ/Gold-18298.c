#include <stdio.h>
#include <math.h>

double getArea( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC );

int main( void )
{
    int n, m;
    scanf( "%d", &n );
    double totalArea = 0, area;
    while ( n-- )
    {
        scanf( "%d", &m );

        long long x1, y1, x2, y2, x3, y3;
        scanf( "%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3 );

        area = getArea( x1, y1, x2, y2, x3, y3 );
        // printf( "getArea: %lf, x1: %lld, y1: %lld, x2: %lld, y2: %lld, x3: %lld, y3: %lld, \n", area, x1, y1, x2, y2, x3, y3 );
        x2 = x3;
        y2 = y3;
        m -= 3;

        while ( m > 0 )
        {
            scanf( "%lld%lld", &x3, &y3 );
            area += getArea( x1, y1, x2, y2, x3, y3 );
            // printf( "getArea: %lf, x1: %lld, y1: %lld, x2: %lld, y2: %lld, x3: %lld, y3: %lld, \n", area, x1, y1, x2, y2, x3, y3 );

            x2 = x3;
            y2 = y3;
            m--;
        }

        if ( area < 0 ) area = -area;
        totalArea += area;
    }
    long long ans = totalArea;

    printf( "%lld", ans );

    return 0;
}

double getArea( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC )
{
    double xAB = (xB - xA);
    double yAB = (yB - yA);
    double xAC = (xC - xA); 
    double yAC = (yC - yA);
    double zAB = 0, zAC = 0;

    return (xAB*yAC - xAC*yAB) / 2;
}
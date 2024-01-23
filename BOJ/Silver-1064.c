#include <stdio.h>
#include <math.h>

int checkInclination( int x1, int y1, int x2, int y2, int x3, int y3 );
double getLength( int x1, int y1, int x2, int y2 );

int main( void )
{
    int x1, y1, x2, y2, x3, y3;
    scanf( "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3 );

    if ( checkInclination( x1, y1, x2, y2, x3, y3 ) )
        printf( "-1.0" );
    else
    {
        double AB = getLength( x1, y1, x2, y2 );
        double BC = getLength( x3, y3, x2, y2 );
        double CA = getLength( x1, y1, x3, y3 );

        double tmpMax = AB > BC ? AB : BC;
        double Max = tmpMax > CA ? tmpMax : CA;
        double tmpMin = AB < BC ? AB : BC;
        double Min = tmpMin < CA ? tmpMin : CA;

        printf( "%.15f", 2 * (Max - Min) );
    }

    return 0;
}

double getLength( int x1, int y1, int x2, int y2 )
{
    return sqrt( pow( abs( x1 - x2 ), 2 ) + pow( abs( y1 - y2 ), 2 ) );
}
int checkInclination( int x1, int y1, int x2, int y2, int x3, int y3 )
{
    int xAB = x1 - x2;
    int xAC = x1 - x3;
    int yAB = y1 - y2;
    int yAC = y1 - y3;

    if ( yAB * xAC == xAB * yAC )
        return 1;
    else
        return 0;
}
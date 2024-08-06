#include <stdio.h>

int checkCCW( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC );

int main( void )
{
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    scanf( "%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4 );

    int res1 = checkCCW( x1, y1, x2, y2, x3, y3 ) * checkCCW( x1, y1, x2, y2, x4, y4 ); 
    int res2 = checkCCW( x3, y3, x4, y4, x1, y1 ) * checkCCW( x3, y3, x4, y4, x2, y2 );

    if ( res1 == -1 && res2 == -1 )
    {
        printf( "1\n" );

        double a1 = (double)(y2 - y1) / (x2 - x1);
        double b1 = (double)y1 - (double)x1 * (y2 - y1) / (x2 - x1);

        double a2 = (double)(y4 - y3) / (x4- x3);
        double b2 = (double)y3 - (double)x3 * (y4 - y3) / (x4 - x3);

        // printf( "%.10lf %.10lf %.10lf %.10lf\n", a1, b1, a2, b2 );

        if ( x1 == x2 && x3 != x4 )
        {
            double x = x1;
            double y = (double)a2 * x1 + (double)b2;

            printf( "%.10lf %.10lf\n", x, y );
        }
        else if ( x1 != x2 && x3 == x4 )
        {
            double x = x3;
            double y = (double)a1 * x3 + (double)b1;

            printf( "%.10lf %.10lf\n", x, y );
        }
        else
        {
            if ( x1 == x2 && x3 == x4 )
            {
                if ( x1 == x3 && y1 == y3 )
                {
                    long long xTmp1 = x1 - x2;
                    long long xTmp2 = x3 - x4;
                    long long yTmp1 = y1 - y2;
                    long long yTmp2 = y3 - y4;
                    
                    long long resX = xTmp1 * xTmp2;
                    long long resY = yTmp1 * yTmp2;

                    if ( resX <= 0 && resY <= 0 )
                        printf( "%d %d", x1, y1 );
                }
                else if ( x1 == x4 && y1 == y4 )
                {
                    long long xTmp1 = x1 - x2;
                    long long xTmp2 = x4 - x3;
                    long long yTmp1 = y1 - y2;
                    long long yTmp2 = y4 - y3;
                    
                    long long resX = xTmp1 * xTmp2;
                    long long resY = yTmp1 * yTmp2;

                    if ( resX <= 0 && resY <= 0 )
                        printf( "%d %d", x1, y1 );
                }
                else if ( x2 == x3 && y2 == y3 )
                {
                    long long xTmp1 = x2 - x1;
                    long long xTmp2 = x3 - x4;
                    long long yTmp1 = y2 - y1;
                    long long yTmp2 = y3 - y4;
                    
                    long long resX = xTmp1 * xTmp2;
                    long long resY = yTmp1 * yTmp2;

                    if ( resX <= 0 && resY <= 0 )
                        printf( "%d %d", x2, y2 );
                }
                else if ( x2 == x4 && y2 == y4 )
                {
                    long long xTmp1 = x2 - x1;
                    long long xTmp2 = x4 - x3;
                    long long yTmp1 = y2 - y1;
                    long long yTmp2 = y4 - y3;
                    
                    long long resX = xTmp1 * xTmp2;
                    long long resY = yTmp1 * yTmp2;

                    if ( resX <= 0 && resY <= 0 )
                        printf( "%d %d", x2, y2 );
                }
            }
            else if ( a1 != a2 )
            {
                double x = (b2 - b1) / (a1 - a2);
                double y = a1 * (b2 - b1) / (a1 - a2) + b1;

                printf( "%.10lf %.10lf\n", x, y );
            }
            else
            {
                if ( x1 == x3 && y1 == y3 )
                {
                    long long xTmp1 = x1 - x2;
                    long long xTmp2 = x3 - x4;
                    long long yTmp1 = y1 - y2;
                    long long yTmp2 = y3 - y4;
                    
                    long long resX = xTmp1 * xTmp2;
                    long long resY = yTmp1 * yTmp2;

                    if ( resX <= 0 && resY <= 0 )
                        printf( "%d %d", x1, y1 );
                }
                else if ( x1 == x4 && y1 == y4 )
                {
                    long long xTmp1 = x1 - x2;
                    long long xTmp2 = x4 - x3;
                    long long yTmp1 = y1 - y2;
                    long long yTmp2 = y4 - y3;
                    
                    long long resX = xTmp1 * xTmp2;
                    long long resY = yTmp1 * yTmp2;

                    if ( resX <= 0 && resY <= 0 )
                        printf( "%d %d", x1, y1 );
                }
                else if ( x2 == x3 && y2 == y3 )
                {
                    long long xTmp1 = x2 - x1;
                    long long xTmp2 = x3 - x4;
                    long long yTmp1 = y2 - y1;
                    long long yTmp2 = y3 - y4;
                    
                    long long resX = xTmp1 * xTmp2;
                    long long resY = yTmp1 * yTmp2;

                    if ( resX <= 0 && resY <= 0 )
                        printf( "%d %d", x2, y2 );
                }
                else if ( x2 == x4 && y2 == y4 )
                {
                    long long xTmp1 = x2 - x1;
                    long long xTmp2 = x4 - x3;
                    long long yTmp1 = y2 - y1;
                    long long yTmp2 = y4 - y3;
                    
                    long long resX = xTmp1 * xTmp2;
                    long long resY = yTmp1 * yTmp2;

                    if ( resX <= 0 && resY <= 0 )
                        printf( "%d %d", x2, y2 );
                }
            }
        }
    }
    else
    {
        int flag = 0;

        if ( res1 == 0 )
        {
            if ( checkCCW( x1, y1, x2, y2, x3, y3 ) == 0 )
            {
                if ( ((x1 <= x3 && x3 <= x2) || (x1 >= x3 && x3 >= x2))
                    && ((y1 <= y3 && y3 <= y2) || (y1 >= y3 && y3 >= y2)) )
                {
                    flag = 1;
                    goto end;
                }
                else
                {
                    flag = 0;
                }
            }
            if ( checkCCW( x1, y1, x2, y2, x4, y4 ) == 0 )
            {
                if ( ((x1 <= x4 && x4 <= x2) || (x1 >= x4 && x4 >= x2))
                    && ((y1 <= y4 && y4 <= y2) || (y1 >= y4 && y4 >= y2)) )
                {
                    flag = 1;
                    goto end;
                }
                else
                {
                    flag = 0;
                }
            }
        }

        if ( res2 == 0 )
        {
            if ( checkCCW( x3, y3, x4, y4, x1, y1 ) == 0 )
            {
                if ( ((x3 <= x1 && x1 <= x4) || (x3 >= x1 && x1 >= x4))
                    && ((y3 <= y1 && y1 <= y4) || (y3 >= y1 && y1 >= y4)) )
                {
                    flag = 1;
                    goto end;
                }
                else
                {
                    flag = 0;
                }
            }
            if ( checkCCW( x3, y3, x4, y4, x2, y2 ) == 0 )
            {
                if ( ((x3 <= x2 && x2 <= x4) || (x3 >= x2 && x2 >= x4))
                    && ((y3 <= y2 && y2 <= y4) || (y3 >= y2 && y2 >= y4)) )
                {
                    flag = 1;
                    goto end;
                }
                else
                {
                    flag = 0;
                }
            }
        }

        end:
            printf( "%d\n", flag );

        if ( flag )
        {
            double a1 = (double)(y2 - y1) / (x2 - x1);
            double b1 = (double)y1 - (double)x1 * (y2 - y1) / (x2 - x1);

            double a2 = (double)(y4 - y3) / (x4- x3);
            double b2 = (double)y3 - (double)x3 * (y4 - y3) / (x4 - x3);

            // printf( "%.10lf %.10lf %.10lf %.10lf\n", a1, b1, a2, b2 );

            if ( x1 == x2 && x3 != x4 )
            {
                double x = x1;
                double y = (double)a2 * x1 + (double)b2;

                printf( "%.10lf %.10lf\n", x, y );
            }
            else if ( x1 != x2 && x3 == x4 )
            {
                double x = x3;
                double y = (double)a1 * x3 + (double)b1;

                printf( "%.10lf %.10lf\n", x, y );
            }
            else
            {
                if ( x1 == x2 && x3 == x4 )
                {
                    if ( x1 == x3 && y1 == y3 )
                    {
                        long long xTmp1 = x1 - x2;
                        long long xTmp2 = x3 - x4;
                        long long yTmp1 = y1 - y2;
                        long long yTmp2 = y3 - y4;
                        
                        long long resX = xTmp1 * xTmp2;
                        long long resY = yTmp1 * yTmp2;

                        if ( resX <= 0 && resY <= 0 )
                            printf( "%d %d", x1, y1 );
                    }
                    else if ( x1 == x4 && y1 == y4 )
                    {
                        long long xTmp1 = x1 - x2;
                        long long xTmp2 = x4 - x3;
                        long long yTmp1 = y1 - y2;
                        long long yTmp2 = y4 - y3;
                        
                        long long resX = xTmp1 * xTmp2;
                        long long resY = yTmp1 * yTmp2;

                        if ( resX <= 0 && resY <= 0 )
                            printf( "%d %d", x1, y1 );
                    }
                    else if ( x2 == x3 && y2 == y3 )
                    {
                        long long xTmp1 = x2 - x1;
                        long long xTmp2 = x3 - x4;
                        long long yTmp1 = y2 - y1;
                        long long yTmp2 = y3 - y4;
                        
                        long long resX = xTmp1 * xTmp2;
                        long long resY = yTmp1 * yTmp2;

                        if ( resX <= 0 && resY <= 0 )
                            printf( "%d %d", x2, y2 );
                    }
                    else if ( x2 == x4 && y2 == y4 )
                    {
                        long long xTmp1 = x2 - x1;
                        long long xTmp2 = x4 - x3;
                        long long yTmp1 = y2 - y1;
                        long long yTmp2 = y4 - y3;
                        
                        long long resX = xTmp1 * xTmp2;
                        long long resY = yTmp1 * yTmp2;

                        if ( resX <= 0 && resY <= 0 )
                            printf( "%d %d", x2, y2 );
                    }
                }
                else if ( a1 != a2 )
                {
                    double x = (b2 - b1) / (a1 - a2);
                    double y = a1 * (b2 - b1) / (a1 - a2) + b1;

                    printf( "%.10lf %.10lf\n", x, y );
                }
                else
                {
                    if ( x1 == x3 && y1 == y3 )
                    {
                        long long xTmp1 = x1 - x2;
                        long long xTmp2 = x3 - x4;
                        long long yTmp1 = y1 - y2;
                        long long yTmp2 = y3 - y4;
                        
                        long long resX = xTmp1 * xTmp2;
                        long long resY = yTmp1 * yTmp2;

                        if ( resX <= 0 && resY <= 0 )
                            printf( "%d %d", x1, y1 );
                    }
                    else if ( x1 == x4 && y1 == y4 )
                    {
                        long long xTmp1 = x1 - x2;
                        long long xTmp2 = x4 - x3;
                        long long yTmp1 = y1 - y2;
                        long long yTmp2 = y4 - y3;
                        
                        long long resX = xTmp1 * xTmp2;
                        long long resY = yTmp1 * yTmp2;

                        if ( resX <= 0 && resY <= 0 )
                            printf( "%d %d", x1, y1 );
                    }
                    else if ( x2 == x3 && y2 == y3 )
                    {
                        long long xTmp1 = x2 - x1;
                        long long xTmp2 = x3 - x4;
                        long long yTmp1 = y2 - y1;
                        long long yTmp2 = y3 - y4;
                        
                        long long resX = xTmp1 * xTmp2;
                        long long resY = yTmp1 * yTmp2;

                        if ( resX <= 0 && resY <= 0 )
                            printf( "%d %d", x2, y2 );
                    }
                    else if ( x2 == x4 && y2 == y4 )
                    {
                        long long xTmp1 = x2 - x1;
                        long long xTmp2 = x4 - x3;
                        long long yTmp1 = y2 - y1;
                        long long yTmp2 = y4 - y3;
                        
                        long long resX = xTmp1 * xTmp2;
                        long long resY = yTmp1 * yTmp2;

                        if ( resX <= 0 && resY <= 0 )
                            printf( "%d %d", x2, y2 );
                    }
                }
            }
        }
    }

    return 0;
}

int checkCCW( long long xA, long long yA, long long xB, long long yB, long long xC, long long yC )
{
    long long xAB = (xB - xA);
    long long yAB = (yB - yA);
    long long xAC = (xC - xA); 
    long long yAC = (yC - yA);
    long long zAB = 0, zAC = 0;

    if ( xAB*yAC - xAC*yAB > 0 ) return 1;
    else if ( xAB*yAC - xAC*yAB < 0 ) return -1;
    else return 0;   
}
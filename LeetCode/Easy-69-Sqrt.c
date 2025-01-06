int mySqrt( int x )
{
    long long i = 1;
    while ( i*i <= (long long)x )
        i++;

    return (int)(i-1);
}
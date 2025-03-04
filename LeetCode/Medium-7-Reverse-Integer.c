int reverse( int x )
{
    int ans = 0;
    while ( x )
    {
        int rest = x % 10;

        if ( ( x > 0 && ans > (0x7fffffff - rest) / 10 ) ||
            ( x < 0 && ans < ((signed)0x80000000 - rest) / 10 ) ) 
            return 0;
        
        ans = ans*10 + rest;
        x /= 10;
    }

    return ans;
}
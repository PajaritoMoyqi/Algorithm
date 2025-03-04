int numberOfSteps( int num )
{
    int cnt = 0;
    while ( num )
    {
        if ( num & 1 )
            cnt++;

        num >>= 1;
        if ( num )
            cnt++;
    }

    return cnt;
}
#include <stdio.h>

int main( void )
{
    int floor, sec;
    scanf( "%d%d", &floor, &sec );

    int move1, move2, move3, move4;
    move1 = floor;
    move2 = floor / 2;
    move3 = floor % 2 ? (floor / 2) + 1 : floor / 2;
    move4 = (floor + 2) / 3;

    int fin1, fin2, fin3, fin4, fin5, fin6, fin7, fin8;
    fin1 = move1;
    fin2 = move2;
    fin3 = move3;
    fin4 = 0;
    fin5 = move1 + move4;
    fin6 = move2 + move4;
    fin7 = move3 + move4;
    fin8 = move4;

    int cnt = 0;
    if ( floor == 1 )
    {
        if ( sec == 0 ) cnt = 1;
        else cnt = 2;
    }
    else if ( floor == 2 )
    {
        if (fin1 <= sec) cnt++;
        if (fin2 <= sec) cnt++;
        if (fin3 <= sec) cnt++;
        if (fin4 <= sec) cnt++;
    }
    else
    {
        if (fin1 <= sec) cnt++;
        if (fin2 <= sec) cnt++;
        if (fin3 <= sec) cnt++;
        if (fin4 <= sec) cnt++;
        if (fin5 <= sec) cnt++;
        if (fin6 <= sec) cnt++;
        if (fin7 <= sec) cnt++;
        if (fin8 <= sec) cnt++;
    }
    printf( "%d", cnt );

    return 0;
}
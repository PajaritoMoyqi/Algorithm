#include <stdio.h>

int main( void )
{
    int T;
    scanf( "%d", &T );

    int Cnt = 0, sameCnt = 0, Max = 0, num, before = -1, sign = 0;
    while ( T-- )
    {
        scanf( "%d", &num );
        
        if ( !sign ) // 입력 받기를 시작했고, 아직 수열이 증가하는지 아닌지 모르는 경우
        {
            if ( !Cnt ) // 배열의 첫 번째 수인 경우
                Cnt++;
            else // 배열의 첫 번째 수는 아닌 경우
            {
                Cnt++;
                if ( before != -1 ) // 이전 수가 존재할 경우 - 배열의 첫 번쨰 수가 아닌지 더블 체크
                {
                    if ( before > num )
                    {
                        sign = -1;
                        sameCnt = 0;
                    }
                    else if ( before < num )
                    {
                        sign = 1;
                        sameCnt = 0;
                    }
                    else
                        sameCnt++;
                }
            }
        }
        else if ( sign == 1 ) // 배열 내의 부분 수열이 증가하는 중인 경우
        {
            if ( before <= num ) // 이번에 입력된 수도 증가 조건을 만족
            {
                Cnt++;
                if ( before == num ) // 같은 경우 sameCnt도 증가
                    sameCnt++;
                else // 다른 경우
                    sameCnt = 0;
            }
            else // 증가 조건을 만족하지 않는 경우
            {
                if ( Cnt > Max )
                    Max = Cnt;

                Cnt = 1 + sameCnt + 1;
                sign = -1; // 감소하는 경우로 flag 변수 변경
                sameCnt = 0;
            }
        }
        else if ( sign == -1 ) // 배열 내의 부분 수열이 감소하는 중인 경우
        {
            if ( before >= num ) // 이번에 입력된 수도 감소 조건을 만족
            {
                Cnt++;
                if ( before == num ) // 같은 경우 sameCnt도 증가
                    sameCnt++;
                else // 다른 경우
                    sameCnt = 0;
            }
            else // 감소 조건을 만족하지 않는 경우
            {
                if ( Cnt > Max )
                    Max = Cnt;

                Cnt = 1 + sameCnt + 1;
                sign = 1; // 증가하는 경우로 flag 변수 변경
                sameCnt = 0;
            }
        }
        // printf( "Before: %d, Now: %d, Sign: %d, Max: %d, Cnt: %d, SameCnt: %d\n", before, num, sign, Max, Cnt, sameCnt );
        
        before = num; // 언제나 마지막에는 현재의 수를 이전 수(before)에 저장해두어야 함 - 비교를 위해
    }

    printf( "%d", Cnt > Max ? Cnt : Max ); // 끝나고 난 뒤 얻은 마지막 부분의 부분 수열 길이와 그 전까지의 최대 부분 수열의 길이 중 더 큰 것 출력

    return 0;
}
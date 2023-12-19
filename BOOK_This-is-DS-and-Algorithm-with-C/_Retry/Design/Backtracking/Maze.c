#include "Maze.h"

int GetNextStep( MazeInfo* M, Position* Current, int direction, Position* Next )
{
    // Moves to next direction
    switch ( direction )
    {
        case NORTH:
            Next->X = Current->X;
            Next->Y = Current->Y - 1;

            if ( Next->Y == -1 )
                return FAIL;

            break;
        
        case SOUTH:
            Next->X = Current->X;
            Next->Y = Current->Y + 1;

            if ( Next->Y == M->RowSize )
                return FAIL;

            break;

        case EAST:
            Next->X = Current->X + 1;
            Next->Y = Current->Y;

            if ( Next->X == M->ColumnSize )
                return FAIL;

            break;

        case WEST:
            Next->X = Current->X - 1;
            Next->Y = Current->Y;

            if ( Next->X == -1 )
                return FAIL;

            break;
    }

    // If moved position is wall or marked, it means fail
    if ( M->Map[Next->Y][Next->X] == WALL )
        return FAIL;
    if ( M->Map[Next->Y][Next->X] == MARKED )
        return FAIL;

    // else
    return SUCCESS;
}
int MoveTo( MazeInfo* M, Position* Current, int direction ) // actually variable 'direction' is not used at all
{
    // all possible directions
    int DirectionSet[] = { NORTH, SOUTH, EAST, WEST };
    Position Next;

    // But I am on the goal position, it's end
    if ( M->Map[Current->Y][Current->X] == GOAL )
        return SUCCESS;

    // else, first, mark position as marked( '+' )
    M->Map[Current->Y][Current->X] = MARKED;

    // check whether I can take next step
    int i;
    for ( i = 0; i < 4; i++ )
    {
        if ( GetNextStep( M, Current, DirectionSet[i], &Next ) == FAIL )
            continue;

        if ( MoveTo( M, &Next, DirectionSet[i] ) == SUCCESS )
            return SUCCESS;
    }

    M->Map[Current->Y][Current->X] = WAY;

    return FAIL;
}

int FindPath( MazeInfo* M )
{
    int i, j, startFound = FAIL, result = FAIL;
    Position startPosition;

    // find start position
    for ( i = 0; i < M->RowSize; i++ )
    {
        for ( j = 0; j < M->ColumnSize; j++ )
        {
            if ( M->Map[i][j] == START )
            {
                startPosition.X = j;
                startPosition.Y = i;
                startFound = SUCCESS;
                
                break;
            }
        }
    }
    if ( startFound == FAIL )
        return FAIL;

    // If you can move at least one or more direction(s) from start positoin, we can start
    if ( MoveTo( M, &startPosition, NORTH ) )
        result = SUCCESS;
    else if ( MoveTo( M, &startPosition, SOUTH ) )
        result = SUCCESS;
    else if ( MoveTo( M, &startPosition, EAST ) )
        result = SUCCESS;
    else if ( MoveTo( M, &startPosition, WEST ) )
        result = SUCCESS;

    M->Map[startPosition.Y][startPosition.X] = START;

    return result;
}

int GetMaze( char* FilePath, MazeInfo* M )
{
    int rowSize = 0;
    int columnSize = INIT_VALUE;

    FILE* fp;
    char Buffer[MAX_BUFFER];

    if ( (fp = fopen( FilePath, "r" )) == NULL )
    {
        printf( "File Not Exists.\n" );
        return FAIL;
    }

    while ( fgets( Buffer, MAX_BUFFER, fp ) != NULL )
    {
        rowSize++;

        if ( columnSize == INIT_VALUE )
            columnSize = strlen( Buffer ) - 1;
        else if ( columnSize != strlen( Buffer ) - 1 )
        {
            printf( "File Not Valid.\n" );
            fclose( fp );
            return FAIL;
        }
    }

    M->RowSize    = rowSize;
    M->ColumnSize = columnSize;
    M->Map = (char**)malloc( sizeof( char* ) * rowSize );

    int i, j;
    for ( i = 0; i < rowSize; i++ )
        M->Map[i] = (char*)malloc( sizeof( char ) * columnSize);

    rewind( fp );

    for ( i = 0; i < rowSize; i++ )
    {
        fgets( Buffer, MAX_BUFFER, fp );

        for ( j = 0; j < columnSize; j++ )
            M->Map[i][j] = Buffer[j];
    }

    fclose( fp );

    return SUCCESS;
}

int main( void )
{
    MazeInfo M;

    if ( GetMaze( "YourPath\\MazeSample.dat", &M ) == FAIL )
        return 0;
    
    if ( FindPath( &M ) == FAIL )
        return 0;

    int i, j;
    for ( i = 0; i < M.RowSize; i++ )
    {
        for ( j = 0; j < M.ColumnSize; j++ )
            printf( "%c", M.Map[i][j] );

        printf( "\n" );
    }

    return 0;
}
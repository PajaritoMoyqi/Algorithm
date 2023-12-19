#ifndef MAZE_H
#define MAZE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_BUFFER 1024
# define INIT_VALUE -1

# define START 'S'
# define GOAL 'G'
# define WAY ' '
# define WALL '#'
# define MARKED '+'

enum DIRECTION { NORTH, SOUTH, EAST, WEST };
enum RESULT { FAIL, SUCCESS };

typedef struct Position
{
    int X;
    int Y;
} Position;
typedef struct MazeInfo
{
    int ColumnSize;
    int RowSize;

    char** Map;
} MazeInfo;

// declarations

#endif
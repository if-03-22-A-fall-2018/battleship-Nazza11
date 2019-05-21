/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: 2AHIF Vinzent Kronreif
 *-----------------------------------------------------------------------------
 * Exercise Number: 22
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * Schiife versenken
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "battleship.h"

#include <stdio.h>
#include "battleship.h"

#define SIZE 10
static CellContent my[SIZE][SIZE];
static CellContent op[SIZE][SIZE];
static CellContent myGuesses[SIZE][SIZE];

void load_game()
{
    FILE* fd_my = fopen("battleship.my", "r");
    FILE* fd_op = fopen("battleship.op", "r");

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            fread(&my[i][j], 4, 1, fd_my);
            fread(&op[i][j], 4, 1, fd_op);
            myGuesses[i][j] = Unknown;
        }
    }
    fclose(fd_my);
    fclose(fd_op);
}

CellContent get_shot(int row, int col)
{
    return row > -1 && row < SIZE && col > -1 && col < SIZE ? my[row][col]: OutOfRange;
}

bool shoot(int row, int col)
{
    if(!(row > -1 && row < SIZE && col > -1 && col < SIZE ))
    {
          return false;
    }

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if(row + i > -1 && row + i < SIZE && col + j > -1 && col + j < SIZE)
            {
              myGuesses[row+i][col+j] = op[row+i][col+j];
            }
        }
    }
    return true;
}

CellContent get_my_guess(int row, int col)
{
    return row > -1 && row < SIZE && col > -1 && col < SIZE ? myGuesses[row][col]: OutOfRange;
}

#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PLAYER_01 'X'
#define PLAYER_02 'O'
#define NO_WINNER 'N'
#define WINNER 'W'

// void window

void initingNcurses()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

void drawingBoard()
{
    int column, line, verticalLineX = 0;

    for (column = 0; column <= 6; column++)
    {
        if (column % 2 == 0)
        {

            for (line = 4; line <= 16; line++)
            {
                mvwprintw(stdscr, column + 2, line, "%c", '-');
            }
        }

        else
        {
            mvwprintw(stdscr, column + 2, 4, "%s", "|");
            mvwprintw(stdscr, column + 2, 8, "%s", "|");
            mvwprintw(stdscr, column + 2, 12, "%s", "|");
            mvwprintw(stdscr, column + 2, 16, "%s", "|");
        }

        refresh();
        move(1, 2);
    }
    refresh();
}

void close(WINDOW *board)
{
    delwin(board);
    endwin();
    printf("Finalized\n");
}

void initingBoard(int *boardInfo)
{

    int i;

    for (i = 0; i <= 8; i++)
    {
        boardInfo[i] = i + 2;
    }
}

int main()
{

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLUE);

    int boardInfo[9];
    initingNcurses();
    drawingBoard();
    initingBoard(boardInfo);

    close(boardInfo);
    return 0;
}
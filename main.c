#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "./tictactoe.h"

#define PLAYER_1 'O'
#define PLAYER_2 'X'

void initingNcurses()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

void drawingBoard()
{
    int column, line;

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
}

void playerRound(unsigned long PlayerID01, unsigned long PlayerID02)
{
}

void displayOptions()
{
    char line[1], column[1];
    printw("\n\nDigite a sua jogada \n");
    printw("Linha:\n");
    getstr(line);
    printw("Coluna:\n");
    getstr(column);
    printw("Sua jogada foi: %c %c \n \n", line, column);
}

void playerLogin()
{
    Game_T game;

    unsigned long currentPlayer;

    game.Players[0].Name = "Guilherme";
    game.Players[0].PlayerID = 1;

    currentPlayer = game.Players[0].PlayerID;

    game.Players[1].Name = "Carol";
    game.Players[1].PlayerID = 2;

    displayOptions();
}

int main()
{
    Player_Interface playerInterface;

    // player 01 - receba sempre a O
    // player 02 - receba sempre o X
    // colocar comando para marcar o valor na posição do jogo

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLUE);

    int boardInfo[9];
    initingNcurses();
    playerLogin();
    drawingBoard();
    initingBoard(boardInfo);

    return 0;
}
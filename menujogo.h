
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	int		win_x; 
	int		win_y; 
	int		opcao = 1; 
	int		c_x; 
	int		c_y; 
	int		titleboxlen; 
	titleboxlen = strlen("=========================================================================="); 

	char *o_1p = "1 Jogador"; 
	char *o_2p = "2 Jogador";
	char *o_help = "Ajuda";
	char *o_credits = "Créditos";
	char *o_quit = "Quit";


	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	
	getmaxyx(stdscr, win_y, win_x); 
	WINDOW*win_menu = newwin(win_y, win_x, 0, 0);

	keypad(win_menu, true);

	while (1)
	{
		wclear(win_menu);
		getmaxyx(win_menu, win_y, win_x);
		c_x = win_x / 2; 
		c_y = win_y / 2; 
		
		
		mvwprintw(win_menu, c_y - 10, c_x - (titleboxlen / 2), "==========================================================================");
		mvwprintw(win_menu, c_y - 9, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 8, c_x - (titleboxlen / 2), "||                         JOGO DA VELHA                                ||");
		mvwprintw(win_menu, c_y - 7, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 6, c_x - (titleboxlen / 2), "==========================================================================");
		mvwprintw(win_menu, c_y - 5, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 4, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 3, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 2, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y - 1, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 1, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 2, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 3, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 4, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 5, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 6, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 7, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 8, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 9, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 10, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 11, c_x - (titleboxlen / 2), "||                                                                      ||");
		mvwprintw(win_menu, c_y + 12, c_x - (titleboxlen / 2), "==========================================================================");

		if (opcao == 1)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y - 1, c_x - (strlen(o_1p) / 2), o_1p);
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y - 1, c_x - (strlen(o_1p) / 2), o_1p);

		if (opcao == 2)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y + 1, c_x - (strlen(o_2p) / 2), o_2p);
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y + 1, c_x - (strlen(o_2p) / 2), o_2p);

		if (opcao == 3)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y + 3, c_x - (strlen(o_help) / 2), o_help);
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y + 3, c_x - (strlen(o_help) / 2), o_help);

		if (opcao == 4)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y + 5, c_x - (strlen(o_credits) / 2), o_credits);
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y + 5, c_x - (strlen(o_credits) / 2), o_credits);

		if (opcao == 5)
		{
			wattron(win_menu, COLOR_PAIR(1));
			mvwprintw(win_menu, c_y + 7, c_x - (strlen(o_quit) / 2), o_quit);
			wattroff(win_menu, COLOR_PAIR(1));
		}
		else
			mvwprintw(win_menu, c_y + 7, c_x - (strlen(o_quit) / 2), o_quit);

		//Update Screen
		wrefresh(win_menu);

		//Key Hooks
		switch(wgetch(win_menu))
		{
			case KEY_UP:
				if (opcao == 1)
					opcao = 5;
				else
					opcao -= 1;
				break;
			case KEY_DOWN:
				if (opcao == 5)
					opcao = 1;
				else
					opcao += 1;
				break;
			case 10: 
				if (opcao == 1)
				{
					
				}
				
				if (opcao == 2)
				{
					
				}

				if (opcao == 3)
				{
					
				}

				if (opcao == 4)
				{
					
				}

				if (opcao == 5)
				{
					
					endwin();
					curs_set(TRUE);
					system("Fechar");
					return (0);
				}
				break;
		}
	}
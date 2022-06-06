#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void limpar(char t[3] [3]);
void mostrar(char t[3] [3]);
void usuario(char t[3] [3]);
void usuario2(char t[3] [3]);
char vencedor(char t[3] [3]);

int main(void) {
	
	char t[3] [3], v;
	int j=0, e, s;
	printf("Par (0) ou Impar (1)?");
	scanf("%d", &e);
	srand(time(NULL));
	s=rand()%2;
	limpar(t);
	
	do{
		mostrar(t);
		if(e==s)usuario(t);
		else usuario2(t);
		j++;
		s=!s;
		v=vencedor(t);
	} while(j<9 && v==' ');
	
	mostrar(t);
	
	switch(v) {
		case 'x': puts("\n\n Jogador 1 Voce ganhou");break;
		case '0': puts("\n\n Jogador 2 Voce ganhou");break;
		case ' ': puts("\n\nEmpatamos");
	}
	
	return 0;
}

void limpar(char t[3] [3]) {
	int i, j;
	
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			t[i] [j]=' ';
}

void clrscr() {
  #ifdef WINDOWS
  system("cls");
  #endif
  #ifdef LINUX
  system("clear");
  #endif
}

void mostrar(char t[3] [3]) {
	int i;
	clrscr();
	printf("\n Jogador, voce deve informar a posicao de linha e coluna. \n");
	for(i=0;i<3;i++)  {
		printf("\n | %c | %c | %c |", t[i] [0], t[i] [1], t[i] [2]);
		if(i<2)  printf ("\n |---+---+---|");
	}
}
void usuario (char t[3] [3]) {
	int L, C;
	
	do{
		printf("\n \n Jogador 1 Posicao?");
		scanf("%d,%d", &L, &C);
	} while (L<0 || L>2 || C<0 || C>2 || t[L] [C]!=' ');
	t[L] [C] ='x';
}

void usuario2 (char t[3] [3]) {
	int L, C;
	
	do{
		printf("\n \n Jogador 2 Posicao?");
		scanf("%d,%d", &L, &C);
	} while (L<0 || L>2 || C<0 || C>2 || t[L] [C]!=' ');
	t[L] [C] ='0';
}

char vencedor(char t[3][3])  {
	int i;
	for(i=0; i<3;i++){

		if(t[i] [0] == t[i] [1]  && t[i] [1] == t[i] [2] && t[i] [0] != ' ')
			return t[i] [0];
			
		if(t[0] [i] == t[1] [i]  && t[1] [i] == t[2] [i] && t[0] [i] != ' ')
			return t[0] [i];
	 }
	 
	 if(t[0] [0] == t[1] [1] && t[1] [1] == t[2] [2] && t[0] [0] != ' ')
			return t[0] [0];
			
	 if(t[0] [2] == t[1] [1] && t[1] [1] == t[2] [0] && t[0] [2] != ' ')
			return t[0] [2];
	 return ' ';
}

#include <stdbool.h>

typedef struct
{
	unsigned long PlayerID;
	char *Name;
	bool Enabled;
	char RegDate[8]; // aaaammdd
	unsigned long OverAllScore;
} Player_t;

typedef struct
{
	unsigned long GameId;
	unsigned long PlayerID01;
	unsigned long PlayerID02;
	unsigned long Score;
	int Winner;
	int Status;
	struct Game_T *Next;
	Player_t Players[2];
} Game_T;

typedef struct
{
	char PlayValue;
	int Round;
	int Time;
	char *Comand;
	char *Play;
} Player_Interface;

// JOGADA -> J - COMANDO LINHA COLUNA JOGADA
// COMANDOS -> A, B, C, D -> COMANDOS PARA O CHAT, PARA SAIR DA JOGADA, BLA
#include <stdbool.h>

typedef struct {
	unsigned long PlayerID;
	char Name[50];
	bool Enabled;
	char RegDate[8]; //aaaammdd
	unsigned long overallScore;
} Player_t;

struct Game_T {
	unsigned long GameId;
	unsigned long PlayerID01;
	unsigned long PlayerID02;
	unsigned long Score;
	int Winner;
	int Status;
	struct Game_T *Next;
};
//typedef struct Game_T game_t;

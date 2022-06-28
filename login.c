#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fp;
char linha[110];
char *sub, user[50], password[50];
int opcao;

struct usuario
{
    char login[50];
    char senha[50];
};

int validUsuario(char** login){
    fp = fopen("login.txt", "r");
    while (fscanf(fp, "%s %s", user, password) != -1)
    {
        if(!strcmp(login,user)){
           printf("Usuario já existe\n");
           fclose(fp);
           return 1;            
        }
    }
    return 0;
}

void cadastrar(struct usuario usr){
    printf("Cadastro de usuário: \n");

    do {
        printf("login: ");
        scanf("%s", usr.login);
    }while(validUsuario(usr.login));

    printf("senha: ");
    scanf("%s", usr.senha);    

    char dados[110] = "";
    strcat(dados, usr.login);
    strcat(dados, " ");
    strcat(dados, usr.senha);

    fp = fopen("login.txt", "a");
    if (fp == NULL)
    {
        printf("Não foi possível abrir o arquivo");
    }
    else
    {
        fputs(dados, fp);
        fputs("\n", fp);
        fclose(fp);
    }
}

int login(struct usuario usr)
{   int tentativas = 0;
    while (tentativas < 3)
    {
        printf("login> ");
        scanf("%s", usr.login);
        printf("senha> ");
        scanf("%s", usr.senha);

        while (fscanf(fp, "%s %s", user, password)!= -1)
        {
            if(!strcmp(usr.login,user)){
                if(!strcmp(usr.senha,password)){
                    printf("Logado!\n");
                    return 1;
                }
            }
        }
    }
    printf("Dados não encontrados\n");
    cadastrar(usr);
    fclose(fp);      
    return 0;
}

int main(int argc, char *argv[])
{
    struct usuario usr;

    printf("Informe a opção desejada:\n");
    printf(" 1 - Logar\n");
    printf(" 2 - Cadastrar\n");
    printf(" 3 - Sair\n");

    scanf("%d", &opcao);
    fp = fopen("login.txt", "r");
    if(opcao == 1 && fp){
        login(usr);
    }else if (opcao == 2)
    {
        cadastrar(usr);
    }
    return 0;
}
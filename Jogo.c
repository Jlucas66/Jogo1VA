/*
Programa: Jogo Escape Room simples
Autor: João Lucas de Araújo Pereira
Versão 1.0
Jogo realizado para a 2° avaliação de aprendizagem da cadeira Introdução à
Programação I do curso Bacharelado em Ciência da computação da UFRPE. Professor:
George Moreno
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int i, j, larg = 20, tam = 20;
int gameover, score;
int x, y, fruitx, fruity, flag;

// Função para gerar a comida.
void setup()
{
    gameover = 0;

    x = larg / 2;
    y = tam / 2;
label1:
    fruitx = rand() % 20;
    if (fruitx == 0)
        goto label1;
label2:
    fruity = rand() % 20;
    if (fruity == 0)
        goto label2;
    score = 0;
}

// Função para desenhar o cenário
void desenha()
{
    system("cls");
    for (i = 0; i < larg; i++) {
        for (j = 0; j < tam; j++) {
            if (i == 0 || i == tam - 1
                || j == 0
                || j == larg - 1) {
                printf("*");
            }
            else {
                if (i == x && j == y)
                    printf("<>");
                else if (i == fruitx
                         && j == fruity)
                    printf("*");
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("Sua pontuação é: = %d", score);
    printf("\n");
    printf("Aperte X para sair do jogo.");
}

// Função para registrar os comandos
void input()
{
    if (kbhit()) {
        switch (getch()) {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'd':
            flag = 3;
            break;
        case 'w':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}

// Função para a lógica de todo o programa
void logic()
{
    sleep(0.1);
    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }


    if (x < 0 || x > larg
        || y < 0 || y > tam)
        gameover = 1;


    if (x == fruitx && y == fruity) {
    label3:
        fruitx = rand() % 20;
        if (fruitx == 0)
            goto label3;

    label4:
        fruity = rand() % 20;
        if (fruity == 0)
            goto label4;
        score += 10;
    }
}

// Main do projeto, executa todos os comandos.
void main()
{
    int m, n;


    setup();


    while (!gameover) {


        desenha();
        input();
        logic();
    }
}

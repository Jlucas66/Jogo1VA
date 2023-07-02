/*
Programa: Jogo Escape Room simples
Autor: João Lucas de Araújo Pereira
Versão 1.0
Jogo realizado para a 2° avaliação de aprendizagem da cadeira Introdução à
Programação I do curso Bacharelado em Ciência da computação da UFRPE. Professor:
George Moreno
*/
// função static
// definir a função para definir as posições aleatoriamente das paredes
//

//  bibliotecas
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <time.h>
#include <unistd.h>

int i, j, t, tamanho = 40, lado = 40;
int x, y, flag,  gameover = 0, score;

void posxy(int x, int y) { // função para definir a posição do boneco
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){x, y});
} 
void posi(){
  if(kbhit()){
    switch(getch()){
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
void aleat(){
  srand(time(NULL));
   t = rand();
   printf("%d", t % 40);

}

int main(void) {
  aleat();
while (!gameover)
{

  for (i = 0; i < 50; i++) {
    posxy(i + t, 0);
    printf("%c", 219);
    sleep(5);
  }
  for (i = 0; i < 20; i++) {
    posxy(50, i + t);
    printf("%c", 219);
    sleep(5);
  }
  for (i = 50; i >= 0; i--) {
    posxy(i + t, 20);
    printf("%c", 219);
    sleep(5);
  }
  for (i = 20; i >= 0; i--) {
    posxy(0, i + t);
    printf("%c", 219);
    sleep(5);
  }
}
  return 0;
}

/* script
- criar as paredes e tentar fazer com que elas se movam aleatoriamente.
- criar o boneco e fazer com que ele se mova de acordo com os comandos do
usuário.
- fazer com que, se o boneco tocar nas paredes, o jogo acabe.
- colocar um tempo para que depois de alguns segundos as paredes comecem a
fechar, tornando o jogo mais difícil.
- tentar colocar um controlador de velocidade do boneco, para que o jogo fique
mais interativo.
*/

#include "Game.hpp"

int main( int argc, char* args[] )
{
	int bombas, linhas, colunas;
	Game* game = NULL;
	system("clear");

	printf("Digite a quantidade de linhas do tabuleiro (10 a 30): ");
	scanf("%d", &linhas);
	while (linhas<10 || linhas >30){
		system("clear");
		printf("Entrada invalida\nDigite a quantidade de linhas do tabuleiro (10 a 30): ");
		scanf("%d", &linhas);
	}

	system("clear");
	printf("Digite a quantidade de colunas do tabuleiro (10 a 30): ");
	scanf("%d", &colunas);
	while (colunas<10 || colunas >30){
		system("clear");
		printf("Entrada invalida\nDigite a quantidade de colunas do tabuleiro (10 a 30): ");
		scanf("%d", &colunas);
	}

	system("clear");
	printf("Digite a quantidade de bombas do tabuleiro (%d ate %d): ", colunas*linhas/10, colunas*linhas/2);
	scanf("%d", &bombas);
	while (bombas < colunas*linhas/10 || bombas > colunas*linhas/2){
		system("clear");
		printf("Entrada invalida\nDigite a quantidade de bombas do tabuleiro (%d ate %d): ", colunas*linhas/10, colunas*linhas/2);
		scanf("%d", &bombas);
	}
	
	game = new Game(linhas,colunas,bombas);
	
	delete [] game;
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//Crear tres mapas
// Primero las funciones que carguen cada mapa

void cargarmapa1(int matrizjuego[20][30]);
void cargarmapa2();
void cargarmapa3();
void menu();
void motordejuego();
void pintarmapa(int matrizjuego[20][30]);
void movimientopacman(int matrizjuego[20][30], int posicionpacman[2]);
void OcultaCursor();

int main() {
	
	motordejuego();
	
	return 0; 	
}

void cargarmapa1(int matrizjuego[20][30]){
	
	int mapa[20][30]={
		
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,5,4,4,4,4,4,4,4,4,4,4,4,4,4,1,1,4,4,4,4,4,4,4,4,4,4,5,4,1},
		{1,4,1,4,1,1,4,1,1,1,1,4,1,4,4,1,1,4,1,4,4,4,1,1,1,4,4,4,4,1},
		{1,4,1,4,1,1,4,1,1,4,4,4,1,4,4,4,4,4,1,1,4,4,1,1,1,4,4,4,4,1},
		{1,4,1,4,1,1,4,1,1,4,4,4,4,4,4,4,4,4,1,1,4,4,1,4,4,4,4,4,4,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,1,1,4,4,4,4,1,4,4,4,1,4,1},
		{4,4,1,1,1,1,1,4,4,4,4,4,1,1,1,1,4,4,4,1,4,4,4,1,4,4,4,1,4,4},
		{1,4,4,4,4,4,1,4,4,4,4,4,1,6,7,1,4,4,4,1,4,4,4,1,4,4,4,1,4,1},
		{1,4,4,4,4,4,1,4,4,4,4,4,1,8,9,1,4,4,4,1,4,4,4,1,4,4,4,4,4,1},
		{1,4,4,4,1,1,1,4,4,4,4,4,1,1,1,1,4,4,4,1,4,4,4,1,1,1,1,4,4,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{1,4,4,4,4,4,4,4,1,4,4,4,1,1,1,1,4,4,4,4,1,4,4,4,4,4,4,4,4,1},
		{1,4,4,4,1,4,4,4,1,4,4,4,4,0,4,4,4,4,4,4,1,4,4,4,1,4,4,4,4,1},
		{1,5,1,4,1,4,4,4,1,4,4,4,1,1,1,1,4,4,4,4,1,4,4,4,1,4,4,5,4,1},
		{1,4,1,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,1,4,4,4,4,1},
		{1,4,1,4,1,1,1,1,1,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,1,4,4,1,4,1},
		{1,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,1,4,4,4,4,4,4,4,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}		
	};
	
	int i,j;
	
	for (i=0; i<=19; i++){
		for (j=0; j<=29; j++){
			matrizjuego[i][j]=mapa[i][j];
		}
		
	}
		
}

void menu(){
	
}

void motordejuego(){
	
	int matrizjuego[20][30];
	int posicionpacman[2];
	posicionpacman[0]=13;
	posicionpacman[1]=13;
		
	cargarmapa1(matrizjuego);
	do{
		pintarmapa(matrizjuego);
		movimientopacman(matrizjuego, posicionpacman);
	//	system ("pause");
		system ("cls");
	}while(true);
}

void pintarmapa(int matrizjuego[20][30]){
	int i,j; 
	for (i=0; i<=19; i++){
		for (j=0; j<=29; j++){
			printf("%d", matrizjuego[i][j]);
		}
		printf("\n");
	}
	
}

void movimientopacman(int matrizjuego[20][30], int posicionpacman[2]){
	char tecla;
	tecla=getch();

	
	// si se pone w es que el pacman va hacia arriba
	if (tecla=='w'){
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
		posicionpacman[0]=posicionpacman[0]-1;
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
	}
	// si se pone s es que el pacman va hacia abajo
	else if (tecla=='s'){
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
		posicionpacman[0]=posicionpacman[0]+1;
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
	}
	else if (tecla=='d'){
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
		posicionpacman[1]=posicionpacman[1]+1;
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
	}
	else if (tecla=='a'){
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
		posicionpacman[1]=posicionpacman[1]-2;
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
	}
}	
	
void OcultaCursor() { // Oculta la flechita el cuadro que parpadea en el ejecutable y se pone antes de la generacion de cualquier cosa.
	
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}












	


#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>

#define VELOCIDAD 220 //Importante no usar valores negativos

//Crear tres mapas
// Primero las funciones que carguen cada mapa

void cargarmapa1(int matrizjuego[20][30]);
void cargarmapa2();
void cargarmapa3();
void menu();
void motordejuego();
void pintarmapa(int matrizjuego[20][30], BITMAP *buffer);
void movimientopacman(int matrizjuego[20][30], int posicionpacman[2]);
void init();

int main() {
	
	init();
	motordejuego();
	
	return 0; 	
}
END_OF_MAIN();

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
	BITMAP *buffer = create_bitmap(960,660);
		
	cargarmapa1(matrizjuego);
	do{
		pintarmapa(matrizjuego,buffer);
		movimientopacman(matrizjuego, posicionpacman);
		//system ("pause");
		//system ("cls");
		blit(buffer,screen,0,0,0,0,960,660);
		clear(buffer);//Borramos el buffer
		rest(VELOCIDAD);//Maneja la velocidad del juego. Entre más alto el parámetro, más lento el juego
	}while(true);
}

void pintarmapa(int matrizjuego[20][30], BITMAP *buffer){
	int i,j; 
	BITMAP *vectorMapa[10];
	vectorMapa[0] = load_bitmap("CuerpoPacman_II.bmp", NULL); //PACMAN;
	vectorMapa[1] = load_bitmap("Bloques_7.bmp", NULL); //BLOQUE
	vectorMapa[2] = load_bitmap("PuntosChicos.bmp", NULL); // Puntos chicos
	vectorMapa[3] = load_bitmap("Espacio.bmp", NULL);
	
	for (i=0; i<=19; i++){
		for (j=0; j<=29; j++){
			if(matrizjuego[i][j] == 1){ //BLOQUE
				draw_sprite(buffer,vectorMapa[1],j*30,i*30+35);
			}
			else if(matrizjuego[i][j] == 0){ //PACMAN
				draw_sprite(buffer,vectorMapa[0],j*30,i*30+35);
			}
			else if (matrizjuego[i][j] == 4) {
				draw_sprite(buffer, vectorMapa[2], j*30, i*30+35);
			}
			else if (matrizjuego[i][j]== 2){
				draw_sprite(buffer, vectorMapa[3], j*30, i*30+35);
			}
		}
		//printf("\n");
	}
	
}

void movimientopacman(int matrizjuego[20][30], int posicionpacman[2]){


	
	// si se pone w es que el pacman va hacia arriba
	
	if (key[KEY_W]){
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
		posicionpacman[0]=posicionpacman[0]-1;
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
	}
	// si se pone s es que el pacman va hacia abajo
	else if (key[KEY_S]){
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
		posicionpacman[0]=posicionpacman[0]+1;
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
	}
	else if (key[KEY_D]){
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
		posicionpacman[1]=posicionpacman[1]+1;
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
	}
	else if (key[KEY_A]){
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
		posicionpacman[1]=posicionpacman[1]-2;
		matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
	}
}	
	
void init (){
	
	int depth, res,cancion;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 900, 635, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
	set_window_title("Pac_Man Game");

	install_timer();
	install_keyboard();
	install_mouse();
	show_mouse(screen);
} 











	


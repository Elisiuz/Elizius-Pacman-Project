#include <stdio.h>   
#include <stdlib.h> 
#include <allegro.h>
#include <string.h> 

#define VELOCIDAD 200 //Importante no usar valores negativos

//Crear tres mapas
// Primero las funciones que carguen cada mapa

void cargarmapa1(int matrizjuego[20][30]); 
void cargarmapa2();
void cargarmapa3(); 
void menu();
void motordejuego();
void pintarmapa(int matrizjuego[20][30], BITMAP *buffer, int *poderactivo, int vidaspacman, int score_frutas, int nivel);
void movimientopacman(int matrizjuego[20][30], int posicionpacman[2], int *poderactivo, int *muertepacman, int *score, int *score_frutas);
void init();
void submenuJugar(); 
void Nuevojuego();
int continuarjuego();
void regresar();
int verificarUsuario(char usuario[]);
void IngresarUsuario (char usuario[], char password[]);
void FantasmaNaranja(int matrizjuego[20][30], int posicionnaranja[2], int *posicion_guardada, int *muertepacman); //es el que se mueve aleatoriamente
void FantasmaRojo (int matrizjuego[20][30], int posicionrojo[2], int *posicion_guardada, int *muertepacman);//AQUÍ VA FANTASMA ROJO
void SacarFantasma (int matrizjuego[20][30], int posicionnaranja[2], int posicionroja[2], int posicionrosa[2], int posicionazul[2], int turno);
void MostrarFruta (int matrizjuego[20][30]);
void Reinicio (int matrizjuego[20][30], int posicionpacman[2],int posicsionnaranja[2], int posicionroja[2], int posicionrosa[2], int posicionazul[2]);

int main() {
	srand(time(NULL));
	init();
	motordejuego();

//	menu();
	
	return 0; 	
}
END_OF_MAIN();

void cargarmapa1(int matrizjuego[20][30]){
	
	int mapa[20][30]={
	//	 0 1 3 4 5 6 7 8 9 1011121314             14  
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,1,4,4,1,4,4,4,4,4,4,4,4,4,4,4,5,4,1},
		{1,4,5,4,1,1,4,1,1,1,1,4,4,4,4,4,4,4,4,4,4,4,1,1,1,4,4,4,4,1},
		{1,4,1,4,1,1,4,1,1,4,4,4,1,1,1,1,4,4,1,1,4,4,1,1,1,4,4,4,4,1},
		{1,4,1,4,1,1,4,1,1,4,4,4,4,4,4,4,4,4,1,1,4,4,1,1,4,4,4,4,4,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,1,4,1},
		{4,4,1,1,1,1,1,4,4,4,4,4,1,1,1,1,4,4,4,1,4,4,4,1,4,4,4,4,4,4},
		{1,4,4,4,4,4,1,4,4,1,4,4,1,6,7,1,4,4,4,1,4,4,4,1,4,4,4,1,4,1},
		{1,4,4,4,4,4,1,4,4,1,4,4,1,8,9,1,4,4,4,1,4,4,4,1,4,4,4,4,4,1}, // 10
		{1,4,4,4,1,1,1,4,4,1,4,4,1,1,1,1,4,4,4,1,4,4,4,1,1,1,1,4,4,1},
		{1,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,1,1,1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,1},
		{1,4,4,4,1,4,4,4,1,4,4,4,4,0,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,1},
		{1,5,1,4,1,4,4,4,1,4,4,4,1,1,1,1,4,4,4,4,4,4,4,4,1,4,4,5,4,1},
		{1,4,1,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,4,4,4,1},
		{1,4,1,4,1,1,1,1,1,4,4,4,1,1,1,1,4,4,4,4,1,1,1,1,1,4,4,1,4,1},
		{1,4,1,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1,4,1},
		{1,4,4,4,4,4,4,4,4,4,4,4,1,4,4,1,4,4,4,4,4,1,4,4,4,4,4,4,4,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}		
	};
	
	int i,j;
	
	for (i=0; i<=19; i++){
		for (j=0; j<=29; j++){
			matrizjuego[i][j]=mapa[i][j];
		}
		
	}
		
}

void submenuJugar(){
	int nuevaopcion;
	printf("1. Nuevo juego\n");
	printf("2. Continuar juego \n");
	printf("3. Regresar \n");
	scanf ("%i", &nuevaopcion);
	
	switch (nuevaopcion){
		case 1:
			Nuevojuego();
			break;
		case 2: 
			if (continuarjuego()==1){
				printf("Usuario o contrasena correctos\n");
			}else{
				printf("Usuario o contrasena incorrectos\n");
			}
			break;
		case 3: 
			regresar();
			break;
	}
}

void Nuevojuego(){

	char usuario[20];
	char password[20];
	int ocupado=1;
	int intentos=0;
	
	do {
		printf ("Ingrese nombre de  usuario \n");
		fflush(stdin);
		gets(usuario);
		printf ("Ingrese password \n");
		fflush(stdin);
		gets(password);
		ocupado=verificarUsuario(usuario);
		if (ocupado==0){
			IngresarUsuario(usuario, password);
		}
		else{
			printf("El Usuario no está disponible elija otro\n");
		}
		intentos++;	
	}
	while (ocupado==1 && intentos<3);
}

void IngresarUsuario (char usuario[], char password[]){
	
	FILE *arch;
	arch=fopen("usuarios.txt", "a");
	
	char linea[20];
	
	fprintf(arch,"%s\n%s\n", usuario, password);

	fclose (arch);
}

int verificarUsuario(char usuario[]){
	
	FILE *arch;
	arch=fopen("usuarios.txt", "r");
	char linea[20];
	
	while (fgets(linea, 20, arch) != NULL){
		if (strcmp(usuario, linea)==0){
			fclose(arch);
			return 1; // Esto significa que el usuario no está disponible. 
		}
	}
	fclose(arch);
	return 0;
}

int continuarjuego(){
	char usuario[20];
	char password[20];
	
	printf("Ingrese el nombre del usuario\n");
	fflush(stdin);
	fgets (usuario, 20, stdin);
	printf("Ingrese el password\n");
	fflush(stdin);
	fgets (password, 20, stdin);
	
	FILE *arch;
	arch=fopen ("usuarios.txt", "r");
	char linea[20]; 
	
	while(fgets(linea,20,arch) !=NULL){
		if (strcmp(usuario, linea)==0){
			fgets (linea,20,arch);
			if (strcmp(password, linea)==0){
				return 1; // Esto significa que el usuario y la contraseña son correctos.  
			}				
			break;
		}
			
		}
	return 0; 
}

void regresar(){
	
}

void menu(){
	int opcion; 
	printf("1. Jugar\n");
	printf("2. Puntuaciones\n");
	printf("3. Ayuda \n");
	printf ("4. Salir \n");
	scanf ("%i", &opcion);
	
	switch (opcion){
		case 1:
			submenuJugar();
			break;
		case 2: 
			break;
		case 3:
			break;
		case 4:
			break;
	}
}

void motordejuego(){
	
	FONT *font1=load_font("letritas.pcx", NULL,NULL);
	
	int score=0;
	int matrizjuego[20][30];
	int posicionpacman[2];
	int posicionnaranja[2];
	int posicionroja[2];
	int posicionrosa[2]; 
	int posicionazul[2];
	int TiempoSalida = 0; 
	int posicion_guardada=4;
	int poderactivo=0;
	int TiempoPoder=0;
	int muertepacman=0; 
	int vidaspacman=3;
	int score_frutas=0;
	int turno=0;
	int nivel=1;
	BITMAP *buffer = create_bitmap(960,660);
	BITMAP *findejuego = load_bitmap("perdiste.bmp", NULL);
	
	do{
		TiempoSalida=0;
		posicion_guardada=4;
		poderactivo=0;
		TiempoPoder=0;
		muertepacman=0;
		vidaspacman=3;
		turno=0;
		score=0;
		posicionpacman[0]=13;
		posicionpacman[1]=13;
	
		
		//posiciones iniciales de los fantasmas en el mapa
		
		posicionnaranja[0]=9;
		posicionnaranja[1]=14;
		
		posicionroja[0]=8; 
		posicionroja[1]=13;
		
		posicionrosa[0]=8;
		posicionrosa[1]=14;
		
		posicionazul[0]=9;
		posicionazul[1]=13;
		
		cargarmapa1(matrizjuego);
		MostrarFruta(matrizjuego);
		do{  
			pintarmapa(matrizjuego,buffer, &poderactivo, vidaspacman, score_frutas, nivel);
			movimientopacman(matrizjuego, posicionpacman, &poderactivo, &muertepacman, &score, &score_frutas);
			TiempoSalida++;
			if (TiempoSalida==10){
				SacarFantasma(matrizjuego, posicionnaranja, posicionroja, posicionrosa, posicionazul, 0);			
			}
			if (TiempoSalida==20){
				SacarFantasma(matrizjuego, posicionnaranja, posicionroja, posicionrosa, posicionazul, 1);			
			}
			if (TiempoSalida==30){
				SacarFantasma(matrizjuego, posicionnaranja, posicionroja, posicionrosa, posicionazul, 2);			
			}
			if (TiempoSalida==40){
				SacarFantasma(matrizjuego, posicionnaranja, posicionroja, posicionrosa, posicionazul, 3);			
			}  
			if (TiempoSalida>10){
				//FantasmaNaranja(matrizjuego, posicionnaranja, &posicion_guardada, &muertepacman);  
			}		
			if (poderactivo==1){
				TiempoPoder++;
			}
			if (TiempoPoder>30){
				poderactivo=0;
				TiempoPoder=0;
			}
			if (muertepacman==1){
				Reinicio(matrizjuego, posicionpacman, posicionnaranja, posicionroja, posicionrosa, posicionazul); //Esto es ciuando pierde una vida
				muertepacman=0;
				TiempoSalida=0;
				vidaspacman--;
			}
			//system ("pause");
			//system ("cls"); 
			blit(buffer,screen,0,0,0,0,960,660);
			textprintf(screen, font1,0,-2,makecol(255,153,51),"score: %i",score);  
			textprintf(screen, font1,200,-2,makecol(8,211,251),"[Esc] Pausa");	    
			textprintf(screen, font1,400,-2,makecol(251,236,8),"Nivel: %i", nivel);
	
			clear(buffer);//Borramos el buffer
			rest(VELOCIDAD);//Maneja la velocidad del juego. Entre más alto el parámetro, más lento el juego
		}while(vidaspacman>0 && score<30);
		//Significa que pasó de nivel
		if(score>=30){
			nivel++;	
			printf("ENTRA");
			continue;
		}
		///Muestra la pantalla de perdedor
		clear_keybuf();//Borramos el buffer de entrada del teclado
		clear(buffer);
		do{
			blit(findejuego, buffer, 0, 0, 0, 0, 900, 660);
			blit(buffer, screen, 0, 0, 0, 0, 960, 660);			
		}while(!key[KEY_ESC]);
		nivel = 1;
		score_frutas = 0;
	}while(true);

}
 
void pintarmapa(int matrizjuego[20][30], BITMAP *buffer, int *poderactivo, int vidaspacman, int score_frutas, int nivel){
	int i,j; 
	BITMAP *vectorMapa[15];
	vectorMapa[0] = load_bitmap("CuerpoPacman_II.bmp", NULL); //PACMAN;
	vectorMapa[1] = load_bitmap("Bloques_7.bmp", NULL); //BLOQUE
	vectorMapa[2] = load_bitmap("Espacio.bmp", NULL);
	vectorMapa[3] = load_bitmap("Fruta 1.bmp", NULL);
	vectorMapa[4] = load_bitmap("PuntosChicos.bmp", NULL); // Puntos chicos
	vectorMapa[5] = load_bitmap("PuntosGrandes.bmp", NULL);
	vectorMapa[6] = load_bitmap("FantasmaBlinky_Abajo.bmp", NULL);
	vectorMapa[7] = load_bitmap("FantasmaPinky_I.bmp", NULL);
	vectorMapa[8] = load_bitmap("FantasmaInky_D.bmp", NULL);
	vectorMapa[9] = load_bitmap("FantasmaClyde_Arriba.bmp", NULL); 
	vectorMapa[11] = load_bitmap("Espacio.bmp", NULL);
	
	if (nivel==1){
		vectorMapa[3]=load_bitmap("Fruta 1.bmp", NULL);
	}
	else if (nivel==2){
		vectorMapa[3]=load_bitmap("Fruta 2.bmp", NULL);
	}
	else if (nivel==3){
		vectorMapa[3]=load_bitmap("Fruta 3.bmp", NULL);
	}
	else if (nivel==4){
		vectorMapa[3]=load_bitmap("Fruta 4.bmp", NULL);
	}
	
	if (*poderactivo==1){
		vectorMapa[6]=load_bitmap("Fantasmas_Asustados.bmp", NULL);
		vectorMapa[7]=load_bitmap("Fantasmas_Asustados.bmp", NULL);
		vectorMapa[8]=load_bitmap("Fantasmas_Asustados.bmp", NULL);
		vectorMapa[9]=load_bitmap("Fantasmas_Asustados.bmp", NULL);
	}
	
	if (vidaspacman==3){
		vectorMapa[10]=load_bitmap("Vidas3.bmp", NULL); 
	} 
	else if (vidaspacman==2){
		vectorMapa[10]=load_bitmap("Vidas2.bmp", NULL);
	}
	else {
		vectorMapa[10]=load_bitmap("Vidas1.bmp", NULL);
	}
	
	draw_sprite(buffer, vectorMapa[10], 750,0); //Es para que pinte las frutas
	printf("El score frutas es: %d\n",score_frutas);
	if (score_frutas==1){
		vectorMapa[11]= load_bitmap("1Frutas.bmp", NULL);
	}
	else if (score_frutas==2){
		vectorMapa[11]= load_bitmap("2Frutas.bmp", NULL);
	}
	else if (score_frutas==3){
		vectorMapa[11]= load_bitmap ("3Frutas.bmp", NULL);
	}
	else if (score_frutas==4){
		vectorMapa[11]= load_bitmap ("4Frutas.bmp", NULL);
	}
	else if (score_frutas==5){
		vectorMapa[11]= load_bitmap ("5Frutas.bmp", NULL);
	}
	
	draw_sprite(buffer, vectorMapa[11], 550,0);
	
	
	for (i=0; i<=19; i++){
		for (j=0; j<=29; j++){
			if(matrizjuego[i][j] == 1){ //BLOQUE
				draw_sprite(buffer,vectorMapa[1],j*30,i*30+35);
			}
			else if(matrizjuego[i][j] == 0){ //PACMAN
				draw_sprite(buffer,vectorMapa[0],j*30,i*30+35);
			}
			else if (matrizjuego[i][j] == 4) {
				draw_sprite(buffer, vectorMapa[4], j*30, i*30+35);
			}
			else if (matrizjuego[i][j]== 2){
				draw_sprite(buffer, vectorMapa[2], j*30, i*30+35);
			}
			else if (matrizjuego[i][j]==6){
				draw_sprite(buffer, vectorMapa[6], j*30, i*30+35);
			}
			else if (matrizjuego[i][j]==8){
				draw_sprite(buffer, vectorMapa[8], j*30, i*30+35);
			}
			else if (matrizjuego[i][j]==9){
				draw_sprite(buffer, vectorMapa[9], j*30, i*30+35);
			}
			else if (matrizjuego[i][j]==7){
				draw_sprite(buffer, vectorMapa[7], j*30, i*30+35);
			}
			else if (matrizjuego[i][j]==5){
				draw_sprite(buffer, vectorMapa[5], j*30, i*30+35);
			}
			else if (matrizjuego[i][j]==3){
				draw_sprite (buffer, vectorMapa[3], j*30, i*30+35);
			}
		}
		//printf("\n");
	}
}

void movimientopacman(int matrizjuego[20][30], int posicionpacman[2], int *poderactivo, int *muertepacman, int *score, int *score_frutas){	
	// si se pone w es que el pacman va hacia arriba
	
	if (key[KEY_W]){	
		if (matrizjuego [posicionpacman[0]-1 ] [posicionpacman[1]] !=1){	
			if (matrizjuego[posicionpacman[0]-1 ] [posicionpacman[1]]==5){	// 5 es un poder activo
				*poderactivo=1;
			}
			if (matrizjuego[posicionpacman[0]-1][posicionpacman[1]]==9){ // 9 es el fantasma
				*muertepacman=1;
				return;
			} 
			if (matrizjuego[posicionpacman[0]-1][posicionpacman[1]]==3){ // esto es cuando se come la fruta
				*score=*score+3;
				*score_frutas=*score_frutas+1;
			}
			if (matrizjuego[posicionpacman[0]-1 ] [posicionpacman[1]]==4){ // esto es cuando se come un punto chico
				*score=*score+1;	
			}
			matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
			posicionpacman[0]=posicionpacman[0]-1;
			matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
		}
	}
	// si se pone s es que el pacman va hacia abajo
	else if (key[KEY_S]){
		if (matrizjuego [posicionpacman[0]+1] [posicionpacman[1]] !=1){
			if (matrizjuego[posicionpacman[0]+1] [posicionpacman[1]]==5){
				*poderactivo=1;
			}
			if (matrizjuego[posicionpacman[0]+1][posicionpacman[1]]==9){
				*muertepacman=1; // Esto representa la muerte del pacman. 
				return;
			}
			if (matrizjuego[posicionpacman[0]+1][posicionpacman[1]]==3){
				*score=*score+3;
				*score_frutas=*score_frutas+1;
			}
			if (matrizjuego[posicionpacman[0]+1] [posicionpacman[1]]==4){
				*score=*score+1;
			}
			matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
			posicionpacman[0]=posicionpacman[0]+1;
			matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
		}
	}
	else if (key[KEY_D]){
		if (matrizjuego [posicionpacman[0]] [posicionpacman[1]+1] !=1){
			if (matrizjuego[posicionpacman[0]] [posicionpacman[1]+1]==5){
				*poderactivo=1;
			}
			if (matrizjuego[posicionpacman[0]][posicionpacman[1]+1]==9){
				*muertepacman=1;
				return;
			}
			if (matrizjuego[posicionpacman[0]][posicionpacman[1]+1]==3){
				*score=*score+3;
				*score_frutas=*score_frutas+1;
			}
			if (matrizjuego[posicionpacman[0]][posicionpacman[1]+1]==4){
				*score=*score+1;
			}
			matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
			posicionpacman[1]=posicionpacman[1]+1;
			matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
			}
			if (posicionpacman[0]==7 && posicionpacman[1]==29){ //es el teleport de los lados, por eso esta disinto
				posicionpacman[0]=7;
				posicionpacman[1]=0;
				matrizjuego [posicionpacman[0]] [posicionpacman[1]]=0;
				matrizjuego[7][29]=2;
			}
		}
	
	else if (key[KEY_A]){
		if (matrizjuego[ posicionpacman[0]] [posicionpacman[1]-1] !=1){
			if (matrizjuego[posicionpacman[0]] [posicionpacman[1]-1]==5){
				*poderactivo=1;
			}
			if (matrizjuego[posicionpacman[0]][posicionpacman[1]-1] ==9){
				*muertepacman=1;
				return;
			}
			if (matrizjuego[posicionpacman[0]][posicionpacman[1]-1]==3){
				*score=*score+3;
				*score_frutas=*score_frutas+1;
			}
			if (matrizjuego[posicionpacman[0]] [posicionpacman[1]-1]==4){
				*score=*score+1;
			}
			matrizjuego[posicionpacman[0]][posicionpacman[1]]=2;
			posicionpacman[1]=posicionpacman[1]-1;
			matrizjuego[posicionpacman[0]][posicionpacman[1]]=0;
			
			if (posicionpacman[0]==7 && posicionpacman[1]==0){
				posicionpacman[0]=7;    
				posicionpacman[1]=29;   
				matrizjuego [posicionpacman[0]] [posicionpacman[1]]=0;
				matrizjuego[7][0]=2;
			}
		}
	}	
}

void FantasmaNaranja (int matrizjuego[20][30], int posicionnaranja[2], int *posicion_guardada, int *muertepacman){
	int posicion=rand() %4; // Genera numeros aleatorios para moverse en las cuatro direcciones 		
	//posicion=-1;
	
	switch (posicion){
		case 0: //Izquierda
			if(matrizjuego[posicionnaranja[0]][posicionnaranja[1]-1] !=1){
				matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=*posicion_guardada;
				if (matrizjuego[posicionnaranja[0]] [posicionnaranja[1]-1]==0){
					*muertepacman=1;
					printf("Mato");
					return;
				}
				posicionnaranja[1]=posicionnaranja[1]-1;
				*posicion_guardada=matrizjuego[posicionnaranja[0]][posicionnaranja[1]];
				if (*posicion_guardada==0){
					*posicion_guardada=2;
				}
			
				
				matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9;				
				if (posicionnaranja[0]==7 && posicionnaranja[1]==0){ // Esto es el teleport de los hoyos de las paredes
					posicionnaranja[0]=7;
					posicionnaranja[1]=29;
					matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9;
					matrizjuego[7][0]=2;
				} 
			}		
		break;
		case 1: //Derecha
			if(matrizjuego[posicionnaranja[0]][posicionnaranja[1]+1] !=1){
				matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=*posicion_guardada;
				if (matrizjuego[posicionnaranja[0]][posicionnaranja[1]+1]==0){
					*muertepacman=1;
					printf("Mato");
					return;
				}
				posicionnaranja[1]=posicionnaranja[1]+1;
				*posicion_guardada=matrizjuego[posicionnaranja[0]][posicionnaranja[1]];
				if (*posicion_guardada==0){
					*posicion_guardada=2;
				}
				
				matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9;
				if (posicionnaranja[0]==7 && posicionnaranja[1]==29){
					posicionnaranja[0]=7;
					posicionnaranja[1]=0;
					matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9;
					matrizjuego[7][29]=2;
				} 
			}
		break; //Arriba
		case 2:
			if(matrizjuego[posicionnaranja[0]-1][posicionnaranja[1]] !=1){
				matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=*posicion_guardada;
				if (matrizjuego[posicionnaranja[0]-1][posicionnaranja[1]]==0){
					*muertepacman=1;
					printf("Mato");
					return;
				}
				posicionnaranja[0]=posicionnaranja[0]-1;
				*posicion_guardada=matrizjuego[posicionnaranja[0]][posicionnaranja[1]];
				if (*posicion_guardada==0){
					*posicion_guardada=2;
				}	
				matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9;
			}
		break; //Abajo
		case 3:
			if(matrizjuego[posicionnaranja[0]+1][posicionnaranja[1]] !=1){
				matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=*posicion_guardada;
				if (matrizjuego[posicionnaranja[0]+1][posicionnaranja[1]]==0){
					*muertepacman=1;
					printf("Mato");
					return;
				}
				posicionnaranja[0]=posicionnaranja[0]+1;
				*posicion_guardada=matrizjuego[posicionnaranja[0]][posicionnaranja[1]];
				if(*posicion_guardada==0){
					*posicion_guardada=2;
				}
			
				matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9;
			}
		break;
	} 
//	matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9;
	
//Ojo: el fantasma sale del corral al principio y cuando te lo comes regresa, sería conveniente la función "sacar y meter fantasmas".
}
 
void FantasmaRojo (int matrizjuego[20][30], int posicionrojo[2], int *posicion_guardada, int posicionpacman[2], int *muertepacman){
	
	int direccionHorizontal, direccionVertical;
	
	if(posicionrojo[0] > posicionpacman[0]){
		//El fantasma está en filas abajo del pacman
		//por lo tanto el fantasma tiene que ir hacia arriba
		direccionVertical = 1; //Aquí el 1 significa que debe ir hacia arriba
	}
	else if(posicionrojo[0] < posicionpacman[0]){
		//El fantasma se debe de mover hacia abajo
		direccionVertical = 2; 
	}
	else{
		direccionVertical = 0; //No se debe de mover de fila
	}
	
	if(posicionrojo[1] > posicionpacman[1]){
		//El fantasma se debe de mover hacia la izquierda
		direccionHorizontal = 1; 
	}
	else if(posicionrojo[1] < posicionpacman[1]){
		//El fantasma se debe de mover hacia la derecha
		direccionHorizontal = 2;
	}
	else{
		//Están en la misma columna
		direccionHorizontal = 0;
	}
	
	// -1 es para arriba, para arriba siempre se resta 
	if(direccionVertical == 1 && matrizjuego[posicionrojo[0]-1] [posicionrojo[1]] != 1){
		matrizjuego[posicionrojo[0]] [posicionrojo[1]]=*posicion_guardada;
		if (matrizjuego[posicionrojo[0]-1] [posicionrojo[1]==0]){
			*muertepacman=1;		
		}
		posicionrojo[0]=posicionrojo[0]-1;
		*posicion_guardada=matrizjuego[posicionrojo[0]][posicionrojo[1]];
		if (*posicion_guardada==0){
			*posicion_guardada=2;
		}
		matrizjuego[posicionrojo[0]][posicionrojo[1]]=6; 
	}
}
 
 
void SacarFantasma (int matrizjuego[20][30], int posicionnaranja[2], int posicionroja[2], int posicionrosa[2], int posicionazul[2], int turno){
	
	switch(turno){
		case 0:
			matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=2; // Se actualiza la coordenada como un espacio vacío
			posicionnaranja[0]=7; // posicion vertical
			posicionnaranja[1]=11; // posicion horizontal
			matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9; // Se actualiza la localización del fantasma en la coordenada de arriba
			break;
			
		case 1:
			matrizjuego[posicionroja[0]][posicionroja[1]]=2;
			posicionroja[0]=8;
			posicionroja[1]=11;
			matrizjuego[posicionroja[0]][posicionroja[1]]=6; 
			break;
			
		case 2:
			matrizjuego[posicionrosa[0]][posicionrosa[1]]=2;
			posicionrosa[0]= 8;
			posicionrosa[1]= 16;
			matrizjuego[posicionrosa[0]][posicionrosa[1]]=7;
			break;
		
		case 3:
			matrizjuego[posicionazul[0]][posicionazul[1]]=2;
			posicionazul[0]=10;
			posicionazul[1]=11;
			matrizjuego[posicionazul[0]][posicionazul[1]]=8;
			break; 
	}
}

 void MostrarFruta (int matrizjuego[20][30]){
	int posicionfruta[2];

	do {
		posicionfruta[0]=rand()%20;
		posicionfruta[1]=rand()%30;
		
	} while (matrizjuego[posicionfruta[0]] [posicionfruta[1]]==1 || matrizjuego[posicionfruta[0]] [posicionfruta[1]]==0 || matrizjuego[posicionfruta[0]] [posicionfruta[1]]==7 || matrizjuego[posicionfruta[0]] [posicionfruta[1]]==8 || matrizjuego[posicionfruta[0]] [posicionfruta[1]]==9);
	
	matrizjuego[posicionfruta[0]][posicionfruta[1]]=3; 
}

void Reinicio (int matrizjuego[20][30], int posicionpacman[2],int posicionnaranja[2], int posicionroja[2], int posicionrosa[2], int posicionazul[2]){
	// Esta funcion es para reiniciar una vez que el pacman se muera al tocar a un fantasma
	
	matrizjuego[posicionpacman[0]][posicionpacman[1]]=2; // Se pone 2 porque es un espacio vacio
	posicionpacman[0]=13; //Porque es la posición de origen 
	posicionpacman[1]=13;  // posicion de origen
	matrizjuego[posicionpacman[0]][posicionpacman[1]]=0; 

	matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=2; //igual se trata de espacio vacio
	posicionnaranja[0]=9;       
	posicionnaranja[1]=14;     
	matrizjuego[posicionnaranja[0]][posicionnaranja[1]]=9; 
	
	matrizjuego[posicionroja[0]][posicionroja[1]]=2; 
	posicionroja[0]=8;  
	posicionroja[1]=13;  
	matrizjuego[posicionroja[0]][posicionroja[1]]=6;   
	    
	matrizjuego[posicionrosa[0]][posicionrosa[1]]=2;
	posicionrosa[0]=8;    
	posicionrosa[1]=14;   
	matrizjuego[posicionrosa[0]][posicionrosa[1]]=7;
	
	matrizjuego[posicionazul[0]][posicionazul[1]]=2;
	posicionazul[0]=9;
	posicionazul[1]=13; 
	matrizjuego[posicionazul[0]][posicionazul[1]]=8;
	
}

void init () {
	
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


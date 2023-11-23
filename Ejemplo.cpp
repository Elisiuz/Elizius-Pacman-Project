#include <allegro.h>

int main() {
    // Inicializar Allegro
    allegro_init();

    // Configurar Allegro
    set_color_depth(16); // Establecer profundidad de color a 16 bits
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0); // Modo de ventana de 640x480

    // Instalar el teclado
    install_keyboard();

    // Crear un bitmap para dibujar
    BITMAP *buffer = create_bitmap(640, 480);

    // Ciclo principal
    while (!key[KEY_ESC]) {
        // Dibujar en el buffer
        rectfill(buffer, 100, 100, 200, 200, makecol(255, 0, 0)); // Dibujar un rectángulo rojo

        // Copiar el buffer a la pantalla
        blit(buffer, screen, 0, 0, 0, 0, 640, 480);

        // Esperar un momento para evitar el parpadeo
        rest(16);
    }
}

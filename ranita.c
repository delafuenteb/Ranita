// simula el salto de una rana de forma aleatoria ( tamaño del salto y dirección) con la tecla space

#include <windows.h> //sirve para usar la funcion Sleep
#include <time.h>// sirve para la inicialización del generador de números
#include "uframework.h"

int main()
{

    initialize("Ejemplo uFramework", 800, 600, false);

    create_sprite("s_player_idle", 1);
    add_frame_to_sprite("s_player_idle", "frog/frog.png");

    create_sprite("s_player_left", 1);
    add_frame_to_sprite("s_player_left", "frog/frog_leap.png");

    create_sprite("s_player_right", 1);
    add_frame_to_sprite("s_player_right", "frog/frog_leap_d.png");

    srand (time(NULL));       //Instrucción que inicializa el generador de números aleatorios]

    float xPlayer=400;
    float yPlayer=200;
    int salto,direccion;

    add_indexed_object("o_player",xPlayer, yPlayer, 50, 50, "s_player_idle");

    while(!is_window_closed())
    {
        bool k_up = is_key_pressed("space");
        salto=(rand() % 150);// indica la cantidad que avanza la rana con el salto
        direccion=1+(rand() %2); // Selecciona la dirección del salto en eje X.

        if( k_up == true )
        {
            printf("Lado %d distancia %d\n",direccion,salto);
            if(direccion==1)
            {
                xPlayer=xPlayer-salto;
                yPlayer=yPlayer-50;
                set_indexed_object_sprite("o_player","s_player_left");
                set_indexed_object_origin("o_player", xPlayer, yPlayer);
                xPlayer=xPlayer-10;
            }
            else{
                xPlayer=xPlayer+salto;
                yPlayer=yPlayer-50;
                set_indexed_object_sprite("o_player","s_player_right");
                set_indexed_object_origin("o_player", xPlayer, yPlayer);
                xPlayer=xPlayer+10;
            }
            yPlayer=yPlayer+50;
            Sleep(200); //pausa de 20 milisegundos
            set_indexed_object_origin("o_player", xPlayer, yPlayer);
        }
        else
        {
             set_indexed_object_sprite("o_player","s_player_idle");
        }
        Sleep(200); //pausa de 20 milisegundos
    }
    return 0;
}

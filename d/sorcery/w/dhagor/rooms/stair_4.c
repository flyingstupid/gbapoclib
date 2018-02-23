#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Escaleras hacia los calabozos");
    set_long("La luz en este lugar ha sido tragada por la gran\n"+
             "obscuridad de los calabozos. Este lugar comienza\n"+
             "a ser un poco tetrico, en el piso algunos cuerpos\n"+
             "de animales parecen haber sido muertos hace mucho\n"+
             "tiempo, pero aun se conservan. El viento sopla un\n"+
             "poco mas fuerte en este lugar y la humedad es ya\n"+
             "muy grande. De los agujeros en las paredes, muchos\n"+
             "bichos asoman ante tu presencia.\n");
    set_items(({
             "pared#paredes", "Las paredes estan hechas de uno poderosos\n"+
                              "ladrillos de piedra gris traida de alguna\n"+
                              "importante mina. Su antiguedad parece ser\n"+
                              "de muchos siglos atras.\n",
             "escalera", "Es una grande escalera muy antigua, cuyos\n"+
                         "escalones parecen estar cubiertos de una\n"+
                         "densa capa de polvo.\n",
             "escalon#escalones", "Los escalones estan cubiertos de una\n"+
                                  "densa capa de polvo.\n",
             }));
    set_weather(0,0,0);
    set_smell("El lugar comienza a oler un poco mal..\n");
    set_listen("Escuchas el soplar del viento....\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/stair_5", "down",
                 "/d/sorcery/w/dhagor/rooms/stair_3", "up", }));
}
 

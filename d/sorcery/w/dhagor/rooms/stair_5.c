#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Escaleras hacia los calabozos");
    set_long("En el piso cientos de bichos se han amontonado ante\n"+
             "los cuerpos muertos de muchas creaturas. Algunos de\n"+
             "ellos vuelan y golpean tu cara atontandote por un\n"+
             "momento. Hacia arriba se alcanza a ver un punto de\n"+
             "luz emitido por una antorcha. A tus costados algunas\n"+
             "ratas cuelgan de las paredes.\n");
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
             "rata#ratas", "Son varias ratas negras..\n",
             "bicho#bichos", "Son decenas de ellos, todos diferentes\n"+
                             "y de un aspecto muy asqueroso.\n",
             }));
    set_weather(0,0,0);
    set_smell("El lugar comienza a oler un poco mal..\n");
    set_listen("Escuchas el soplar del viento....\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/d_center", "down",
                 "/d/sorcery/w/dhagor/rooms/stair_4", "up", }));
}
 

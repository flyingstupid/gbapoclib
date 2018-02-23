#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Ala sur de los calabozos");
    set_long("Aqui es el ala sur de los calabozos, no hay mas camino\n"+
             "que recorrer hacia el sur. El lugar es tetrico y sin\n"+
             "se~al de vida, mas que las ratas que cruzan junto a tus\n"+
             "pies chillando. No hay ninguna entrada de aire por lo\n"+
             "cual la niebla ha comenzado a ahogarte.\n");
    set_items(({
             "vapor#vapores", "Son unos ligeros vapores que brotan del piso.\n",
             "ceniza#cenizas", "Estas cenizas fueron dejadas aqui por algo\n"+
                               "que ardio en llamas.\n",
             "piso", "El piso esta cubierto de ceniza que al conjuntarse\n"+
                     "con los vapores que de el emergen han formado una\n"+
                     "niebla aun mas densa.\n",
             "niebla", "Es una densa niebla formada por el vapor\n"+
                       "y las cenizas proveniente del piso.\n",
             }));
    set_weather(0,0,0);
    set_smell("El lugar huele a emanaciones de algun tipo...\n");
    set_listen("Escuchas el crujir de la ceniza al tocar el vapor...\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/d4_6", "north", }));
}
 
 
 

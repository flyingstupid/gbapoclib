#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Celda oeste del ala sur");
    set_long("Esta es la celda oste del ala sur de los calabozos. Como\n"+
             "puedes ver ahora esta abandonada y sin vida, solo quedan\n"+
             "cenizas de lo que antiguamente las habito. El vapor del\n"+
             "piso te impide respirar bien, sera mejor que salgas de\n"+
             "este lugar cuanto antes.\n");
    set_items(({
             "vapor#vapores", "Son unos ligeros vapores que brotan del piso.\n",
             "ceniza#cenizas", "Estas cenizas fueron dejadas aqui por algo\n"+
                               "que ardio en llamas.\n",
             "piso", "El piso esta cubierto de ceniza que al conjuntarse\n"+
                     "con los vapores que de el emergen han formado una\n"+
                     "niebla aun mas densa.\n",
             }));
    set_weather(0,0,0);
    set_smell("El lugar huele a emanaciones de algun tipo...\n");
    set_listen("Escuchas el crujir de la ceniza al tocar el vapor...\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/d4_6", "east", }));
}
 
 

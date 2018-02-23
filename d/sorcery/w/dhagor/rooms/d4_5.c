#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Pasillo Sur");
    set_long("Caminas por el pasillo sur, el cual muestra a tus ojos\n"+
             "los arrores que aqui se han vivido. En el piso decenas\n"+
             "de cuerpos calcinados yacen sin vida. Las paredes estan\n"+
             "llenas de sangre al igual que el techo. Unas celdas se\n"+
             "miran hacia el sur. Las ratas husmean por todo el lugar.\n"+
             "Del piso unas ligeras emanaciones crean algo de niebla.\n");
    set_items(({
             "pared#paredes", "Las paredes estan hechas de uno poderosos\n"+
                              "ladrillos de piedra gris traida de alguna\n"+
                              "importante mina. Su antiguedad parece ser\n"+
                              "de muchos siglos atras. Se encuentran llenas\n"+
                              "de sangre y de cenizas.\n",
             "vapor#vapores", "Son unos ligeros vapores que brotan del piso.\n",
             "piso", "El piso esta cubierto de cuerpos sin vida. De el\n"+
                     "emergen unas ligeras emanaciones que forman niebla.\n",
             "rata#ratas", "Son algunas ratas negras.\n",
             "cuerpo#cuerpos", "Son decenas de cuerpos de diferentes\n"+
                               "razas, todos sin vida y calcinados.\n",
             "techo", "El techo esta lleno de sangre y cubierto\n"+
                      "de una grande capa de moho y ceniza.\n",
             }));
    set_weather(0,0,0);
    set_smell("El lugar huele a emanaciones de algun tipo...\n");
    set_listen("Puedes escuchar a las ratas saltar sobre el agua..\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/d_center", "north",
                 "/d/sorcery/w/dhagor/rooms/d4_6",     "south", }));
}
 

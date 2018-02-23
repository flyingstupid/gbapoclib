#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Celda este del ala sur");
    set_long("Este lugar parece haber sido una celda antiguamente, pues\n"+
             "en las paredes aun quedan las marcas de lo que fueron las\n"+
             "cadenas que sujetaron a alguna creatura. En el piso obervas\n"+
             "cuerpos y ceniza, aun aqui el vapor sigue saliendo ligeramente.\n"+
             "Las puertas de la celda fueron arrancadas de par.\n");
    set_items(({
             "vapor#vapores", "Son unos ligeros vapores que brotan del piso.\n",
             "ceniza#cenizas", "Estas cenizas fueron dejadas aqui por algo\n"+
                               "que ardio en llamas.\n",
             "piso", "El piso esta cubierto de ceniza que al conjuntarse\n"+
                     "con los vapores que de el emergen han formado una\n"+
                     "niebla aun mas densa.\n",
             "cuerpo#cuerpos", "Son varios cuerpos tirados aqui y alla dentro\n"+
                               "de las celdas que se encuentran a tus costados.\n",
             "paredes#pared", "Son unas gruesas paredes contruidas hace\n"+
                              "mucho tiempo y llenas de ceniza y sangre\n"+
                              "de quien parece haberlas habitado tiempo\n"+
                              "atras. En la superficie quedan las marcas\n"+
                              "de lo que fueron cadenas empotradas en las\n"+
                              "misma.\n",
             }));
    set_weather(0,0,0);
    set_smell("El lugar huele a emanaciones de algun tipo...\n");
    set_listen("Escuchas el crujir de la ceniza al tocar el vapor...\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/d4_6", "west", }));
}
 
 

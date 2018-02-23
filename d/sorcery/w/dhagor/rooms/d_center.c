#include <mudlib.h>
inherit ROOM;
object guard;
int i;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Entrada a los calabozos de las torres");
    set_long("Estas parado en el centro de los calabozos de las torres.\n"+
             "Varios pasillos se desprenden hacia los cuatro puntos\n"+
             "cardinales. El agua gotea del techo y unos ligeros vapores\n"+
             "han comenzado a brotar del piso. Unas viejas celdas ser ven\n"+
             "hacia el sur y el norte. Hacia el oeste el pasillo mas grande\n"+
             "muestra sus obscuras fauces. Observas una grande escalera que\n"+
             "sube hacia las torres de magia.\n");
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
             "vapor#vapores", "Son unos ligeros vapores que brotan del piso.\n",
             }));
    set_weather(0,0,0);
    set_smell("El lugar huele a emanaciones de algun tipo...\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/d5_4",    "east",
                 "/d/sorcery/w/dhagor/rooms/stair_5", "up",
                 "/d/sorcrey/w/dhagor/rooms/d3_4",    "west",
                 "/d/sorcery/w/dhagor/rooms/d4_3",    "north",
                 "/d/sorcery/w/dhagor/rooms/d4_5",    "south", }));
   for(i=0;i<3;i++){
    guard=clone_object("/d/sorcery/w/dhagor/monst/b_rat");
    transfer(guard,this_object());
   }
}
 

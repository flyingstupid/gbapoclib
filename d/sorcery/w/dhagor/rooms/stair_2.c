#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Escaleras hacia los calabozos");
    set_long("Conforme desciendes por las escaleras, el aire\n"+
             "comienza a ser mas denso, impidiendote respirar\n"+
             "como debieras. Las paredes han comenzado a ser\n"+
             "mas obscuras y sobre su superficie algunos muy\n"+
             "peque~os chorros de agua brotan de sus grietas.\n"+
             "La luz de una antorcha ilumina tu camino, pero\n"+
             "mas abajo parece no bastar, pues la obscuridad\n"+
             "ha comenzado a apoderarse de la luz que esta\n"+
             "emite.\n");
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
             "antorcha", "Es una antorcha muy grande que ilumina el lugar.\n",
             }));
    set_weather(2,0,0);
    set_smell("El lugar comienza a oler un poco mal..\n");
    set_listen("Escuchas el soplar del viento....\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/stair_3", "down",
                 "/d/sorcery/w/dhagor/rooms/stair_1", "up", }));
}


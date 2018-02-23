#include <mudlib.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Escaleras hacia los calabozos");
    set_long("Te encuentras en los primeros escalones de una\n"+
             "profunda escalera que te podria llevar hacia los\n"+
             "calabozos de las torres. Las paredes estan llenas\n"+
             "de suciedad y muestran una gran placa de moho sobre\n"+
             "sobre su superficie. El ambiente comienza a ser un\n"+
             "poco frio y un viento maloliente sopla tu cara muy\n"+
             "fuertemente, proveniente de abajo. Hay una enorme\n"+
             "antorcha que ilumina tu camino.\n");
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
    set_exits(({ "/d/sorcery/w/dhagor/rooms/stair_2", "down", }));
}


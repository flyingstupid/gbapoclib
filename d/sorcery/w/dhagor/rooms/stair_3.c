#include <mudlib.h>
#include <ansi.h>
inherit ROOM;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Escaleras hacia los calabozos");
    set_long("Te encuentras en un descanso de las escaleras.\n"+
             "Este lugar todavia se encuentr iluminado por la\n"+
             "luz de una antorcha empotrada en la pared, pero\n"+
             "mas abajo parece no haber mas antorchas. En una\n"+
             "de las paredes hay una placa de bronce. Desde el\n"+
             "infinito techo unas grandes gotas de agua golpean\n"+
             "tu cabeza. El ambiente parece estar viciado, pues\n"+
             "el aire es aun mas denso que mas arriba.\n");
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
             "placa", "Es una placa de bronce muy antigua. Parece\n"+
                      "contener una especie de advertencia, deberias\n"+
                      "leerla.\n",
             }));
    set_weather(2,0,0);
    set_smell("El lugar comienza a oler un poco mal..\n");
    set_listen("Escuchas el soplar del viento....\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/stair_4", "down",
                 "/d/sorcery/w/dhagor/rooms/stair_2", "up", }));
}
 
 
 
 
void init(){
    ::init();
    add_action("read","read");
}
 
 
read(str){
    if(str == "placa"){
          write(RED_F+BLINK+"\t     -=-=[ PELIGRO ]=-=-\n"+OFF);
          write("Ten cuidado si deseas descender hacia los peligrosos\n"+
                "calabozos bajo las torres, pues un maligno poder se\n"+
                "ha apoderado de ese maldito lugar. Pocos de los que\n"+
                "se han atrevido a atravesar esta linea han podido\n"+
                "volver sanos a este lugar. Aun los mas grandes magos\n"+
                "han sucumbido a la maldad que habita este lugar.\n\n");
          write(BLUE_F+BOLD+"    Anari El Gran Mago Azul.\n"+OFF);
     }
}

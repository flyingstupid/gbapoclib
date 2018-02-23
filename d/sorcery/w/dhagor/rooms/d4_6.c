#include <mudlib.h>
inherit ROOM;
object zombies;
 
 
void reset(status arg){
    if(arg) return;
    set_short("Pasillo Sur");
    set_long("Te encuentras parado entre lo que parecen ser dos celdas\n"+
             "de los calabozos. Todo el lugar se encuentra lleno de\n"+
             "una enorme cantidad de cenizas que junto con los vapores\n"+
             "que emergen del piso hacen del lugar algo tetrico. Dentro\n"+
             "de las celdas parece haber algunos cuerpos calcinados.\n"+
             "Hacia el sur observas una de las alas de los calabozos.\n");
    set_items(({
             "vapor#vapores", "Son unos ligeros vapores que brotan del piso.\n",
             "ceniza#cenizas", "Estas cenizas fueron dejadas aqui por algo\n"+
                               "que ardio en llamas.\n",
             "piso", "El piso esta cubierto de ceniza que al conjuntarse\n"+
                     "con los vapores que de el emergen han formado una\n"+
                     "niebla aun mas densa.\n",
             "cuerpo#cuerpos", "Son varios cuerpos tirados aqui y alla dentro\n"+
                               "de las celdas que se encuentran a tus costados.\n",
             }));
    set_weather(0,0,0);
    set_smell("El lugar huele a emanaciones de algun tipo...\n");
    set_listen("Escuchas el crujir de la ceniza al tocar el vapor...\n");
    set_exits(({ "/d/sorcery/w/dhagor/rooms/d4_5", "north",
                 "/d/sorcery/w/dhagor/rooms/d4_7", "south",
                 "/d/sorcery/w/dhagor/rooms/d5_6", "east",
                 "/d/sorcery/w/dhagor/rooms/d3_6", "west", }));
}
 
 
 
 
void init(){
    ::init();
    add_action("east","east");
    add_action("east","e");
}
 
 
 
 
east(){
    int i;
    if(!zombies || !find_living("zombie")){
        for(i=0;i<2;i++){
        zombies=clone_object("/d/sorcery/w/dhagor/monst/zombie");
        move_object(zombies,"/d/sorcery/w/dhagor/rooms/d5_6");
       }
    }
    this_player()->move_player("dentro de la celda#/d/sorcery/w/dhagor/rooms/d5_6");
    tell_room("/d/sorcery/w/dhagor/rooms/d5_6", "Unos cuerpos han cobrado vida!\n");
    return 1;
}

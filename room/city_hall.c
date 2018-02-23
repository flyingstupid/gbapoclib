
//
// room/city_hall.c
//
//city hall base object
//
#include <mudlib.h>

inherit ROOM;



void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("City Hall of Second Chance");
    set_long(
             " City Hall of Second Chance \n"+
             "This is the city hall of the little town of Second Chance. \n"+
             "Here life started again and people finally pulled themselves \n"+
             "collectively together. Begin living a new life of prosperity.\n"+
             "Its a large wooden building with lots of hand made wooden pews\n"+
             "that give it an old timy look different than most of the wastelands.\n"+
             "Here is where you can get started as a citizen.\n");
    set_exits(({"d/wastelands/w/critical/secondtry/city2","out"}));
    set_items(({
        "pews",
        "Hand crafted and beautifully done, it shows what folks can really\n"+
        "do when they put their minds to it2.\n",
        
    }));
}





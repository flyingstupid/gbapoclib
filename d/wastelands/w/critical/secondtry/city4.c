#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("Second Chance's East Path");
    set_long(
      "Second Chance's East Path\n"+
      "Away from the crossroads of the city is the local inn. Its a bit of\n"+
      "a joke around town to call it an inn. A communal eating house is more\n"+
      "like it. If you want hot food this is the place however. Its constructed\n"+
      "entirely out of wood and has a bit of an old wood log cabin feel but its.\n"+
      "big enough for the whole town to gather in so no one says to much about it.\n"+
      "Farther to the east is the workshops. Back west is the center of town.\n"
      );   
    set_exits(({
    "d/wastelands/w/critical/secondtry/city5","inn",
    "d/wastelands/w/critical/secondtry/city2","west",
    "d/wastelands/w/critical/secondtry/city6","east",
    }));

}

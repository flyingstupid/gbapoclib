
#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("the docks of Ille Coronos");
    set_long(
"A beginning of a stone road branches off to the northwest while the docks \n"+
"run to the south. Old wooden planks form the walkway, and many boats line \n"+
"the edge as if waiting for their next load of cargo and their next long \n"+
"journey at sea.\n");

    set_day_desc(
      " The docks are very busy during the day hours.\n");
    set_night_desc(
      " The docks are quiet during the off hours.\n");
    set_items(({ 
        "road#stone#stones#walk#walkway#street",
"Running to the northwest is Pyrosh Avenue, while the docks run \n"+
"back to the southwest.\n",
  "seas",
  "The seas are very rough.\n",
      }));
    set_day_items(({
"docks#dock",
"Many people crowd the wooden docks of Ille Coronos.\n", 
      }));  
    set_night_items(({
"During the off hours of the night the docks remain quiet.\n",
      }));
    set_smell(
      "Salty sea air seems to fill your nostrils.\n");
    set_listen(
      "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you upon the docks of Ille Coronos.\n");
    set_weather(2, 4, 0);
    set_exits(({
        "/d/coronos/w/alena/ille/c_11","northwest",
"/d/coronos/w/chi/city/streets/dock5","southeast",
      }));
}

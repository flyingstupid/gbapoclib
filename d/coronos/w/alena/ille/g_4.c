#include <mudlib.h>
inherit ROOM;

#define APP 4

object *apprentice;

void reset (status arg){
     object ob;
     int i;
  
     if(!apprentice) apprentice = allocate(APP);
     for(i = 0; i < APP ; i++) {
       if(!apprentice[i]) {
          ob = clone_object("d/coronos/w/angel/city/monst/apprentice");
         apprentice[i] = ob;
         move_object(apprentice[i], this_object());
       }
     }

    if (arg) return;

    set_short("the commercial sector of Ille Coronos");
    set_long(
      "Gshone continues to the east, as well as turning to the south. A \n"+
      "tall oak stands directly to the south of here, its branches long \n"+
      "and sturdy. The grey stones pave the road, placed carefully and \n"+
      "seem to be maintained a bit more then the stretch of road further \n"+
      "south. A line of bushes stand to the west.");
    set_day_desc(
      " A tall lamp stands unlit.\n");
    set_night_desc(
      " The oil lamp is lit and \n"+
      "the small flame illuminates the street.\n");
    set_items(({
	"road#stone#stones#walk#walkway#street",
	"The road is paved with smooth grey stones, placed more evenly \n"+
	"here then to the south.\n",
	"grass",
	"Pushing its way up through the stones the blades seemingly \n"+
	"reach for the sky.\n",
	"bush#bushes#line of bushes",
	"Standing about two to three feet high they form a wall to the \n"+
	"west and north.\n",
      }));
    set_day_items(({
	"lamp#light#oil lamp post#lamp",
	"The oil lamp stands about seven feet tall and the wick is \n"+
	"encased by glass and steel, unlit for now.\n",
      }));  
    set_night_items(({
	"lamp#light#oil lamp post#lamp",
	"The oil lamp stands about seven feet tall and the wick is \n"+
	"lit, illuminating the street below. It has been encased by \n"+
	"glass and steel, protecting the flame from wind and rain.\n",
      }));
    set_smell(
      "You smell only a very light salty scent on the air to the southeast.\n");
    set_listen(
      "Boots upon stone, voices, and other bustling sounds fill the air \n"+
      "about you in thie busy section of the city of Ille Coronos.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/alena/ille/g_3","south",
	"/d/coronos/w/alena/ille/g_5","east",
      }));
}

/* High Clerists Tower - entrance.c
 * Angel October 1993
 */

#include <mudlib.h>
inherit ROOM;

object ob;
void reset(status arg) {

  if(!ob) {
    ob = clone_object("d/coronos/w/angel/city/monst/bailston");
    move_object(ob, this_object());
  }

  load_door(({
  "file", "d/coronos/w/angel/city/temple/hall2",
  "direction", "south door",
  "lock description",
               "The lock appears to be made of marble, similar to \n"+
               "that of the marble in the room around you. Around \n"+
               "the edges of the lock are small golden leaves with\n"+
               "dragons curled about them.\n",
   "open", 1,
  "key id",
               "city key",
  "long",
               "A huge set of double doors stands before you.\n",
  }));
  reset_doors(arg);


  if(arg) return;
  set_short("the steps to the high clerists tower");
  set_long(
     "Rising high before you is the grand beauty of the High   \n"+
     "Temple to the All-God. Steps of blue-white marble rise   \n"+
     "sharply towards a set of huge double doors that stand    \n"+
     "open, the way lined by sentinels - marble columns tall   \n"+
     "and straight, watching all who pass through this place.  \n");

  set_night_desc(
     "Torches hang from each column, forcing the darkness away \n"+
     "from this holiest of places.\n");


  set_items(({
     "temple#high temple",
     "The grand High Temple to the All-God, father of the Panthenon \n"+
     "of gods. Of all places within the city of Tempus, this is the "+
     "holies of all places",

     "stairs#stair case#stair", "They leads upwards to the double doors",

     "doors#double doors#door", "Huge doors at the top of the stairs. "+
     "They are currently open",
  }));

  set_night_items(({
     "torch#torches#fire", "The fire from the torches flicker, sheding light "+
     "onto the stairs",

     "column#columns#sentinels",
     "Tall marble columns leads the way up the stairs to the doors.\n"+
     "Hung from each column is a torch that lights the way the stairs"
  }));
  set_day_items(({
     "column#columns#sentinels",
     "Tall marble columns leads the way up the stairs to the doors"
  }));

  set_weather(2, 4, 0);

  set_exits(({
	"d/coronos/w/alena/ille/temp1", "north",
  }));
}


     

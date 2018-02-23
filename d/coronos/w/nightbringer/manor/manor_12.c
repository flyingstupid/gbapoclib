/* MANOR_12.C
   AUTHOR:NIGHTBRINGER
   04-25-97 */

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
reset_doors(arg);

  load_door(({
    "destination", "d/coronos/w/nightbringer/manor/manor_13.c",
    "direction", "west door",
    "description", "A plain wooden door .\n",
    "closed",
    "door number", 1,
  }));

  if(!present("pierre")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/pierre.c"),this_object());
                        }
  if(!present("george")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/mon/george.c"),this_object());
                        }
if(arg) return;

  set_short("Hallway");
  set_long(
"The kitchen of Penor Manor is immaculate. It has every modern convienece\n"+
"imaginable. A massive wood stove is on the east wall, and a new Gnomish\n"+
"invention, called the ice box, is beside it. Cabinets, made of oak wood\n"+
"cover nearly every inch of available wall space. Every kind of kitchen\n"
"utensil imaginable hang from hooks in the ceiling, along with an enormous\n"+
"collection of pots and pans.\n");

  set_items(({
"wall#walls",
"They are made out of a shiny, glassy tile.\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"floor",
"It is made out of a shiny, glassy tile.\n",

"stove#wood stove#massive wood stove",
"It is black and made from cast iron. The cooking surface is very roomy.\n",

"ice box",
"A new invention from the Gnomes. This icebox is said to keep food cold\n"+
"and fresh for several days, and even has an area that lets you freeze\n"+
"food items. Unfortunately, as is with most Gnomish inventions, it does\n"+
"not work quite right. The part that is supposed to freeze doesn't\n"+
"and the part that's not supposed to does. But at least\n"+
"it works.\n",
"cabinet#cabinets",
"Tweenty oak cupboards encircle the room. They have shiny gold handles on\n"+
"them.\n",

"utensil#utensils#kitchen utensil#kitchen utensils",
"A wide variety of spoons, spatulas, forks, and other utensils hang from\n"+
"hooks in the ceiling.\n",

"pot#pots#pan#pans",
"Several different types of cookware hang from hooks in the ceiling\n",

           }));


set_weather(2,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_8.c",  "south",
  }));

}


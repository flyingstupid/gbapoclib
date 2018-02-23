#include <mudlib.h>
inherit ROOM;

void reset(status arg){

    reset_doors(0);
    ::reset(arg);
	
    if(arg) return;
    load_door(({
       "destination", "d/ooc/w/jheleg/bhouse/sand2",
       "direction",   "screen door",
       "closed",
       "description",
          "A silver mesh screen door.\n",
    }));

    set_long(
      "The porch has been screened in to keep the pesky bugs outside and allows a \n"+
      "calm breeze to carry in the salty air. A rug lays upon the hardwood floor and \n"+
      "a screen door stands at the top of the staircase that leads down to the beach. \n"+
      "An open entryway leads back into the main beach house.\n");


    set_short("the main porch");
    set_weather(2,2,0);

    set_night_desc(
      "Other beach houses can be seen lit up across the beach.\n");
    set_items(({
"door#screen door",
"Framed in metal the door is screened in to keep out bugs.\n",
	"stairs#staircase",
	"A set of wooden steps leading down to the sand below.\n",
	"screen#windows#window",
	"It is made up of tiny little holes made of wire.",       
	"rug#large rug",
	"It's main purpose is to cover up the hardwood floor and to "+BS(n)+
	"protect it from scuff marks from shoes and boots. It also "+BS(n)+
	"dampens the sounds of feet upon wood, making it a bit quieter "+BS(n)+
	"then it could be. It's dark blue in color and full of sand.",
	"floor#hardwood floor",
	"A standard hardwood floor that shows years of use.",
      }));

    set_exits(({      
	"/d/ooc/rooms/ooc2","inside",

      }));

    set_smell("The strong scent of salt strikes your nose.\n");
    set_listen("You hear the voices of people chatting from all around. As \n"+
      "well as the roar of the surf outside.\n");

    set_ooc_room(1);
}
/* Lena, December 11, 1996 */


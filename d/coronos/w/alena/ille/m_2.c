#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  object ob;

  if(!present("gadil")) {
    ob = clone_object("d/coronos/w/angel/city/monst/gadil");
    move_object(ob, this_object());
  }

    if (arg) return;

    set_short("Main Street");
    set_long(
      "Smooth cobblestones line the street that runs west and east. A busy \n"+
      "interesection lies to the west where tall trees block a clear view \n"+
      "of what stands to the southeast. Bushes line the street on both sides \n"+
      "and seem to be healthy and strong.");
    set_day_desc(
      "\n");
  set_night_desc(
      " The pair of lamps lining the street\n"+
      "burn brightly.\n");
    set_items(({
	"road#street",
	"This is Main Street.  It is paved with grey bricks.\n",
	"bricks#brick#grey bricks",
	"These are smooth grey bricks that pave the road.\n",
	"bush#bushes",
	"These bushes seem to be in good health.\n",
	"grass",
	"The grass is green and healthy.\n",
	"leaves",
	"The leaves of the trees and bushes are very pretty.\n",
      }));
    set_day_items(({
	"lamp post#lamp posts",
	"This pair of lamp posts are made from iron, and are engraved with\n"+
	"intricate designs.  They have cylindrical tops that house the oil\n"+
	"and wick.  They are currently unlit.\n", 
      }));  
    set_night_items(({
	"lamp post#lamp posts",
	"This pair of lamp posts are made from iron, and are engraved with\n"+
	"intricate designs.  They have cylindrical tops that house the oil\n"+
	"and wick.  They burn brightly, illuminating the road.\n",
      }));
    set_smell(
      "You smell nothing but fresh air.\n");
    set_listen(
      "You hear the rustling leaves as a breeze blows by.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/alena/ille/m_3","west",
	"/d/coronos/w/alena/ille/m_1","east",
      }));
}

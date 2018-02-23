#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  object ob;

  if(!present("citizen")) {
    ob = clone_object("d/coronos/w/angel/city/monst/citizen");
    move_object(ob, this_object());
  }

    if (arg) return;

    set_short("East Road");
    set_long(
      "East Road continues to carry travelers north and south. The\n"+
      "commercial district of Ille Coronos lies to the southeast. A busy \n"+
      "intersection of roads is just to the north and a fountain stands \n"+
      "to the southwest.\n");
    set_day_desc(
      "An unlit oil lamp hangs from its lamp post here.\n");
    set_night_desc(
      "A lit oil lamp burns brightly to light the way.\n");
    set_items(({
	"fountain",
	"The fountain is to the southwest.\n",
	"lamp post#post",
	"This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
	"cobblestones#cobblestone",
	"These grey cobblestones have been smoothed and worn over time.\n",
	"road",
	"This road is made from grey cobblestones.\n",      
	"district#commercial district",
	"The commercial district is far to the south.\n",
	"southern end#end",
	"The end of East Road is far to the south.\n",
      }));
    set_day_items(({
	"lamp#oil lamp",
	"This is a simple oil lamp that hangs from a post.  It is has a metal\n"+
	"frame and glass panels.  The lamp is unlit right now.\n",
      }));
    set_night_items(({
	"lamp#oil lamp",
	"This is a simple oil lamp that hangs from a post.  It has a metal\n"+
	"frame and glass panels.  The lamp shines brightly, illuminating the\n"+
	"area.\n",
      }));
    set_smell(
      "You smell nothing but fresh air.\n");
    set_listen(
      "You faintly hear the trickle of a water from a fountain.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/eastrd3", "north",
	"/d/coronos/w/darkness/eastrd5", "south",
      }));
}

#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  object ob;

  if(!present("citizen")) {
    ob = clone_object("d/coronos/w/angel/city/monst/citizen");
    move_object(ob, this_object());
  }

    if (arg) return;

    set_short("Main Street");
    set_long(
      "This wide, cobblestone road stretches from east to west.  Some bushes\n"+
      "grow in a patch to the north, next to a small gazebo.  The gazebo looks\n"+
      "like a comfortable place to relax");
    set_day_desc(
      " and get out of the hot sun.  Right\n"+
      "outside the gazebo, next to the road is a lamp post with an oil lamp\n"+
      "hanging from it.\n");
    set_night_desc(
      " and enjoy the fresh night air.  A\n"+
      "lit oil lamp stands right outside the gazebo, illuminating the road.\n");
    set_items(({
	"gazebo",
	"This is a small gazebo with vines growing on it.\n",
	"vines",
	"These green vines grow on the outside of the gazebo.\n",
	"lamp post#post",
	"This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
	"cobblestones#cobblestone",
	"These grey cobblestones have been smoothed and worn over time.\n",
	"road",
	"This is Main Street.\n",      
	"bush#bushes",
	"These are short bushes that have pointy leaves.  They grow in a\n"+
	"group, next to the gazebo.\n",
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
      "You faintly hear the trickle of a fountain.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/gazebo1", "north",
	"/d/coronos/w/darkness/mainst4", "east",
	"/d/coronos/w/darkness/mainst2", "west",
      }));
}

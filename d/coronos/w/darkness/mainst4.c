#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("Main Street");
    set_long(
      "This wide, cobblestone road stretches to the east, towards the\n"+
      "commercial district of the city.  To the north lies a fountain\n"+
      "square, and to the northwest is a vine covered gazebo.");
    set_day_desc(
      "  A lone\n"+
      "lamp post stands here, with its lamp swaying in the wind.\n");
    set_night_desc(
      "  A lit\n"+
      "oil lamp burns brightly, illuminating the quiet street.\n");
    set_items(({
	"lamp post#post",
	"This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
	"cobblestones#cobblestone",
	"These grey cobblestones have been smoothed and worn over time.\n",
	"road",
	"The road is paved with grey cobblestones.\n",      
	"street#streets",
	"Main Street leads to the west, and East Rd runs north.\n",
	"fountain#water#square#fountain square",
	"The fountain is to the north.\n",
	"district#commercial",
	"The commercial district is far to the east.\n",
	"city#buildings",
	"All around you stands the city of Ille Coronos.  Buildings of all\n"+
	"shapes and sizes stand before you.\n",
	"gazebo",
	"The gazebo is to the northwest.\n",
	"vines",
	"These green vines grow on the outside of the gazebo.\n",
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
      "You hear the trickling of water from the fountain.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/fountn", "north",
	"/d/coronos/w/darkness/mainst5", "east",
	"/d/coronos/w/darkness/mainst3", "west",
      }));
}

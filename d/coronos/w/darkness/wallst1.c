#include <mudlib.h>
inherit ROOM;

void reset (status arg){
  object ob;

  if(!present("citizen")) {
    ob = clone_object("d/coronos/w/angel/city/monst/citizen");
    move_object(ob, this_object());
  }

    if (arg) return;

    set_short("Wall Street");
    set_long(
      "Wall Street continues to both the west and east, cobblestone \n"+
      "lines the walkway that many have tred upon before at the northernmost\n"+
      "border of Ille Coronos. A large gate stands to the west and a \n"+
      "tall brick wall prevents a northern passage. Small shrubs grow \n"+
      "along the street, adding color to the otherwise drab surroundings.\n");
    set_day_desc(
      "An unlit oil lamp hangs on its post, standing near the wall.\n");
    set_night_desc(
      "A lit lamp shines brightly, illuminating the road.\n");
    set_items(({
	"post#lamp post",
	"This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
	"cobblestones#cobblestone",
	"These grey cobblestones have been smoothed and worn over time.\n",
  "road#walkway",
	"The road is paved with many cobblestones.\n",
	"wall#brick wall",
	"This is a long brick wall that runs along one side of the road.\n"+
	"It is made of red bricks.\n",
	"bricks#brick",
	"These bricks were made from red clay.\n",
	"vine#vines",
	"These green vines grow along the wall, clinging to the bricks.\n",
	"moss",
	"This green moss grows in patches on the wall.\n",
	"shrub#shrubs",
	"A few shrubs grow along the road, on the side opposite the wall.\n",
	"gate",
  "The gate is far to the west. It seems to lead south towards\n"+
	"the gardens.\n",
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
      "You hear the sound of a gentle breeze.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/wallst0", "west", 
	"/d/coronos/w/darkness/wallst2", "east",
      }));
}

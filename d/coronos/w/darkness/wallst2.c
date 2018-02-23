#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    set_short("Wall Street");
    set_long(
      "Cobblestones line the walkway under your feet and a long, \n"+
      "brick wall stretches along the northern side of the street. A \n"+
      "few shrubs add life to the southern edge of the road while \n"+
      "moss and vines line the strong and sturdy wall.");
    set_day_desc(
      "  An\n"+
      "unlit oil lamp hangs on its post, next to the wall.\n");
    set_night_desc(
      "  A lit\n"+
      "oil lamp burns brightly, illuminating the road.\n");
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
      "You hear the rustling leaves of the shrubs as a breeze blows by.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/wallst1", "west",
	"/d/coronos/w/darkness/wallst3", "east",
      }));
}

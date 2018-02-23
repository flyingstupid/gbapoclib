#include <mudlib.h>
#define MONST	"d/coronos/w/angel/city/monst"

inherit ROOM;

void reset (status arg){
    reset_doors(arg);
    load_door(({
	"file", "d/coronos/w/angel/city/univ/path1",
	"direction", "northeast gate",
	"long",
		"A grand set of iron gates, almost as wide as they \n"+
		"are tall, and bound in steel and gold. Two great    \n",
		"gargoyles stand over the tops of the gate watching  \n",
		"your every move.\n",
    }));

    if(!present("guard")) 
      move_object(clone_object(MONST+"/guard1"), this_object());

    if (arg) return;

    set_short("just before the arch");
    set_long(
      "The road leads toward a tall arch, that of the University of \n"+
      "Ille Coronos, where those come to train in the works of magics. \n");
    set_day_desc(
"A pair of tall lamp posts stand on either side of the gate.\n");
    set_night_desc(
      "A pair of lamp posts burn brightly.\n");
    set_items(({
	"road",
	"The road is paved with grey bricks.\n",
	"bricks#brick#grey bricks",
	"These are smooth grey bricks that pave the road.\n",
	"bush#bushes",
	"These bushes are well trimmed and in healthy condition.\n",
	"grass",
	"The grass is green and healthy.\n",
	"tree#trees",
	"These are young saplings that have recently been planted.\n",
	"bench#benches#wooden benches",
	"These wooden benches look brand new.  They are made from wood, and\n"+
	"held together with an iron frame.",
	"arch",
	"The arch of the University stands tall, above the trees.\n",
      }));
    set_day_items(({
	"lamp post#lamp posts#posts",
	"This pair of lamp posts are made from iron, and are engraved with\n"+
	"intricate designs.  They have cylindrical tops that house the oil\n"+
	"and wick.  They are currently unlit.\n", 
      }));  
    set_night_items(({
	"lamp post#lamp posts#posts",
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
	"/d/coronos/w/darkness/univst1", "southwest",
      }));
}
/* Alena 1-11-97 */

#include <mudlib.h>
#define MONST	"d/coronos/w/angel/city/monst"
inherit ROOM;
 
void reset (status arg){
  int i;
  if (arg) return;
 
  if(!present("igiloo"))
    move_object(clone_object(MONST+"/igiloo"), this_object());

  if(!present("pigeon")){
    for(i=0; i<6; i++)
      move_object(clone_object(
    	"/d/coronos/w/darkness/npc/bird1"),
    this_object());
  }


  set_short("East Road");
  set_long(
      "This cobblestone road runs north to south.  The tall trees in the\n"+
      "gardens can be seen to the west, and the arch of the University \n"+
      "rises to the northeast.  A birdfeeder hangs from one of the trees\n"+
      "that line the road.");
  set_day_desc(
      "  A lamp post also stands here, under the tall\n"+
      "branches of an oak tree.\n");
  set_night_desc(
      "  A lit oil lamp burns brightly, as it hangs\n"+
      "from its lamp post, under an old oak tree.\n");
  set_items(({
      "garden#gardens",
      "The garden is far to the west.\n",     
      "post#lamp post",
      "This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
      "cobblestones#cobblestone",
      "These grey cobblestones have been smoothed and worn over time.\n",
      "road",
      "This road is made from grey cobblestones.\n",
      "university",
      "The arch of the University can be seen above the other buildings.\n",      
      "arch",
      "The arch of the University towers over the other buildings.\n",
      "tree#trees",
      "Many different kinds of trees scatter themselves on either side\n"+
      "of the road.\n",
      "birdfeeder",
      "This is a wooden birdfeeder that hangs from an old tree.  It has\n"+
      "some seed in it for birds to eat.\n",
      "birdseed#seed",
      "This is a mixture of different seeds that birds like to eat.\n",
      "leaves#leaf",
      "The leaves on the trees are many different shades of green.\n",
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
      "You smell fresh birdseed.\n");
  set_listen(
      "You hear the rustle of leaves.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/eastrd1", "north",
      "/d/coronos/w/darkness/eastrd3", "south",
      }));
}

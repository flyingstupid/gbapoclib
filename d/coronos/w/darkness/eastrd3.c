#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  set_short("East Road");
  set_long(
      "This is the East Road which runs north to south.  The southern end\n"+
      "of University Drive is to the east, and a dirt path leads to the \n"+
      "west.  A signpost stands along the road, next to a lamp post.\n");
  set_night_desc(
      "A lit oil lamp burns brightly, illuminating the road.\n");
  set_items(({
      "lamp post",
      "This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
      "cobblestones#cobblestone",
      "These grey cobblestones have been smoothed and worn over time.\n",
      "road",
      "This road is made from grey cobblestones.\n",
      "university",
      "The arch of the University can be seen above the other buildings.\n",
      "signpost",
      "This is a wooden signpost.  A couple signs have been nailed to the\n"+
      "top of the post.\n",
      "sign#signs",
      "There are two signs nailed into the signpost.  The sign that\n"+
      "north and south reads, 'East Road'.  The sign pointing to the\n"+
      "east reads, 'University Drive'.\n",
      "post",
      "There are two posts here\n",
      "arch",
      "The arch of the University towers over the other buildings.\n",
      "dirt path#path",
      "The path seems to lead west, towards the city gardens.\n",
      "garden#gardens",
      "The gardens are far to the west.\n",
      "university drive",
      "The great University Drive is to the east.\n",
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
      "You hear the wind as a breeze blows by.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/eastrd2", "north",
      "/d/coronos/w/darkness/eastrd4", "south",
      "/d/coronos/w/darkness/univst5", "east",
      "/d/coronos/w/darkness/dpath1",  "west",
      }));
}

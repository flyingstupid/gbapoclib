#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  set_short("East Road");
  set_long(
      "This is the East Road which runs north to south.  University Drive\n"+
      "leads east toward the University.  A signpost stands along the road,\n"+
      "next to a lamp post.");
  set_day_desc(
      "\n");
  set_night_desc(
      "  A lit oil lamp burns brightly, illuminating\n"+
      "the road.\n");
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
      "There are two posts here.\n",
      "arch",
      "The arch of the University towers over the other buildings.\n",
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
      "/d/coronos/w/darkness/wallst5", "north",
      "/d/coronos/w/darkness/eastrd2", "south",
      "/d/coronos/w/darkness/univst1", "east",
      }));
}

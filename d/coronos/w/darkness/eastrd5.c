#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  set_short("East Road");
  set_long(
      "This is the East Road which continues north towards the back wall\n"+
      "of the city.  To the west is a sitting area and a small fountain\n"+
      "flowing with water.");
  set_day_desc(
      "  An unlit oil lamp hangs from its lamp post\n"+
      "here.\n");
  set_night_desc(
      "  A lit oil lamp burns brightly, as it hangs\n"+
      "on its lamp post.\n");
  set_items(({
      "city",
      "You are in the city of Ille Coronos.  You are surrounded by\n"+
      "building of all shapes and sizes.  The road looks old and worn.\n"+
      "To the west is a sitting area.\n",
      "area#sitting area",
      "The sitting area is to the west.\n",
      "fountain",
      "The fountain is to the west.\n",
      "lamp post#post",
      "This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
      "cobblestones#cobblestone",
      "These grey cobblestones have been smoothed and worn over time.\n",
      "road",
      "This road is made from grey cobblestones.\n",      
      "wall",
      "The wall is far to the north.\n",
      "water",
      "The water is coming out of the fountain.\n",
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
      "You faintly hear the trickling of water from the fountain to the west.\n");  
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/eastrd4", "north",
      "/d/coronos/w/darkness/mainst5", "south",
      "/d/coronos/w/darkness/fountn", "west",
      }));
}

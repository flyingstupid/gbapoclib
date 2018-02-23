#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  set_short("Wall Street");
  set_long(
      "This cobblestone road continues from east to west.  A long, brick\n"+
      "wall stretches along next to the road.  Vines and moss grow on the\n"+
      "wall, while shrubs and flowers line the opposite side of the road.\n");
  set_day_desc(
      "An unlit oil lamp hangs on its post, next to the wall.\n");
  set_night_desc(
      "A lit oil lamp burns brightly, illuminating the road.\n");
  set_items(({
      "post#lamp post",
      "This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
      "cobblestones#cobblestone",
      "These grey cobblestones have been smoothed and worn over time.\n",
      "road",
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
      "flowers#flower",
      "Varous flowers line the sides of the road.  They are all very\n"+
      "colorful and aromatic.\n",
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
      "You smell the sweet scent of the flowers.\n");
  set_listen(
      "You hear the rustling leaves of the shrubs as a breeze blows by.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/wallst3", "west",
      "/d/coronos/w/darkness/wallst5", "east",
      }));
}

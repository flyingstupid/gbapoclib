#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){
  if (arg) return;
 
  if(!present("Gary")){
    move_object(clone_object(
    "/d/coronos/w/darkness/npc/gary"),
    this_object());
  }

  set_short("Wall Street");
  set_long(
      "This is the corner of Wall Street and East Road.  A brick wall \n"+
      "stands to the north, and continues west, following the street. \n"+
      "Far to the east stands the great arch of the University.  East \n"+
      "Road goes south towards the commercial area.  Standing along \n"+
      "the road is a signpost, and next to it is a lamp post.\n");
  set_night_desc(
      "The lit oil lamp burns brightly, illuminating the road.\n");
  set_items(({
      "leaves",
      "These are dried leaves that have fallen off some trees.\n",
      "lamp post",
      "This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
      "cobblestones#cobblestone",
      "These grey cobblestones have been smoothed and worn over time.\n",
      "road",
      "This is the corner of Wall Street and East Road.  They are paved\n"+
      "with many cobblestones.\n",
      "wall#brick wall",
      "This is a long brick wall that runs along one side of the road.\n"+
      "It is made of red bricks.\n",
      "bricks#brick",
      "These bricks were made from red clay.\n",
      "arch",
      "The great arch of the University rises above the city to the east.\n",
      "street",
      "Wall Street leads to the west.\n",
      "signpost",
      "This is a wodden signpost stuck into the ground.  A couple of\n"+
      "signs have been nailed into the top of the signpost.\n",
      "signs#sign",
      "There are two signs on the signpost.  The sign pointing to the\n"+
      "west reads, 'Wall Street.'  The sign that points to the south \n"+
      "reads, 'East Road'.",
      "post",
      "There are two posts here.\n",
      "university",
      "The famous university of Ille Coronos rises high into the sky.\n",
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
      "You hear some leaves being blown across the cobblestones.\n");
  set_weather(2, 4, 0);
  set_exits(({
      "/d/coronos/w/darkness/wallst4", "west",
      "/d/coronos/w/darkness/eastrd1", "south",
      }));
}

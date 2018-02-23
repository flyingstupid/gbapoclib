/* house4.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if (!present("rat")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/npc/rat"),this_object()); 
  }

  if(!present("spider")) {
    int i;
    for(i=0; i<3; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/spider"),this_object());}
  }

  if (!present("trunk")) {
     move_object(clone_object(
     "/d/coronos/w/newstar/newbie/items/otrunk"),this_object()); 
  }

  reset_doors(arg);
  load_door(({
    "direction", "cellar door",
    "file", "d/coronos/w/newstar/newbie/rooms/house3",
    "long",
      "A small, cellar door in the ceiling.\n",
  }));

  if(arg) return;
 
  set_short("a cellar");
  set_long(
    "The cellar underneath the kitchen is small, dark and damp.  The only  \n"+
    "light that normally enters this cold room comes from cracks in the    \n"+
    "wood ceiling, which is the kitchen floor up above.  The cellar is full\n"+
    "of old crates and boxes.  Shelves are stacked with yellowed papers and\n"+
    "dusty old books.  All the dust, spiderwebs, and signs that rats have  \n"+
    "made their home here hint that this cellar isn't visited very often.  \n"+
    "The old staircase is the only way back out of here.\n");
  set_items(({
    "stairs",
      "The stairs are very old and creaky.  The have been warped due to the\n"+
      "dampness of the cellar.\n",
    "sign#signs",
      "Signs that rats live here can be seen here and there.  Chewed pieces\n"+
      "of paper, holes in boxes, and rat feces loiter the room.\n",
    "spiderwebs",
      "Spiderwebs mat the walls and cracks of the room.\n",
    "dust",
      "Dust cakes the moist room, creating a thin layer of mud on\n"+
      "much of the room's contents.\n",
    "book#books",
      "The books are moist and falling apart due to the damp environment.\n"+
      "most of them are probably illegable.\n",
    "paper#papers",
      "The papers are all illegable due to being exposed to the damp climate.\n",
    "shelf#shelves",
      "A few shelves hold old books and parchment papers.  Their contents\n"+
      "are all moist and rotting.\n",
    "crate#box#crates#boxes",
      "Various crates and boxes are stacked about the room.  Damp and moldy,\n"+
      "it's no wonder no one comes here to look through the crates and boxes.\n",
    "cracks",
      "Tiny cracks in the boards of the ceiling let in a few traces of light.\n",
    "light",
      "Faint traces of light creap through cracks in the ceiling.\n",
    "floorboards#board#boards",
      "The floorboards are old and made of oak.\n",
    "kitchen#up#ceiling",
      "The kitchen lies above this cellar.  The floor floor boards make up\n"+
      "the ceiling of this room.\n",
    "cellar#room",
      "The cellar is dark, damp and cold.  It doesn't look like people\n"+
      "come down here often.\n",
    }));
  set_smell(
    "This damp cellar smells of stale air.  Decaying wood and\n"+
    "other similar things mingle with the smell of the filthy\n"+
    "rats that live down here.\n");
  set_listen(
    "The sound of a rat scmpering across the floor is all\n"+
    "that you can hear.\n");
  set_weather(0, 1, 0); /* no light, no weather, no climate */
}

#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
  if (arg) return;


  if(!present("spider")) {
    int i;
    for(i=0; i<4; i++) {
      move_object(clone_object(
      "/d/coronos/w/darkness/npc/spider1"),this_object());}
  }

reset_doors(arg);
load_door(({
  
  "file", "d/coronos/w/darkness/mainst1",
  "direction", "north door",
  "long", "This is a wooden door made of oak.\n",
  "door id", "north door",
  "key id", "brass key",
  
  "lock id", "brass lock",
  "lock description", "An old brass lock\n",
  "lock difficulty", 16,
  "closed", 
  }));
 
 
  set_short("A shop for rent");
  set_long(
    "The room is dark and musty, with broken furniture strewn about. Dust\n"+
    "and spiderwebs cover most of the room.  Old shelves and display cases\n"+
    "stand against bare walls.  It's hard to tell what kind of shop this \n"+
    "place used to be.\n");
  set_items(({
    "door",
    "The door is made of oak.\n",
    "furniture#shelves#cases#display cases",
    "Lots of various pieces of broken furniture are scattered about the\n"+
    "room.  Most of everything in the room is covered with dust.\n",
    "walls#wall",
    "The walls are baren, with areas where the paint is peeling off.\n",
    "paint",
    "The paint is off white and it is beginning to yellow.  Paint chips\n"+
    "also mingle with the dust on the floor.\n",
    "dust",
    "It's just dust.  Nothing special.\n",
    "spiderwebs#spiderweb",
    "Spiderwebs are all over this room.  They hang from the ceiling,\n"+
    "cross between pieces of furniture, and fill the corners of the room.\n",
    }));
  set_smell(
      "It smells musty in here.\n");
  set_listen(
      "It's very quiet in here.\n");
  set_weather(0, 2, 0);
  set_exits(({
      "/d/coronos/w/darkness/mainst1", "north",      
      }));
}

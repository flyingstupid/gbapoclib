#include <mudlib.h>
#include "paths.h"

inherit ROOM;

#define RAVEN 4

object *ravens;


void reset(status arg) {
  int i;
  object raven;
  
  if(!arg) {
      set_short("the Elfin Forest");
      set_long(
     "You are standing in a clearing in the forest.  There are trees all \n"+
     "around you but there aren't any growing here.  This place seems to \n"+
     "have been cleared by the trampling of little feet.  You soon realize \n"+
     "that this is the party spot for the elves. The elves gather in this \n"+
     "clearing to sing and dance all night.\n");

      set_exits(({
	PATH+"new6", "southeast",
	PATH+"new3", "west",
       }));

       set_items(({
           "clearing",   "A circular patch of dirt in the forest",
           "trees",   "large oak trees",
       }));
       set_weather(1,4,3);
  }
  if(!ravens) ravens = allocate(RAVEN);
  for(i = 0; i < RAVEN; i++) {
    if(!ravens[i]) {
      raven = clone_object(MONSTER);
      raven->set_name("raven");
      raven->set_short("a raven");
      raven->set_long(
               "A black bird, with a short yellow beak.\n");
      raven->set_level(1);
      raven->set_ac(3);
      raven->set_wc(5);
      raven->set_plural("ravens");
      raven->set_race("bird");
      raven->set_al(25);
      raven->add_money(30);
      move_object(raven, this_object());
      ravens[i] = raven;
    }
  }
}

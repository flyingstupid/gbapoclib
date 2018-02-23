#include <mudlib.h>
#include "paths.h"
inherit ROOM;

int nothing;

void reset(status arg) {
   object mite;
   int i;
   
   nothing = 0;
   if(!arg) {
      set_short("a tree");
      set_long(
"You are in the attic of the tree. There is lots of old junk in this\n"+
"place.  You almost choke from the dust in the room.  It doesn't appear\n"+
"that anyone has been up here for years.  There's no telling what lives\n"+
"up here in this dusty old place, so watch your back.\n");
     set_exits(({
	PATH+"tree3", "down",
      }));
     set_items(({
       "junk",  "a pile of junk, a search my find something useful",
     }));
     set_weather(2,4,3);
   }

  if(!present("mite")) {
    for(i = 0; i< 3; i++) {
      mite = clone_object(MONSTER);
      mite->set_name("mite");
      mite->set_short("a dust mite");
      mite->set_plural("dust mites");
      mite->set_long(
               "A small little 6 legged bug, with small antennii.\n");
      mite->set_level(1);
      mite->set_ac(3);
      mite->set_wc(5);
      mite->add_money(10);
      mite->set_race("insect");
      mite->set_al(10);
      move_object(mite, this_object());
    }
  }
}

void init() {
  ::init();
   add_action("search", "search");
}

status search(string arg) {  
  int chance;
  object bts;
  string tmp1, tmp2;

  chance = random(20);
  if(sscanf((string)this_player()->query_race(), "%self%s",tmp1,tmp2))
    chance -= 3;

  if(arg != "junk") {
    notify_fail("Search what??\n");
    return 0;
  }
  if(chance > random((int)this_player()->query_intelligence())) {
    notify_fail("You find nothing of interest.\n");
    return 0;
  }
  if(nothing == 1) {
     write("You search though the junk, and find nothing.\n");
     say(this_player()->query_name()+" searches through the junk.\n");
     return 1;
   }
  if(arg == "junk" && nothing == 0) {
      nothing = 1;
      write("You search though the junk and find an old pair of boots.\n");
      say(this_player()->query_name()+" searches through the junk.\n");
      bts = clone_object(ARMOUR);
      bts -> set_type("boots");
      bts -> set_weight(5);
      bts -> set_ac(1);
      bts -> set_value(60);
      bts -> set_name("boots");
      bts -> set_short("An old pair of boots");
      bts -> set_long("They look like they have not been worn for \n"+
                      "a very long time, possibly decades. They have\n"+
                      "a small green leaf motive on the sides.\n");
      move_object(bts,this_object());
      return 1;
   }
}

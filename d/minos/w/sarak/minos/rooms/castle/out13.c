#include <mudlib.h>
#include "/d/minos/w/sarak/include/minos.h"
inherit ROOM;

int i;

void reset(status arg) {
  i = 0;
  if(!arg) {
    set_short("The Outer Hall of the Castle");
    set_long(
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
"You are walking along the hall which surrounds the castle. The whole room\n"+

"is glittering with gold. The chandeliers hanging from the ceiling provide\n"+
"the room with a gold glow. The tiles on the floor reflect the light from\n"+
"the chandeliers to highlight the portraits hanging from the wall.\n"+
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");  
    set_exits(({
      CASTLE_ROOMS+"out12",  "east",
      CASTLE_ROOMS+"entrance",  "west",
    }));
    set_weather(2,2,0);
    set_items (({
        "light#chandeliers#chandelier",
          "The chandeliers provide light for the room",
      "portraits#portrait#pictures#picture",
          "The pictures are of various members of minotaur\n"+
          "castle. They have all been framed in gold",
      "tiles#floor",  "The tiles on the floor have been made from rich white\n"+
                      "opals. One of them looks loose. Perhaps you can pry it out!",
    }));                
  }
}

void init() {
  ::init();
  add_action("pry",  "pry");
}

status pry(string gem) {
  if ((gem == "opal") || (gem == "tile")) {
    if (i > 0) {
      write("Someone has already taken that!\n");
      return 1;
    }   
    if (!present("knife", this_player()) && !present("dagger", this_player())){
      write ("You try to pry the opal tile from it's position but it is still\n"+
             "connected to the floor. Perhaps if you had a knife, it would be easier.\n");
      say (this_player()->query_name()+" attempts to take a tile from the ground.\n");
      return 1;
    }
    else {
      if (present("knife", this_player()))
        write ("Using your knife, ");
      else
        write ("Using your dagger, ");
      write ("you cut away at the opal tile on the floor. After\n"+
             "a few minutes it finally comes loose. You take the tile with you.\n");
      say (this_player()->query_name()+" cuts one of the tiles from the ground.\n");
      move_object(clone_object(CASTLE_ITEMS+"tile"), this_player());
      i++;
      return 1;
    }      
  }
  return 0;
}

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  reset_doors(arg);
  load_door(({
    "file", "d/coronos/w/darkness/b/hall3",  
    "secret door", 18,
    "long", "A small opening in the wall that leads to a narrow passageway.\n",
    "secret door finders", ({}),
    "direction", "secret door",
  }));

  if (arg) return;
 
  set_short("a secret room");
  set_long(
    "This small room us dark and damp.  A chair and table barely fit in the\n"+
    "confines of this small space.  Only a little light filters through the\n"+
    "tapestry covered passageway and a wide crack in the south wall.\n");
  set_items(({
    "chair",
      "The wooden chair is old and wobbly.\n",
    "table",
      "The small writing table barely fits in the room.  It is made from\n"+
      "wood, and it looks very old.\n",
    "ceiling#ceilings#up",
      "The granite ceiling is very low and roughly cut.\n",
    "floor#down#",
      "The floor is made of roughly cut granite.\n",
    "light",
      "The light filters through the tapestry and a crack in the south wall.\n",
     }));
  set_smell(
    "The room smells of stagnant water and mildew.\n");
  set_listen(
    "Muffled noises seem to be coming frmo the crack.  The noises are hard\n"+
    "to make out though.\n");
  set_weather(1, 1, 0);

}

void init() {
  ::init();
  add_action("crack1", "use");
  add_action("crack1", "look");
}

status crack1(string str) {
  string tmp1, tmp2;

  if(sscanf(str, "%shole%s", tmp1, tmp2)) { 
    write("Test look.\n");
    show_inventory("d/coronos/w/angel/city/chambers/chambers");
    say(this_player()->query_name()+" peers through the crack.\n",this_player());
    return 1;
  }
  else { return 0; }
}

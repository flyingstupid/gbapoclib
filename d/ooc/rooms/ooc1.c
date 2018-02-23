#include <mudlib.h>
inherit ROOM;
 
void reset(status arg) {
    object ob;
    if(!present("board")) {
        ob = clone_object(BULLETIN_BOARD);
        ob -> set_long("This board is for OOC discussion, as well as general "+
          "mud discussion.\n");
        ob -> set_save_file("ob_saves/boards/ooc1");
        move_object(ob, this_object());
    }
 
    if(arg) return;
    set_weather(2, 1, 0);
    set_short("the hub");
    set_long(
        " [ 00C ] MAGIA's Hub \n"+
      "This is the center of activity for player activities. From here \n"+
      "players launch themselves into the virtual world of "+
        MUD_NAME+".\n"+
        "You can visit the Heaven7 creativity centre to the south,\n"+
        "the Player Discussion Centre, which is to the north, \n"+
        "or you can enter a cozy room for some socialising.\n"+
	"\nTo enter play, type -ic\n"+
	"Newbies go west to learn about the mud.\n\n");
    set_ooc_room(1);
    set_exits(({
        "d/ooc/rooms/ooc2","enter",
        "d/ooc/rooms/play", "north",
        "d/ooc/rooms/h7", "south",
        "d/ooc/creator/inner1", "east",
        "d/ooc/rooms/newbie", "west",
      }));
   set_items(({
     "forcefield",
       "An invisible forcefield protects a fragile rift in the delicate\n"+
       "fabric of time and space.  A soft, blue light emanates from the\n"+
       "rift and prevents you from seeing what is beyond its threshold.\n",
     }));
}
 
void init() {
  ::init();
  if((int)this_player()->query_level() < 2)
    this_player()->set_race((string)this_player()->query_race());
  add_action("east", "east");
}
 
status east() {
  if(!(int)this_player()->query_security_level()) {
    write("An invisible forcefield stops you in your tracks.\n");
    say(this_player()->query_name()+" stumbles into a forcefield and "+
        "and bounces off.\n", this_player());
    return 1;
  }
  write("\nYou pass through the forcefield.\n\n");
  return 0;
}

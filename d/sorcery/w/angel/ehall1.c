#include <mudlib.h>
inherit ROOM;

object mage;
void reset(status arg) {

  reset_doors(arg);

  load_door(({
	"file", "d/affils/rooms/brm",
	"direction", "south door",
	"long",
	"A door of smoky black wood",
  }));

  if(!mage) {
    mage = clone_object("d/sorcery/w/angel/monst/shaarla");
    move_object(mage, this_object());
  }

  if(arg) return;
  set_short("the tower of sorcery");

  set_long(
"You stand in a simple hallway, lined with a dark marble, that extends \n"+
"to the east. Torches light the way through the cold air toward a door \n"+
"at the end of the corridor. Standing against the north wall is a  \n"+
"tall water clock.\n");

  set_items(({
"plaque", "Perhaps you should read it?",
"hallway#corridor",
"A long hallway which leads only to the door at its end",
"torch#torches",
"Torches line both sides of the wall, shedding light into this dark place",
  }));

  set_listen("You can hear soft talking from the east of the hallway.\n");
  set_smell("The air is full of the smell of old books.\n");

  set_weather(2, 1, 0);
  set_exits(({
	"d/sorcery/w/angel/hall3", "west",
	"d/sorcery/w/angel/ehall2", "east",
  }));
}

void init() {
  ::init();

  add_action("read_it", "read");
  add_action("look_at", "look");
  add_action("look_at", "l");
  add_action("look_at", "examine");
  add_action("look_at", "exa");
}

status look_at(string str) {
  string tmp1, tmp2;

  if(!str) return 0;

  if(sscanf(str, "%sclock%s", tmp1, tmp2)) {
    write("The clock is almost ten feet tall, and has all together too \n"+
          "many gears and cogs. Water running from the top seems to power\n"+
	  "this engineering master piece. In The centre of the clock is a\n"+
	  "pannel that reads:\n");
    write(this_object()->query_time()+"\n");
    write("\nAt the very bottom is a small plaque.\n");
    return 1;
  }
  return 0;
}

status read_it(string str) {
  string tmp1, tmp2;

  if(sscanf(str, "%splaque%s", tmp1, tmp2)) {
    if(!this_player()->query_language("gnome")) {
      write("It's written in gnomish, which is a language you don't "+
	"understand.\n");
      return 1;
    }
    else {
      write("The plaque is in gnomish, and reads:\n"+
	"To the Council of Mages,\n"+
	"\tWe thank you for saving our city, Gnome Dome, during the \n"+
	"\tSecond Age of Magic, from the One Whose Name is Spoken\n"+
	"\tin Whispers. We shall remember your courage always.\n");
      return 1;
    }
  }
  return 0;
}

#include <mudlib.h>
#define PKOFFICE "/d/coronos/w/angel/city/chambers/pkoffice"
#include <combat.cfg>


inherit ROOM;

void reset(status arg) {
  reset_doors(arg);

  if(arg) return;
  load_door(({
	"file", "d/coronos/w/angel/city/chambers/pkoffice",
	"direction", "cell door",
	"long",
	"A large iron gaol door with a little peep hole at the top.\n",
  }));

  set_short("the Ille Coronos gaol");
  set_long("The shadows of the cell cling to the heavy darkness that       \n"+"hangs forbodingly here. It is like a thick blanket, smothering \n"+"all who spend time within this dank place. A small bench of    \n"+"iron stands against the wall beside a pair of wall manacles;   \n"+"an ever present reminder that this is no place of happiness,   \n"+"but of despair.\n");

  set_weather(1, 1, 0);
  set_exits(({
  }));
  set_listen("You can hear a guard outside.\n");
  set_smell("The air in here is very stale.\n");
}

status query_no_fight() { return 1; }
status query_no_teleport() { return 1; }
status query_no_scry() { return 1; }

void init() {
  ::init();
  add_action("command_centre", "", 1);
}

status command_centre(string str) {
  string verb;
  verb = query_verb();
  if(this_player()->query_security_level()) return 0;
  if(!PKOFFICE -> query_villian(this_player()->query_name(1))) return 0;

  if(verb != "say") {
    write("You struggle in your bonds. All you can do is say things.\n");
    return 1;
  }
  return 0;
}

#include <mudlib.h>

inherit TREASURE;

void reset(status arg) {
  if(arg) return;


  set_name("scroll");
  set_short("A fine scroll");
  set_long(
	"The scroll bears the insignia of the Tempus city clerk.\n"+
	"It looks very official. Perhaps you could read it?\n");
  set_smell("The scroll smells of musty parchment.\n");
  set_listen("Scrolls don't usually make any noise!\n");
  set_weight(1);
  set_sell_destruct(1);
  set_value(10);
}

void init() {
  ::init();
  add_action("read_me", "read");
}

status read_me(string str) {
  if(id(str)) {
    write("The scroll reads...\n\n");
    this_player()->quest_hint();
    return 1;
  }
  return 0;
}


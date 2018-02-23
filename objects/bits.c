#include <mudlib.h>
#define NAME	(string)this_player()->query_name()

inherit TREASURE;

static status got_head;
void reset(status arg) {
  if(arg) return;
  set_name("bits of arrow");
  set_alias("pieces");
  set_short("Pieces of broken arrow");
  set_long(
	"This was once a fine arrow, but now it is in many pieces.\n");
  set_weight(2);
  set_value(2);
  set_sell_destruct(1);
}

void init() {
  add_action("bits", "get");
  add_action("bits", "take");
}

status bits(string str) {
  string tmp1, tmp2;

  if(sscanf(str, "%shead%s", tmp1, tmp2)) {
    if(got_head) {
      write("There is nothing to get from the broken shaft.\n");
      return 1;
    }
    if(!this_player()->add_weight(1)) {
      write("You can't carry anymore.\n");
      return 1;
    }
    write("You take the arrow head from the broken shaft.\n");
    say(NAME+" takes an arrow head from the broken arrow shaft.\n", 
      this_player());
    got_head = 1;
    set_value(1);
    set_weight(1);
    move_object(clone_object("objects/head"),this_player());
    return 1;
  }
  return 0;
}

void long(status wiz) {
  ::long(wiz);
  if(!got_head) 
    write("The arrow head on the shaft still looks in fine condition.\n");
  else
    write("The arrow head appears to be missing from the shaft.\n");
}

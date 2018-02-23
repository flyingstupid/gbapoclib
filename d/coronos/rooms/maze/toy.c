#include <mudlib.h>

#define NAME	(string)this_player()->query_name()

inherit TREASURE;

void reset(status arg) {
  if(arg) return;
  set_name("top");
  set_short("A spinning top");

  set_long(
"The top is small and red with stripes fanning down \n"+
"its sides into colours of bright yellows and oranges.\n");

  set_weight(1);
  set_value(50);
  set_sell_destruct(1);
  set_alias("sol's toy");
}

void init() {
  ::init();
  add_action("spin", "spin");
  add_action("spin", "turn");
}

status spin() {
  write("You spin the top and watch the colours fly!\n");
  say(NAME +" spins a small toy top.\n");
  return 1;
}



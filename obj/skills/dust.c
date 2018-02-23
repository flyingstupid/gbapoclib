#include <mudlib.h>
inherit TREASURE;


void reset(status arg) {
  if(arg) return;
  set_name("dust");
  set_plural("piles of dust");
  set_short("A pile of dust");
  set_alias("pile");
  set_long(
    "It looks like simple grey dust...\n");
  set_weight(1);
}

status drop(status silently) {
  write("The dust just blows away...\n");
  destruct(this_object());
  return 1;
}



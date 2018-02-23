#include <mudlib.h>
inherit CLOTHING;
 
reset(arg) {
  if(arg) return;
  set_name("cow bell");
  set_alias("bell");
  set_short("a cow bell");
  set_long(
    "This is a simple cow bell made of metal.  It is\n"+
    "attached to a leather strap, so it can be fastened\n"+
    "to a cow's neck.\n");
  set_weight(1);
  set_value(80);
  set_sell_destruct(1);
}

void init() {
  add_action("ringer", "ring");
  ::init(); 
}

status ringer(string str) {
  string tmp1, tmp2;

  if(!str) {
  write("Do you wish to ring the bell?\n");
  return 1;
  }

  else if(sscanf(str, "%sbell%s", tmp1, tmp2)) { 
  write(
    "You ring the cow bell loudly.  CLINK! CLINK! CLINK!\n");
  say(this_player()->query_name()+
    " rings a cow bell loudly.  CLINK! CLINK! CLINK!\n", this_player());
  return 1;
  }
return 0;
}

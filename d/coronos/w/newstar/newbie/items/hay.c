#include <mudlib.h>
inherit TREASURE;
 
 void reset (status arg){
  if(arg) return;
 
  set_weight(1);
  set_value(0);
  set_name("some hay");
  set_alias("hay");
  set_short("some hay");
  set_long(
    "This is some hay.  It's tough and golden.\n"+
    "The farm animals seem to love this stuff.\n"+
    "Maybe you can chew on it.\n");
  set_extra_info("It doesn't look very tasty.\n");
  set_sell_destruct(1);
}
void init() {
  add_action("chew", "chew");
  ::init();
}
 
status chew(string str) {
  string tmp1, tmp2;
 
  if(!str) {
  write("What do you want to chew?\n");
  return 1;
  }
 
  else if(sscanf(str, "%shay%s", tmp1, tmp2)) {
  write("You chew on a piece of hay.\n");
  say(this_player()->query_name()+
    " chews on a piece of hay.\n", this_player());
  return 1;
  }
return 0;
}

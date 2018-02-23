#include <mudlib.h>
inherit "/d/coronos/w/solstice/univ/class/mage_trn";
 
string G_NAME;
 
void init() {
  ::init();
 
  add_action("unknown", "train");
  add_action("advance", "learn");
 
  if (sign) {
    destruct(sign);
  }
}
 
 
int query_no_fight() {
  return 0;
}
 
status unknown(string str)  {
  write(G_NAME+" looks at you in a confused manner.\n");
  return 1;
}
 
 
status join(string str)  {
  if (str != "mage") {
    write(G_NAME+" says: I only deal with mages.\n");
  }
  else if (this_player()->query_class(str)) {
    write(G_NAME+" smirks.\n");
    write(G_NAME+" says: You're already a "+str+", remember?\n");
  }
  else {
    write(G_NAME+" says: You have to enroll in mage studies for me to teach "+
          "you.\n");
  }
 
  return 1;
}
 
status advance(string str, status costing)  {
  if (!str || str == "level" ) {
    return unknown(str);
  }
 
  return ::advance(str, costing);
}
 
void set_guild_master_name(string str) {
  G_NAME=str;
}
 

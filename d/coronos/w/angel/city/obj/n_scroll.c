#include <mudlib.h>

inherit TREASURE;

void reset(status arg) {
  if(arg) return;
  set_name("parchment");
  set_alias("fromshadowbane");
  set_short("a piece of parchment");

  set_long(
"To Bailston,\n"+
"The fellow who brings you this letter wishes to join the infantry.\n"+
"Please show this fine person all courtesy.\n"+
"Shadowbane.\n");

  set_weight(1);
}

status drop(status quit) {
  if(quit)  {
    write("The parchment blows away...\n");
    destruct(this_object());
    return 1;
  }
  return 0;
}


    

#include <mudlib.h>
inherit TREASURE;
 
void reset (status arg){
  if(arg) return;
  
  set_weight(1);
  set_value(10);
  set_name("brass key");
  set_alias("key");
  set_short("a brass key");
  set_long("This is a small key made of brass.  It isn't very\n"+
    "well crafted, but it probably works just fine.\n");
}

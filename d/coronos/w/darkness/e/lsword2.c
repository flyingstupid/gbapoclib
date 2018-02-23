#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
  if(arg) return;
 
  set_name("longsword");
  set_short("a longsword");
  set_alias("sword");
  set_long(
    "This is a longsword of elvish make.  The long blade looks to be\n"+
    "sharp and deadly.  The hilt is grooved for better grip, and the\n"+
    "silver colored guard is decorated with vine-like designs.\n");
  set_length(45);
  set_type("slash");
  set_value(1800);
  set_wc(13); 
  set_weight(5);
}

#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
    if(arg) return;
 
  set_name("duster");  /* Just a fun weapon with WC of 1 */
  set_alias("duster");
  set_short("a feather duster");
  set_long(
    "This is a feather duster used to brush the dust of items of\n"+
    "furniture.  It as a simple wooden handle and brown feathers\n"+
    "sticking out in all directions at one end.\n");
  set_length(18);
  set_type("crush");
  set_value(1 + random(10));
  set_sell_destruct(1);
  set_wc(1);
  set_weight(1);
 
  set_attack_msg(({
    "missed", "barely",
    "dusted", "off",
    "bopped", "on the head",
    "swiped", "across the face",
    "jabbed", "in the stomach",
    "gave", "repeated smacks",
    "whacked", "upside the head",
    }));
}


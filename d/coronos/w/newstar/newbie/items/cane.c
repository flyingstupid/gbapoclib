/* cane.c */
/* Darkness & Newstar */

#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
    if(arg) return;
 
  set_name("club");
  set_alt_name("wooden cane");
  set_alias("cane");
  set_short("a wooden cane");
  set_long(
    "This is a wooden walking stick, usually refered to as a cane.\n"+
    "The stick is very long and ends in a finely crafted, arched\n"+
    "handle.  It looks very sturdy.\n");
  set_length(36);
  set_type("crush");
  set_value(40);
  set_sell_destruct(1);
  set_wc(4);
  set_weight(1);

  set_attack_msg(({
    "tapped", "gently",
    "poked", "hard",
    "grazed", "",
    "quickly jabbed at", "",
    "smacked", "hard",
    "flailed the cane wildly at", "",
    "brought the cane down on", "",
    }));
}
 

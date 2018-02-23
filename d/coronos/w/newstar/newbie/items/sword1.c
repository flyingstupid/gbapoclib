/* sword1.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
    if(arg) return;
 
  set_name("shortsword");
  set_alias("sword");
  set_short("an old sword");
  set_plural("old swords");
  set_long(
    "This is an old sword that has seen many battles.  It has been\n"+
    "taken very good care of though, and is still battle worthy after\n"+
    "so many years.\n");
  set_length(23);
  set_type("slash");
  set_sell_destruct(1);
  set_value(275);
  set_wc(8);
  set_weight(4);
}

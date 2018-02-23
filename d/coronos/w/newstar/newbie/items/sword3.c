/* sword3.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit WEAPON;
 
reset(arg) {
    if(arg) return;
 
  set_name("shortsword");
  set_alias("sword");
  set_short("a drow sword");
  set_plural("drow shortswords");
  set_long(
    "This is an old shortsword made by the Drow.  It is excelently made\n"+
    "and looks to have been through many battles.  The blade may not be\n"+
    "as sharp as it used to be, but it still does its job well.\n");
  set_length(23);
  set_type("slash");
  set_sell_destruct(1); 
  set_value(275);
  set_wc(8);
  set_weight(4);
}

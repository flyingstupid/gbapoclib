#include <mudlib.h>
inherit WEAPON;

void reset(status arg) {
  if(arg) return;
  set_type("cleave");
  set_name("battleaxe");
  set_short("A fine battle axe");
  set_alias("axe");

  set_long(
"This is a fine battle axe, made from a metal with a light blue \n"+
"tinge, with a double head, while the hilt is bound in a black  \n"+
"tough leather thong. The whole axe is huge, and it is a wonder \n"+
"if anyone can wield it effectively at all. \n");

  set_weight(6);
  set_value(2700);
  set_wc(16); /* +4 battle axe */
  set_enchanted(1);
  set_length(55); /* a BIG one! */
}

#include <mudlib.h>

inherit WEAPON;

void reset(status arg) {
  if(arg) return;
  set_name("mace");
  set_short("A wrought iron mace");
  set_long(
    "This is a fine and sturdy mace, made from iron, bound with \n"+
    "strong leather along the length of its grip.\n");
  set_type("crush");
  set_wc(12); /* a standard mace */
  set_length(36);
  set_weight(5);
  set_value(1100);
  set_plural("maces");
}

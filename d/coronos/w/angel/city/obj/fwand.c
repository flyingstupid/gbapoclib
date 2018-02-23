/* A wand of fireballs */

#include <mudlib.h>
inherit WAND;

void reset(status arg) {
  if(arg) return;
  set_name("baton");

  set_alias("runes");  /* so they can read them! */
  set_short("A black baton");
  set_long(
"The black baton has silvery runes along the side, ending in a silver tip.\n");

  set_read(
"The runes are magical in nature, and perhaps reveal something about "+
"the item.\n");

  add_spell("fire ball");
  set_weight(1);
  set_class(({ "mage", "cleric", "fighter", "thief", "paladin", }));
  /* everyone can use it */
  set_sell_destruct(1);
  set_cast_level(10);
  set_max_charges(100);
  set_charges(100);
  set_info("A wand of fireballs.\n");
}



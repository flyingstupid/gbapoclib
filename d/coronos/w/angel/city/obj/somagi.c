#include <mudlib.h>
inherit MAGIC_WEAPON;

void reset(status arg) {
  if(arg) return;
  set_name("staff");
  set_length(80);
  set_type("crush");
  set_wc(14);
  set_weight(4);
  set_value(4000); /* more 'cause its a staff o the magi! */

  set_short("A long oaken staff");
  set_plural("staves");

  set_long(
    "This long stave is iron shod at one end, prooving to be a \n"+
    "valuable weapon in combat. Along the sides of the staff   \n"+
    "are runes of various types. At the very tip is a single   \n"+
    "gem, perhaps even a diamond. \n");

  set_info("A staff of the Magi.\n");

  set_cast_level(17);
  set_max_charges(150);
  set_charges(150);
  add_spell("detect magic");
  add_spell("enlarge");
  add_spell("lt");
  add_spell("detect evil");
  add_spell("fire ball");
  add_spell("lightning bolt");
  add_spell("dispel magic");
  add_spell("ice storm");
}


#include <mudlib.h>
inherit WAND;

void reset(status arg) {
  if(arg) return;
  set_name("sapphire");
  set_short("A small sapphire");
  set_alias("gem");
  set_long(
	"A sapphire that glows with an intense blue.\n");
  set_light(3);
  set_cast_level(20);
  set_max_charges(100);
  set_charges(100);
  add_spell("lightning bolt");
  add_spell("fire ball");
  add_spell("flamestrike");
}

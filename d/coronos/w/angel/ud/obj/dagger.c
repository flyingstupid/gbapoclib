#include <mudlib.h>

inherit MAGIC_WEAPON;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("dagger");
  set_max_charges(50);
  set_cast_level(20);
  set_charges(50);
  set_info("The dagger protects the wielder from lightning.\n");
  set_short("A silver dagger");
  set_long(
	"A fine silver dagger with a keen edge. In the dagger's hilt is \n"+
	"a small blue emerald that flickers in the light. \n");
  set_wc(10);  /* a +2 dagger */
  set_weight(4);
  set_length(15);
  set_type("slash");
  set_value(275);
  set_protection("lightning");
  add_spell("lightning bolt");
}

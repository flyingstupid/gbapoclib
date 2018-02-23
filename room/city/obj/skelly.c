#include <mudlib.h>
inherit CONTAINER;

static object ob;
void reset(status arg) {
  if(!present("leather")) {
    ob = clone_object(ARMOUR);
    ob -> set_ac(1);
    ob -> set_weight(3);
    ob -> set_value(130);
    ob -> set_armour_material("leather");
    ob -> set_short("a suit of leather armour");
    ob -> set_type("armour");
    ob -> set_long("This suit of leather armour is dirty and has seen \n"+
		   "alot of action in its lifetime. While it was once \n"+
		   "well polished and looked after, it has now fallen \n"+
		   "prey to the elements.\n");
    ob -> set_smell("The armour smells a bit musty.\n");
    ob -> set_listen("The leather doesn't make a sound.\n");
    move_object(ob, this_object());
  }

  if(arg) return;
  set_short("A rotting corpse");
  set_long(
	"The corpse is old and rotting away, with maggots eating at the \n"+
	"fleshy bits still hanging to the partched white bones.\n");
  set_weight(50000);
  set_max_weight(10);
}


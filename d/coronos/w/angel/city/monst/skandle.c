#include <mudlib.h>

#define OBJ	"d/coronos/w/angel/city/obj/"

inherit MONSTER;

object robe;
object staff;
void reset(status arg) {
  ::reset(arg);

  if(!present("robe")) {
    robe = clone_object(OBJ+"brobe");
    move_object(robe, this_object());
    init_command("wear robe");
  }

  if(arg) return;
  set_wander(1000, 50);
  set_name("skandle");
  set_short("An old man");
  set_long(
	"From deep within the shadows of his dark hood, two eyes\n"+
	"filled with hatred and an evil beyond mortal comprehension stare\n"+
	"deep into the heart of your soul. Whoever this devil of a \n"+
	"man is, you are sure he could destroy you with a single glance.\n");

  set_gender(1);
  set_level(100);
  add_class("mage");
  add_class("thief");
  add_class("cleric");
  add_class("fighter");

  set_magic_resist(90); /* might as well have some chance */
  set_alias("old man");
  set_alt_name("man");
  set_dead_ob(this_object());
}

void monster_died() {
  object ob;
  tell_room(environment(), "Skandle says: You shall not have me so easily.\n"+
    "Skandle summons up a great mist around him.\n"+
    "When the mist clears, he has vanished from sight.\n");
  destruct(present("corpse", environment()));
}

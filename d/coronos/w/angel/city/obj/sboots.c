/* boots of speed! */

#include <mudlib.h>
inherit ARMOUR;

string old_msgin, old_msgout;

void reset(status arg) {
  if(arg) return;
  set_type("boots");
  set_ac(1);
  set_weight(1);
  set_name("boots");
  set_alias("guild_object"); /* to pick up the boots ability! */
  set_plural("pairs of boots");
  set_short("A pair of hard leather boots");
  set_long(
    "This pair of boots are made from a hard leather that will \n"+
    "withstand the hardships of combat. They also have a tiny  \n"+
    "pair of gold wings at the heels.\n");
  set_value(300);
  set_armour_material("leather");
  set_info("These are boots of speed and grant the wearer the power "+
    "of haste.\n");
  set_enchanted(1);
}

int query_extra_attack() {
  object ob;

  ob = environment();
  if(query_worn()) {
    if(!random(5)) {
      tell_object(ob, "Your boots seem hasten your actions...\n");
      say(ob->query_name()+" seems to hasten a little...\n", ob);
    }
    return 1;
  }
  return 0;
}

void remove_func(object ob) {
  object b;
  if(ob != this_object()) return;
  b = this_player()->query_speed_object();
  if(b) destruct(b);
}

void wear_func(object ob) {
  object b;
  if(ob != this_object()) return;
  b = clone_object("obj/shadows/speed");
  b -> shadow_movement();
}

status drop(status silently) {
  remove_func(this_object());
  return ::drop(silently);
}

/****************************************************************************/
/* Gauntlets of Ogre Power */

#define OGRE_POWER       25

#include <mudlib.h>
inherit ARMOUR;

void remove_func(object ob);
void wear_func(object ob);
status strong;
int old_strength;

void reset(status arg) {
  if(arg) return;
  set_name("gauntlets");
  set_type("gloves");
  set_alias("external_object");
  set_short("A pair leather gauntlets");
  set_long("A fine pair of black, studded leather gauntlets.\n");
  set_armour_material("leather");
  set_ac(1);
  set_weight(2);
  set_value(1000);  /* because of magical properties */
  set_sell_destruct(1);
  set_enchanted(1);
  set_info("These leather hand gear are enchanted with 'Ogre Power'.\n");
}

void wear_func(object ob) {
  if(!strong) {
    strong = 1;
    tell_object(environment(),"You feel stronger!\n");
    old_strength = (int)environment()->query_strength();
    environment()->set_strength(OGRE_POWER);
  }
}


void remove_func(object ob) {
  if(strong) {
    strong = 0;
    write("You feel your normal self once more.\n");
    environment()->set_strength(old_strength);
  }
}

status drop(status quit) {
  remove_func(this_object());
  return ::drop(quit);
}

status id(string str) {
  if(strong) return str == "no_advance" || ::id(str);
  else return ::id(str);
}

inherit "inherit/drink";


#include <spell.h>


void dispel_magic() {
  tell_object(environment(),"The Water vanishes!\n");
  destruct(this_object());
}

status cast_spell(object caster,object target,object prev,int level) {
  mixed *loaded_spell;
  string c_name;

  /* the spell MUST have a component for the spell */

  loaded_spell = (mixed *)caster->query_loaded_spell();
  c_name = (string)COMPONENT[0]->query_empty_container();
  if(!c_name) c_name = "bottle";

  if(level > 40) level = 40;  /* healing strength */
  set_name("water");
  set_alias(c_name);
  set_alt_name("spell");
  set_soft_drink(1);
  set_short("A "+ c_name +" of water");
  set_weight(1);
  set_long("The water inside is fresh and cool.\n");
  set_empty_container(c_name);
  set_strength(level);
  set_consumer_msg("The cool water refreshes your partched throat.\n");
  set_room_msg("@@query_name:$this_player()$@@ drinks some fresh water.\n");

  tell_object(target, "Some water fills the "+ c_name +".\n");
  if(!target->add_weight(1)) move_object(this_object(), environment(target));
  target->recalc_carry();
  return 1;
}

status drop(status quit) {
  if(quit) dispel_magic();
  return 0;
}


/* created food */

inherit "inherit/food";

status cast_spell(object caster,object target,object prev,int level) {
  object obj;

  if(level > 50) level = 50;
  set_name("food");
  set_alt_name("spell");
  set_short("A bowl of lumpy food");
  set_plural("bowls of lumpy food");
  set_weight(1);
  set_long("It looks like wet, soggy, thick cardboard.\n");
  set_strength(level);
  set_consumer_msg("It tastes lumpy and bland, but is quite filling.\n");
  set_room_msg("@@query_name:$this_player()$@@ eats a bowl of lumpy food.\n");

  tell_object(target, "Some food magically appears before you.\n");
  if(!target->add_weight(1)) move_object(this_object(), environment(target));
  target->recalc_carry();
  return 1;
}

void dispel_magic() {
  tell_object(environment(),"The Food vanishes!\n");
  destruct(this_object());
}

status drop(status quit) {
  if(quit) dispel_magic();
  return 0;
}


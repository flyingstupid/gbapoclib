/* spell disease */


status cast_spell(object caster,object target,object prev,int time) {
  object deaf;

  if((int)caster->query_spell_dmg() == time &&
    !present("Disease", target)) {
    write("You make "+ target->query_name() +" catch a disease!\n");
    tell_object(target,"You start to sniff.\n");
    move_object(clone_object("objects/disease"), target);
  }
  else {
    tell_room(environment(caster), "Nothing Happens...\n");
  }
  destruct(this_object());
  return 1;
}


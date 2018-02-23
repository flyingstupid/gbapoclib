/* deafness */

inherit "inherit/timer";

status id(string str) {
  return str == "Deafness";
}

void time_out() {
  tell_object(environment(),"You can hear!\n");
  ::time_out();
}

void dispel_magic() { time_out(); }


status cast_spell(object caster,object target,object prev,int time) {
  object deaf;

  if((int)caster->query_spell_dmg() == time) { /* did not save */
    if((deaf = present("Deafness 2", target))) {
      write("You extend the time of the Deaf spell.\n");
      deaf->adj_time(time * 30);
      destruct(this_object());
      return 1;
    }
    write("You make "+ target->query_name() +" deaf!\n");
    tell_object(target,"Everything goes silent!\n");
    adj_time(time * 30);
  }
  else {
    tell_room(environment(caster), "Nothing Happens...\n");
    destruct(this_object());
  }
  return 1;
}


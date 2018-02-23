/* blindness */

inherit "inherit/timer";

status id(string str) {
  return str == "Blindness";
}

void time_out() {
  tell_object(environment(),"You can see!\n");
  ::time_out();
}

void dispel_magic() { time_out(); }

void extra_long(status wiz) {
  if(this_player() != environment()) {
    if(environment()->query_pronoun()) {
      write(capitalize((string)environment()->query_pronoun()) +
            " is Blind!\n");
    }
  }
}

status cast_spell(object caster,object target,object prev,int time) {
  object deaf;

  if((int)caster->query_spell_dmg() == time) { /* did not save */
    if((deaf = present("Blindness 2", target))) {
      write("You extend the time of the Blind spell.\n");
      deaf->adj_time(time * 30);
      destruct(this_object());
      return 1;
    }
    write("You make "+ target->query_name() +" blind!\n");
    tell_object(target,"Everything goes dark!\n");
    adj_time(time * 30);
  }
  else {
    tell_room(environment(caster), "Nothing Happens...\n");
    destruct(this_object());
  }
  return 1;
}


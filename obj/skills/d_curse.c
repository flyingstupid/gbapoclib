/* death curse */

inherit "inherit/base/base_obj";
inherit "inherit/timer";

int level;

void reset(status arg) {
  if(arg) return;
  set_alt_extra_long("You have cast death curse.\n");
  set_name("death curse");
  set_alias("guild_object");
  set_alt_name("spell");
}

void time_out() {
  tell_object(environment(), "The death curse spell fades....\n");
  ::time_out();
}

void dispel_magic() { time_out(); }


status cast_spell(object caster,object target,object prev,int time) {
  object curse;

  curse = present("death curse 2", target);
  if(curse) {
    write("You extent the time of your death curse.\n");
    curse->adj_time(time * 60);
    destruct(this_object());
    return 1;
  }
  write("The gods grant you you Death Curse.\n");
  level = time;
  adj_time(time * 60);
  return 1;
}


void player_death() {
  if(this_player() != environment()) {
    write("Death comes to get you personally.\n");
    this_player()->check_shout(environment()->query_name() +" death curses "+ 
                this_player()->query_name() +"!\n");
    if(this_player()->query_immunity("death")) {
      write("The curse has no effect on you.\n");
    }
    else if(random((int)this_player()->query_wisdom()) < random(level)) {
      this_player()->death(); /* curser gets no exp */
    }
  }
  else {
    write("The curse has no effect on you.\n");
  }
}




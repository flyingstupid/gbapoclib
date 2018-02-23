/* general - spell armor bonus object */

inherit "inherit/base/base_obj";
inherit "inherit/timer";

int ac_bonus;

int set_ac_bonus(int i)  { return ac_bonus = i; }

int armour_class_bonus() { return ac_bonus;     }

void reset(status arg) {
  if(arg) return;
  enable_commands();
  set_heart_beat(1);
}

void heart_beat() {
  if(!random(10))
    if(environment())
    tell_room(environment(), "The "+query_name()+" shimmers...\n");
}

void time_out() {
  ac_bonus = 0;
  tell_object(environment(),"The "+ query_name() +" fades...\n");
  if(environment()) environment()->recalc_ac();  
  set_heart_beat(0); /* stop the heart beat! */
  ::time_out();
}

void dispel_magic() { time_out(); }

status drop(status quit) {
  if(quit) time_out();
  return 1;
}

status id(string str) {
  return str == "external"
      || str == "spell"
      || str == "spell armor"
      || ::id(str);
}


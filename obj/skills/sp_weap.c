/* general - spell weapon bonus object */

inherit "inherit/base/base_obj";
inherit "inherit/timer";

int wc_bonus;
int left_wc_bonus;

int set_wc_bonus(int i)      { return wc_bonus = i;      }
int set_left_wc_bonus(int i) { return left_wc_bonus = i; }

int weapon_class_bonus()      { return wc_bonus;      }
int left_weapon_class_bonus() { return left_wc_bonus; }


void time_out() {
  wc_bonus = 0;
  tell_object(environment(),"The "+ query_name() +" fades...\n");
  environment()->recalc_wc();  
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
      || str == "spell weapon"
      || ::id(str);
}

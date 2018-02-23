/*
 * This is a generic torch.
 * It will have some good initialisations by default.
 * The torch can't be sold when it is lit.
 */
 
#include <ansi.h>
#include <mudlib.h>
 
inherit TREASURE;
 
inherit "inherit/timer";
 
 
#define NAME (string)this_player()->query_name()
 
int fuel;             /* time left in seconds    */
int max_fuel;         /* time u got when u first made the item */
int light_intensity;  /* light intensity of this */
 
 
void reset(status arg) {
  if(arg) return;
  set_name("torch");
  set_plural("torches");
  set_smell("It smells smokey.\n");
  set_short("a torch");
  set_long("This is a bundle of thatch tied together, with the end "+
           "soaked in oil.\n");
  set_extra_info("Looking at the fluttering flames, you think the torch\n"+
                 "will last for another @@query_approx_time:"+
                 file_name(this_object()) +"@@.\n");
  set_weight(1);
  fuel = 4000;
  light_intensity = 2;
}
 
string short(status wiz) {
  if(ANSI_ON) {
    if(wiz) 
      return ::short(wiz);
    else 
      return ::short(wiz) +((query_time_left() == -1) ? "" : " ("+
      YELLOW_F+BOLD+"lit"+OFF+")");
  }
  else {
    if(wiz) 
      return ::short(wiz);
    else
      return ::short(wiz) +((query_time_left() == -1) ? "" : " (lit)");
  }
}
 
string query_short() { return short(1); }
 
int query_value() {
  return (query_time_left() == -1) ? fuel/200 : 0;
}
 
void init() {
  ::init();
  add_action("light",      "light"      );
  add_action("extinguish", "extinguish" );

  if(!max_fuel) max_fuel = fuel;
}
 
 
 
/* fuel */
 
int query_max_fuel() { return max_fuel; }
 
int query_fuel() {
  return fuel = (query_time_left() != -1) ? query_time_left() : fuel;
}
 
int set_fuel(int f) { return fuel = f; }
 
int set_max_fuel(int f) { return max_fuel = f; }
 
 
 
/* light intensity */
 
int query_light_intensity()    { return light_intensity;     }
int set_light_intensity(int l) { return light_intensity = l; }
 
 
 
status light(string str) {
  object ob;
  status current_light;
 
  if(!str) {
    notify_fail("light what?\n");
    return 0;
  }
  if(!(ob = present(str, this_player()))) {
    if(!(ob = present(str, environment(this_player())))) {
      if(!environment(this_player())->id(str)) {
        notify_fail("There is no "+ str +" here.\n");
        return 0;
      }
    }
  }
  if(ob != this_object()) return 0;
  if(query_time_left() != -1) {
    write("It is already lit.\n");
    return 1;
  }
  adj_time(fuel);
  current_light = (set_light(0) > 0) ? 2 : 0;
  adj_light(light_intensity);
  if(!current_light && set_light(0) > 0) {
    write("You can see again.\n");
    say(NAME +" lights a "+ query_name() +".\n");
  }
  else {
    write("Your "+query_name()+" bursts into flame!\n");
  }
  return 1;
}
 
 
status extinguish(string str) {
  object ob;
  status current_light;
 
  if(!str) {
    notify_fail("extinguish what?\n");
    return 0;
  }
  if(!environment()) return 0;

  if(!(ob = present(str, this_player()))) {
    if(!(ob = present(str, environment(this_player())))) {
      if(!environment(this_player())->id(str)) {
        write("There is no "+ str +" here.\n");
        return 1;
      }
    }
  }

  if(ob != this_object()) return 0;
  if(query_time_left() == -1) {
    write("There "+ query_name() +" is not lit!\n");
    return 1;
  }
  fuel = query_time_left();
  remove_call_out("time_out");
  current_light = (set_light(0) > 0) ? 2 : 0;
  adj_light(light_intensity*(-1));
  if(current_light && set_light(0) < 2) {
    tell_room(environment(), "It turns dark...\n");
    say(NAME +" extinguishes the only light source.\n");
  }
  else {
    write("You extinguish the "+query_name()+".\n");
  }
  return 1;
}
 
 
void time_out() {
  object ob;
 
  if(set_light(light_intensity*(-2)) == 0)
    say("There is darkness as a "+ query_name() +" flickers out.\n");
  else
    say("The " + query_name() +" flickers out.\n");
  write("Your "+ query_name() +" flickers out...\n");
  ob = environment(this_object());
  call_other(ob, "add_weight", query_weight()*(-1));
  ::time_out();
}
 
 
/**
status drop(status quit) {
  extinguish(query_name());
  return 0;
}

**/

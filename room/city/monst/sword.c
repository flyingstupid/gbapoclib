#include <mudlib.h>
inherit WEAPON;

void query_info();
void info();
void reset(status arg) {
  if(arg) return;

  set_name("longsword");
  set_alias("sword");
  set_short("A silver longsword");
  set_long(
     "This fair longsword glows with a soft light and bears \n"+
     "elvish runes of power along its fine silver blade.    \n");
  set_wc(16);
  set_type("slash");
  set_length(45);  /* a little longer than normal */
  set_weight(5);
  set_value(4000);
  set_hit_func(this_object());
}

init() {
  ::init();
  add_action("read", "read");
}

read(string str) {
  string tmp1, tmp2;
  if(sscanf(str, "%srunes%s", tmp1, tmp2)) {
    if(this_player()->query_languages("elf"))
      query_info();
    else
      write("They don't make any sense to you.\n");
    return 1;
  }
}

void query_info() {
  write("The runes on the blade glow as you read them...\n"+
     "they say - 'Champion, the slayer of Evil'\n");
}

void info() {
  ::info();
  query_info();
}

int weapon_hit(object target) {
  if(target -> query_alignment() < -100) {
    tell_object(environment(), "Your longsword glows a brilliant white!\n");
    say(environment()->query_name() +"'s longsword glows a "+
    "brilliant white!\n",environment());
    return 16; /* x2 damage vs evils */
  }
  return 0;
}

wield(string str) {
  ::wield(str);
  if(id(str)) {
    if(this_player()->query_alignment() < 100) {
      tell_object(environment(), "The longsword sparks in your hands!\n");
      environment()->hit_player(10 + random(20));
      drop();
    }
  return 1;
  }
}

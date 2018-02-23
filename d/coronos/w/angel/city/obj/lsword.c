/* frost brand +3/ +6 */


#include <mudlib.h>
inherit MAGIC_WEAPON;

static status shedding_light;

void reset(status arg) {
  if(arg) return;

  set_name("longsword");
  set_short("A fine longsword");

  set_protection("fire");
  set_long(
"This fine steel longsword was forged at the city of Ille Coronos. It \n"+
"bears the symbol of the Black Guard encompassed by a circle. The blade \n"+
"also bears runes of some description along the blade.\n");

  set_enchanted(1);
  set_wc(16); /* +3 longsword */
  set_weight(6);
  set_value(4000);
  set_length(42);
  set_type("slash");
  set_alias("runes");
  set_plural("longswords");
  set_read("The runes are magical and look somewhat like snow flakes.\n");
  set_info("This is a frost brand sword, designed to slay those \n"+
           "creatures that use or dwell in firery places. It also\n"+
           "sheds light in arctic regions.\n");
  set_hit_func(this_object());
  enable_commands();
  set_heart_beat(1);

}



int weapon_hit(object ob) {

  if(ob->query_spell_immune("fire")) {
    tell_object(environment(), "Your "+query_name()+" glows a "+
    "brilliant white!\n");
    return 3;  /* which makes it a total of +6 vs. cold using */
  }
  return 0;
}

void heart_beat() {
  object ob;

  ob = environment();
  if(ob) if(!environment(ob)) return;

  if((string)environment(ob)->query_climate() == "arctic") {
    if(query_wielded(0) && !shedding_light) {
      tell_object(ob, "Your "+query_name()+" starts to shed a soft glow...\n");
      shedding_light = 1;
      adj_light(1);
    }
  }
  else {
    if(query_wielded(0) && shedding_light) {
      tell_object(ob, "Your "+query_name()+" stops glowing...\n");
      adj_light(-1);
      shedding_light = 0;
    }
  }
}


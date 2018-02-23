#include <mudlib.h>
#define CHANCE 10

inherit WEAPON;

void reset(status arg) {
  if(arg) return;
  set_type("slash");
  set_length(48);
  set_wc(14); /* +2 standard */
  set_name("rapier");
  set_alias("scar");
  set_short("A gold rapier");
  set_long(
"This is one of the finest weapons you have beheld in\n"+
"all the years of your travels. The hilt and guard are\n"+
"encrusted with many gems and jewels, giving the whole\n"+
"weapon an overpowering sense of power and ostentation.\n");
  set_info(
"The weapons name is Scar, and it is a flametongue sword.\n"); 
  set_weight(4);
  set_enchanted(1);
  set_value(3100);
  set_hit_func(this_object());
  enable_commands();
  set_heart_beat(1);
  set_light(1);
}

void heart_beat() {
  string *msg;
  object ob;
  if(!environment()) return;
  if(environment()->query_npc()) return;
  ob = environment(environment());
  if(!query_wielded(0)) return;
  if(!ob) return;

  msg = ({
"Scar asks: Are you my new master?\n",
"Scar exclaims: There is no sword better than I!\n",
"Scar says: Do you know Lord Ekimthanis?\n",
"Scar exclaims: I was created by Bahamut!\n",
"Scar says: let me tell you a story\n",
"Scar exclaims: I once met Antaaries!\n",
"Scar asks: How old are you?\n",
"Scar says: I remember back in the Age of Dreams\n",
"Scar says: I wonder where Lord Alexander is\n",
"Scar says: The best weapon is always a rapier.\n",
"Scar asks: You know the forest near Ille Coronos?\n",
"Scar says: The forests have savage elves in them.\n",
"Scar says: The Mountains have dark elves within them.\n",
"Scar says: Lord Alastaire is a good man.\n",
"Scar says: Theres a dog called Spotty Dog\n",
"Scar says: I was speaking to Spotty Dog the other day\n",
"Scar asks: Have you spoken to wizards before?\n",
"Scar says: Metalic dragons are nice, but scary.\n",
"Scar exclaims: Chromatic dragons are evil, and powerful!\n",
"Scar says: Dont attack good dragons, talk to them.\n",
"Scar asks: Where are we, anyway?\n",
 });

  if(!random(CHANCE))
    tell_room(ob, msg[random(sizeof(msg))]);
}

int weapon_hit(object obj) {
  if(!obj) return 0;
  if((status)obj->query_spell_immunity("cold")) {
    tell_object(environment(), "Scar's flames flair up!\n");
    return 14;  /* x2 vs cold */
  }
  else if(obj->id("undead")) {
    tell_object(obj,
	"Scar's flames burn brighter!\n");
    return 28; /* x3 vs undead */
  }
  return 0;
}

status wield(string str) {
  ::wield(str);
  if(id(str)) {
    if((int)this_player()->query_alignment() < 100) {
      tell_object(this_player(), "Scar exclaims: You may not wield me!\n");
      environment()->hit_player(14);
      drop();
    }
  }
}

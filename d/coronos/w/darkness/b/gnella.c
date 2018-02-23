/* Gnella the Gnome */
/* Darkness */

#include <mudlib.h>
inherit MONSTER;
int count;

void reset(status arg) {
  object obj;

  ::reset(arg);
  if(arg) return;

  set_name("gnella");
  set_alias("gnome");
  set_short("Gnella");
  set_long(
    "Gnella is actually rather pretty by human standards.  Her gnomish nose is\n"+
    "not quite as large as most, and her dark hair is long and straight.  Though\n"+
    "she is only a meter tall, her very slim figure almost makes her look like a\n"+
    "pixie.  Her flowing robes are decorated with elaborate stitchings, ornamented\n"+
    "with a gold amulet hanging around her neck.\n"); 

  load_chat(4, ({ 
    "Gnella: Hello to you.\n",
    "Gnella: I can't wait to speak with the other illusionists of the city.\n",
    "Gnella: Do you know the ways of magic?\n",
  }));
 
  load_l_chat(4,"gnome",({
    "Hello.\n",
    "Good day to you.\n",
    }));

  load_a_chat(30,({ 
    "Gnella: Help!\n",
    "Gnella: Guards!\n",
    "Gnella: Somebody help!\n",
    "Gnella deftly maneuvers around the attacks against her.\n",
    "Gnella glows with magic.\n",
  }));

  set_race("gnome");
  set_gender(2);
  set_alignment(150);
  set_level(18);
  set_max_hp(800);
  set_hp(800);
  set_ac(27);  /* +1 to AC because she's a small gnome */
  set_wc(14);  /* -1 to WC because she's a small gnome */
  add_class("mage");
  add_class("fighter");
  set_multi_attack(10);
  set_intelligence(26);
  set_illusion(30);
  set_abjuration(30);
  set_alteration(20);
  set_conjuration(0);
  set_necromancy(0);
  set_evocation(20);
  set_charm(0);
  set_divination(0);
  add_money(2100+random(100));
  set_magic_resist(30);
  add_spell_immunity("charm");
  set_heart_ob(this_object());

  load_spells(40, ({
    "phantom armour", "burning hands", "shield", 
    "stoneskin", "resist magic", "magic missile", "fire ball",
    "ice storm", "acid arrow", 
    /* "shadow monster", "monster summon 3", */
    })); 

  if(!present("knife")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/b/knife"),this_object());
  }

  if(!present("amulet")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/b/amulet"),this_object());
    command("wear amulet");
  }
}


void monster_heart_beat()  {
  object pidge_ob;

  if(this_object()->query_attack()) {
    if(count!=1) {
      command("wield knife");
      tell_room(environment(),
        "Gnella readies herself for battle.\n");
      count = 1;
    }
  }

  if(this_object()->query_attack()) {
    if(pidge_ob = present("pidge", environment())) {
      if(pidge_ob -> query_attack() != query_attack()) {
        pidge_ob -> add_secondary_attacker(query_attack());
        query_attack() -> add_secondary_attacker(pidge_ob);
        tell_room(environment(),
          "\nGnella screams for help!\n"+ 
          "Pidge jumps in to help her.\n");
      }
    }
  }

}

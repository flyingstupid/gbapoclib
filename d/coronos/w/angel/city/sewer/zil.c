/* RATWERE. Angel Sept 1993 */
int max_rats;

#define PATH	"d/coronos/w/angel/city/sewer/"

#include <mudlib.h>
inherit MONSTER;

object dagger;
object ring;
reset(arg) {
  max_rats = 0;
  ::reset(arg);
  if(arg) return;

  set_name("zilanthiuz");
  set_race("elf");
  set_alias("ratwere");
  set_alt_name("lycanthrope");
  set_gender(1);
  set_level(10);
  set_short("Zilanthiuz, the ratwere");
  set_long(
  "With long nimbles fingers, the dexterity of an elf, and the strength \n"+
  "of a lycanthrope, Zilanthiuz is a master of stealth and death. He is \n"+
  "am outcast thief who preys upon those young thieves who enter and    \n"+
  "become lost within the tunnels beneath the city.\n");
  add_spell_immune("charm");
  add_spell_immune("disease");
  set_hp(400);
  load_spells(30, ({ "miss", "acd" }));
  load_chat(10, ({ "Zilanthiuz looks at you with evil intent.\n",
     "Zilanthiuz sharpens his daggers.\n",
     "Zilanthiuz scratches his cheek.\n",
     "Zilanthiuz thinks carefully.\n",
     "Zilanthiuz looks about for more rats to call to his side.\n",
     "Zilanthiuz grins evily.\n"
  }));

  load_a_chat(10, ({ "Zilanthiuz snarls.\n",
     "Zilanthiuz spits at you.\n",
     "Zilanthiuz says: I will kill you.\n",
     "Zilanthiuz says: How dare you attack me!\n"
  }));

  load_l_chat(10, "elf", ({ "leave now before I kill you",
     "I warn you...I will slay you my friend",
     "Begone from this place...this is your last warning..."
  }));

  dagger = clone_object("inherit/weapon");
  dagger -> set_name("dagger");
  dagger -> set_wc(8);
  dagger -> set_type("slash");
  dagger -> set_length(15);
  dagger -> set_weight(4);
  dagger -> set_value(275);
  dagger -> set_short("A steel dagger");
  dagger -> set_long(
     "This is a simple dagger of reasonable quality.\n");
  move_object(dagger, this_object());

  dagger = clone_object("inherit/weapon");
  dagger -> set_name("dagger");
  dagger -> set_wc(8);
  dagger -> set_weight(4);
  dagger -> set_length(15);
  dagger -> set_type("slash");
  dagger -> set_value(275);
  dagger -> set_short("A steel dagger");
  dagger -> set_long(
     "This is a simple dagger of reasonable quality.\n");
  move_object(dagger, this_object());

  ring = clone_object("inherit/armour");
  ring -> set_ac(1);
  ring -> set_weight(1);
  ring -> set_value(300);
  ring -> set_armour_material("gold");
  ring -> set_name("ring");
  ring -> set_type("ring");
  ring -> set_short("A plain gold ring");
  ring -> set_long(
     "A simple golden ring. It bears a small wizard-mark"+
     " that resembles a 'Z'.\n");
  move_object(ring,this_object());

  init_command("wield dagger");
  init_command("wield dagger 2 in left hand");
  init_command("wear ring");
  set_wc(14);
  set_ac(9);

  set_heart_ob(this_object());
  set_dead_ob(this_object());
}

monster_heart_beat() {
  int i;
 /* changed to reduce how often rats are produced, Kingbilly */
  if(max_rats < 8)
  if(!present("rat", environment(this_object())) && hp < 75) {
    say("Zilanthiuz calls more rats to his side!\n");
    i = 0;
    while(i < 5) {
      max_rats ++;
	move_object(clone_object(PATH+"nastyrat"), this_object());
      i++;
    }
  }
}

monster_died() {
  object corpse;
  corpse = present("corpse", environment());

  write("Zilanthiuz snears at you.\n"+
        "Zilanthiuz says: You have only won this fight...\n");
  say("Zilanthiuz begins chanting in an ancient language.\n"+
      "Zilanthiuz vanishes with a pop!\n");
  if(corpse)
    destruct(corpse);
}

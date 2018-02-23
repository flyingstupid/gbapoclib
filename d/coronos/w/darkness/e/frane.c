/* F'rane is the most powerfull of all three elves. */

#include <mudlib.h>
#define BSTAB      (int)this_player()->query_backstab()
#define THISROOM   (string)this_player()->query_current_room()
#define DIFF       (int)1+random(50)
inherit MONSTER;

void reset(status arg) {
  int RANDOM;  

  if (arg) return;  
 
  ::reset(arg);
  set_name("f'rane");
  set_short("F'rane, Elven Bladesinger.");
  set_long(
    "This elf is quite tall for a High Elf.  His most unique feature is his\n"+
    "very uncommon reddish hair.  His mane of dark red hair falls down to his\n"+
    "waist in a simple ponytail.  His high cheekbones and fearless green eyes\n"+
    "add to this elf's appeal.  Strength and agility can be assumed of this\n"+
    "well built warrior.  A tattoo of a Lynx adorns his left arm, and a few \n"+
    "pouches are strapped to his waste.  His elegant sword gleams in the light.\n");
  set_extra_info(
    "F'rane is an Elvin Bladesinger from a far off land.  Bladesingers are\n"+
    "one-elf armies, diplomats for their race & city, and protectors of all\n"+
    "good elves.  He sits in the high council of the Lynx Guild, the Elven\n"+
    "Bladesinger guild that specializes in the use of the Longsword.\n");
  load_chat(1, ( {
    "F'rane smiles and nods at you.\n",
    "F'rane keeps a watchfull eye out for trouble.\n",
    "F'rane watches you closely.\n",
    }));
  load_a_chat(40, ( {
    "F'rane dances to an unheard song as he slashes\n"+
    "and swimgs, singing with his blade.\n",
    "F'rane is obviously a master swordsman.\n",
    "F'rane gracefully dodges the attack and then counters.\n"
    "F'rane skips back, then lunges fiercly!\n",
    }));
  load_l_chat(2,"elf", ({ 
    "Hello there fellow elf.\n",
    "Good day to you.\n",
    }));

  load_spells(28, ({
    "fire ball", "lightning bolt", 
    "acid arrow", "magic missile",
    }));  
 
  set_al(150);
  set_level(40);
  set_gender(1);
  set_race("elf");
  add_class("fighter");
  add_class("mage");
  set_max_hp(2000);
  set_hp(2000);
  set_wc(30);
  set_ac(17);
  set_combat(41);
  set_dexterity(45);
  set_intelligence(41); 
  set_two_weapon(0);
  set_multi_attack(60);
  set_evocation(50);
  set_magic_resist(50); 
  add_spell_immunity("charm");
  set_money(1800+random(200)); 
  set_heart_ob(this_object());

  /* The first sword is unique.  From then on, "generic" ones
     are cloned. */
  RANDOM = random(9) + 1;
  if(RANDOM==1) {
    move_object(clone_object(
    "d/coronos/w/darkness/e/firesign.c"), this_object());  
  }

  if(!present("longsword")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/e/lsword2.c"),this_object());
  }
  
}



void monster_heart_beat()  {
  object sword_ob; 
  
  if(query_attack()) {
    if(present("sword", environment(this_object()))) {
      tell_room(environment(),
        "F'rane motions with his hand and makes a few gestures with his hands.\n");
      sword_ob = present("sword", environment(this_object()));
      sword_ob -> dispel_magic();
    }
  } 
}



void catch_tell(string str) {
  return;
}



void init() {
  ::init();
  add_action("steal1", "steal");
  add_action("bstab1", "backstab");
}



/* Doesn't allow you to steal anything from F'rane because he's always keeping
   an eye out for trouble.  Stat-wise, stealing a Unique item isn't fair. */

status steal1(string str) {
  string tmp1, tmp2;

  if(sscanf(str, "%ssliph%s", tmp1, tmp2)) { 
    write("F'rane's keen eyes catch you just as you make your move.\n"+
          "He kicks you hard, digging his pointed boot into your chest.\n");
    say(this_player()->query_name()+" attempts to pick F'rane's pockets.\n"+
        "F'rane gives "+this_player()->query_name()+" a good kick to the chest.\n",
        this_player());
    say("F'rane shouts: Bandits!\n");
    this_player()->hit_player(random(20)+5);
    this_object()->add_secondary_attacker(this_player());
    return 1;
  }
  else { return 0; }
}



/* Makes Backstab VERY hard. */

status bstab1(string str) {
  string tmp1, tmp2;
  int CHANCE;
    
  if(sscanf(str, "%sf'rane%s", tmp1, tmp2)) {

    CHANCE = 0;
    if(BSTAB<55) { CHANCE = 2;}
    if(BSTAB>54) { CHANCE = 6;}

    if(CHANCE=0) {
      write("You can't do that!");
      }

    if(CHANCE>DIFF) {
      write("You sneak up on F'rane...\n"+
            "You surprised F'rane!\n"+
            "Your weapon pierces F'rane's armour.\n");
      say(this_player()->query_name()+" sneaks up on F'rane..."+
          this_player()->query_name()+" surprises F'rane!\n");
      this_object()->hit_object(random(300)+300);
      say("F'rane yells loudly and begins to attack!\n");
      this_object()->add_secondary_attacker(this_player());
      this_player()->add_secondary_attacker(this_object());
      }
 
    if(CHANCE<DIFF) {
      write("You sneak up on F'rane...\n"+
            "F'rane sees you coming and dodges the attack!\n"+
            "You missed F'rane.\n");
      say("You see "+this_player()->query_name()+" sneaking up on F'rane.\n"+
          this_player()->query_name()+" missed F'rane.\n", this_player());
      say("F'rane screams in anger and begins to attack.\n");
      this_object()->add_secondary_attacker(this_player());
      this_player()->add_secondary_attacker(this_object());
      }
  return 1;
  }

  else { return 0; }
}


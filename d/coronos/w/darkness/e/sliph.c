/* Sliph is an elvin ranger from Scanthian.  She belongs with the Candon and F'rane.
   She has the Ivory Bow. 
   Darkness --    */

#include <mudlib.h>
#define BSTAB      (int)this_player()->query_backstab()
#define THISROOM   (string)this_player()->query_current_room()
#define DIFF       (int)1+random(50)
inherit MONSTER;
int RANDOM;

void reset(status arg) {
  if (arg) {
  return;  
  }
 
  ::reset(arg);
  set_name("sliph");
  set_short("Sliph, of Scanthian.");
  set_long(
    "This gentle looking wood elf has long black hair, pulled back tight in a\n"+
    "ponytail.  She wears a simple, silver circlet upon her forehead just above\n"+
    "her brow.  Her clothes are of elven make, from her high boots to her short\n"+
    "skirt to her light cloak, draped over her shoulders.  Her demeanor is weak\n"+
    "and fragile, but by her bow and cunning in her light green eyes, one can \n"+
    "tell that there is strength in this elf.\n");
  set_extra_info(
    "Sliph is a wood elf from Scanthain.  She is verp adept with a bow, and is\n"+
    "one of the few elves ambitous enough to venture out of Scanthian.  Taking\n"+
    "pride in her duty to protect Candon on his visit to Ille Coronos, she is\n"+
    "very watchfull of those around her party.\n");
  load_chat(2, ( {
    "Sliph keeps a watchfull eye out for any trouble.\n",
    "Sliph inspects her long bow.\n",
    "Sliph adjusts her cloak.\n",
    }));
  load_a_chat(40, ( {
    "Sliph's green eyes flare with rage.\n",
    "Sliph masterfully uses her bow.\n",
    "Sliph dodges the attack, and returns fire with her bow.\n"
    "Sliph says a silent prayer.\n",
    "Sliph dances back from the attack.\n",
    "Sliph swiftly sidesteps and launches her attack.\n",
    }));
  load_l_chat(2,"elf", ({ 
    "Hello there.\n",
    "I'm so excited to be in such a big city!.\n",
    "Good day to you.\n",
    }));

  load_spells(25, ({
    "scare", "monster summon 1",
    "call lightning", "fire storm", 
    }));  
 
  set_al(200);
  set_level(28);
  set_gender(2);
  set_race("elf");
  add_class("ranger");
  set_max_hp(2000);
  set_hp(2000);
  set_wc(30);
  set_ac(17);
  set_intelligence(30); 
  set_multi_attack(25);
  set_bowyer(30);
  set_nature_sphere(18);
  set_conjuration(18);
  set_charm(18);
  set_magic_resist(50); 
  add_spell_immunity("charm");
  set_money(2800+random(200));
  set_heart_ob(this_object());

  if(!present("cloak")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/e/cloak"),this_object());
    command("wear cloak");
  }
  if(!present("leather")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/e/leather"),this_object());
    command("wear armour");
  }
  if(!present("quiver")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/e/iquiver"),this_object());
  }

  /* The First Ivory Bow is unique.  From then on, "generic" ones
     are cloned. */
  RANDOM = random(9) + 1;
  if(RANDOM==1) {
    move_object(clone_object(
    "d/coronos/w/darkness/e/ibow.c"), this_object());  
    command("wield bow");
  }

  if(!present("Bow")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/e/ibow2.c"),this_object());
    command("wield bow");
  }
  
}



void catch_tell(string str) {
  return;
}



void monster_heart_beat()  {
  object frane_ob; 
 
  if(query_attack()) {
    if(frane_ob = present("f'rane", environment())) {
      if(frane_ob -> query_attack() != query_attack()) {
        frane_ob -> add_secondary_attacker(query_attack());
        query_attack() -> add_secondary_attacker(frane_ob);
        tell_room(environment(),
          "The Bladesinger's eyes flare with rage as his companion is attacked.\n"+
          "F'rane immediately joins the fight.\n");
      }
    }
  }
}



void init() {
  ::init();
  add_action("steal1", "steal");
  add_action("bstab1", "backstab");
}


/* Doesn't allow you to steal anything from Sliph because she's always keeping
   an eye out for trouble.  Stat-wise, stealing a Unique item isn't fair. */

status steal1(string str) {
  string tmp1, tmp2;

  if(sscanf(str, "%ssliph%s", tmp1, tmp2)) { 
    write("Sliph's keen eyes catch you just as you make your move.\n"+
          "She kicks you hard, digging her pointed boot into your chest.\n");
    say(this_player()->query_name()+" attempts to pick Sliph's pockets.\n"+
        "Sliph gives "+this_player()->query_name()+" a good kick to the chest.\n",
        this_player());
    say("Sliph shouts: Thief!\n");
    this_player()->hit_player(random(20)+5);
    this_object()->add_secondary_attacker(this_player());
    return 1;
  }
  else { return 0; }
}


/* Makes Backstab VERY hard since she's got a keen eye out for trouble.
   Of the three, she's the hardest to backstab. */

status bstab1(string str) {
  string tmp1, tmp2;
  int CHANCE;
    
  if(sscanf(str, "%ssliph%s", tmp1, tmp2)) {

    CHANCE = 0;
    if(BSTAB<55) { CHANCE = 2;}
    if(BSTAB>54) { CHANCE = 6;}

    if(BSTAB==0) {
      write("You can't do that!");
      }

    if(CHANCE>DIFF) {
      write("You sneak up on Sliph...\n"+
            "You surprised Sliph!\n"+
            "Your weapon pierces Sliph's armour.\n");
      say(this_player()->query_name()+" sneaks up on Sliph..."+
          this_player()->query_name()+" surprises Sliph!\n");
      this_object()->hit_object(random(300)+300);
      say("Sliph screams in pain and begins a fierce attack.\n");
      this_object()->add_secondary_attacker(this_player());
      this_player()->add_secondary_attacker(this_object());
      }
 
    if(CHANCE<DIFF) {
      write("You sneak up on Sliph...\n"+
            "Sliph sees you coming and dodges the attack!\n"+
            "You missed Sliph.\n");
      say("You see "+this_player()->query_name()+" sneaking up on Sliph.\n"+
          this_player()->query_name()+" missed Sliph.\n", this_player());
      say("Sliph screams in anger and begins to attack.\n");
      this_object()->add_secondary_attacker(this_player());
      this_player()->add_secondary_attacker(this_object());
      }
  return 1;
  }

  else { return 0; }
}

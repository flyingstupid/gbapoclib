/* Candon is an elvin ranger from Scanthian.  He belongs with the Sliph and F'rane.
   Hee has a +1 Dagger and a +1 short sword =-= Darkness 97*/

#include <mudlib.h>
#define BSTAB      (int)this_player()->query_backstab()
#define THISROOM   (string)this_player()->query_current_room()
#define DIFF       (int)1+random(50)
inherit MONSTER;
object sword, dagger; 

void reset(status arg) {
  if (arg) {
  return;  
  }
 
  ::reset(arg);
  set_name("candon");
  set_short("Candon, of Scanthian.");
  set_long(
    "This wood elf has long dark hair that is well groomed.  His clothes are\n"+
    "of traditional elven make.  It is obvious that being a ranger is in his\n"+
    "blood by his sylvan demeanor.  With a sword and dagger at his sides, he\n"+
    "looks to be a very formidable opponent in combat.\n");
  set_extra_info(
    "Candon is the wood elf intermediate between Ille Coronos and Scanthian.\n"+
    "He is one of a few that can speak Common, thus is a sort of diplomat\n"+
    "for Scanthian.\n");
  load_chat(2, ( {
    "Candon says: Welcome friend!  How are you?\n",
    "Candon says: I have come to present F'rane to the Circle.\n",
    "Candon says: I enjoy practicing speaking Common during my visits.\n",
    "Candon smiles at you.\n",
    }));
  load_a_chat(40, ( {
    "Candon uses his weapons amazingly well.\n",
    "Candon snarls: How dare you attack!\n",
    "Candon easily dodges your attack.\n",
    "Candon screams an elfin battlecry.\n",
    }));
  load_l_chat(1,"elf", ({ 
    "I wish Sliph wouldn't worry so much about being attacked here.\n",
    "Hello there.\n",
    }));
  load_spells(30, ({
    "monster summon 2", "monster summon 3",
    "shooting stars", "comet", "bark skin",
    }));  
 
  set_level(22);
  add_class("ranger");
  set_multi_attack(30);
  set_multi_opponent(25);
  set_two_weapon(40);
  set_nature_sphere(18);
  set_conjuration(18);
  set_charm(18);
  set_al(240);
  set_gender(1);
  set_race("elf");
  set_max_hp(1500);
  set_hp(1500);
  set_wc(30);
  set_ac(17);
  set_intelligence(26);
  set_magic_resist(25);
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

  /* The first sword is unique.  From then on, "generic" ones
     are cloned. */
  if(!sword) {
    sword = clone_object("d/coronos/w/darkness/e/ssword.c");
    move_object(sword, this_object());  
  }

  if(!present("Shortsword")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/e/ssword2.c"),this_object());
  }


  /* The first dagger is unique.  From then on, "generic" ones
     are cloned. */
  if(!dagger) {
    dagger = clone_object("d/coronos/w/darkness/e/dagger.c");
    move_object(dagger, this_object());  
  }

  if(!present("Dagger")) {
    move_object(clone_object(
    "/d/coronos/w/darkness/e/dagger2.c"),this_object());
  }

  init_command("wield sword");
  init_command("wield dagger in left hand");

}

/* Candon calls Sliph and/or F'rane to fight with him if he in attacked */

void monster_heart_beat()  {
  object sliph_ob, frane_ob; 
 
  if(query_attack()) {
    if(sliph_ob = present("sliph", environment())) {
      if(sliph_ob -> query_attack() != query_attack()) {
        sliph_ob -> add_secondary_attacker(query_attack());
        query_attack() -> add_secondary_attacker(sliph_ob);
        tell_room(environment(),
                "\nCandon calls for Sliph, and she comes to his side.\n"+
                "Sliph immediately joins the fight.\n");
      }
    }

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


/* Doesn't allow you to steal anything from Candon because. Stat-wise, 
   stealing a Unique item isn't fair. */

status steal1(string str) {
  string tmp1, tmp2;

  if(sscanf(str, "%ssliph%s", tmp1, tmp2)) { 
    write("Candon's quick reflexes act with a backhand to your face.\n"+
          "Your attempt to steal from Candon failed.\n");
    say(this_player()->query_name()+" attempts to pick Candon's pockets.\n"+
        "Candon gives "+this_player()->query_name()+" a backhand to the face.\n",
        this_player());
    say("Candon shouts: Thief!\n");
    this_player()->hit_player(random(20)+5);
    /* Player must 'kill candon' to fight back */
    this_object()->add_secondary_attacker(this_player());
    return 1;
  }
  else { return 0; }
}


/* Makes Backstab VERY hard  */

status bstab1(string str) {
  string tmp1, tmp2;
  int CHANCE;
    
  if(sscanf(str, "%scandon%s", tmp1, tmp2)) {

    CHANCE = 0;
    if(BSTAB<55) { CHANCE = 3;}
    if(BSTAB>54) { CHANCE = 7;}

    if(CHANCE=0) {
      write("You can't do that!");
      }

    if(CHANCE>DIFF) {
      write("You sneak up on Candon...\n"+
            "You surprised Candon!\n"+
            "Your weapon pierces Candon's armour.\n");
      say(this_player()->query_name()+" sneaks up on Candon..."+
          this_player()->query_name()+" surprises Candon!\n");
      this_object()->hit_object(random(300)+300);
      say("Candon screams in pain and begins to attack.\n");
      this_object()->add_secondary_attacker(this_player());
      this_player()->add_secondary_attacker(this_object());
      }
 
    if(CHANCE<DIFF) {
      write("You sneak up on Candon...\n"+
            "Candon sees you coming and dodges the attack!\n"+
            "You missed Candon.\n");
      say("You see "+this_player()->query_name()+" sneaking up on Candon.\n"+
          this_player()->query_name()+" missed Candon.\n", this_player());
      say("Candon growls in anger and begins to attack.\n");
      this_object()->add_secondary_attacker(this_player());
      this_player()->add_secondary_attacker(this_object());
      }
  return 1;
  }

  else { return 0; }
}

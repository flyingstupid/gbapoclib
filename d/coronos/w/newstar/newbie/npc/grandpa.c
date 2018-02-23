/* grandpa.c -- Newbie*/
/* Darkness and Newstar */

#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("Grandpa Newman");
  set_alias("grandpa");
  set_short("Grandpa Newman");
  set_long(
    "This is Grandpa Newman, the elder of the family.  He is a kindly, old\n"+
    "man with a venerable air about him.  He has laughing, grey eyes and a\n"+
    "knowing smile.  He has seen many things in his years that have given\n"+
    "him the wisdom of experience.  He is still clear of mind, with cunning\n"+
    "wit and though he has a slight limp, he still stands tall and strong.\n");
  load_chat(5, ({
    "Grandpa Newman clears his throat.\n",
    "Grandpa Newman smiles kindly with twinkling eyes.\n",
    "Grandpa Newman carefully adjusts his collar.\n",
    "Grandpa Newman winks warmly at you.\n",
    "Grandpa Newman chuckles softly to himself.\n",
    }));
 
  load_a_chat(40, ({
    "Grandpa Newman mutters oaths, shaking his fist at you.\n",
    "Grandpa Newman gives you all hes got.\n",
    "Grandpa Newman shouts, 'Be gone, vile betrayer!'\n",
    "Grandpa Newman sends a quick prayer to the All-god.\n",
    "Grandpa Newman yells, 'You'll pay for this evil deed, traitor!'\n",
    }));
 
  set_al(225);
  set_level(3);
  add_class("fighter");
  set_wc(7);
  set_ac(4);
  set_hp(50 + random(20));
  set_gender(1);
  set_money(50 +random(10));
  set_race("human");
 
if (!present("wooden cane")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/cane"),
    this_object());
    command("wield cane");
  }
}


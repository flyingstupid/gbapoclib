/* SAL.C */
/* Author:DarkBringer */
/* 04-24-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  if(!present("sword")) {
       move_object(clone_object("/d/coronos/w/nightbringer/manor/weapon/rapier.c"),this_object());
    init_command("wield sword");
    }

  if(!present("armour")) {
       move_object(clone_object("/d/coronos/w/nightbringer/manor/armour/bandmail.c"),this_object());
    init_command("wear armour");
    }


  set_short("Sal");
  set_name("sal");
  set_race("human");
  set_long(
"    Sal is a captain in the Ille Coronus Navy. He has served loyally\n"+
"    for the last 12 years and has thus earned a great deal of respect\n"+
"    from the citizens of Ille Coronos, particularly, Lord Penor, whose\n"+
"    enourmous business holding he has protected. Sal is a massive man,\n"+
"    standing nearly seven feet tall and weighing close to 300 pounds.\n"+
"    There's not an ounce of fat on his body, just solid muscles. Sal \n"+
"    to engage others in trials of strength such as wresteling. He has\n"+
"    wavy black hair and blue eyes. Sal is considered to be a dashing\n"+
"    fellow and quite the catch to the woemen folk Of Ille Coronos. He\n"+
"    is wearing a splendid suit of banded mail armour and wears a thin\n"+
"    sword at his side\n");

 

  set_gender(1);
  set_level(23);
  set_ac(17);
  set_wc(30);

  add_money(2000 + random(1000));
  add_class("fighter");
  add_class("mage");
  
  load_spells(30,({
   "magic missile", "acid arrow", "pws", "fireball", "shield",
   "chain lightning", }));

  load_chat(5, ({"Sal says: Hello there land lubber.\n",
    "Sal asks: Voices from the cellar, can you believe that?\n",
    " Sal says: He keeps saying he hears voices at night.\n",
    }));

  load_a_chat(5,({"Sal says: Let's get it on.\n",
    "Sal laughs in your face.\n",
    }));


  }

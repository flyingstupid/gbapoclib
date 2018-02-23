/* Duchess Rochester*/
/* Author:DarkBringer */
/* 04-26-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  if(!present("mace")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/weapon/mace2.c"),this_object());
    init_command("wield mace");
    }

  if(!present("armour")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/armour/brobe.c"),this_object());
    init_command("wear cloak");
    }


  set_short("duchess rochester");
  set_name("duchess rochester");
  set_alias("duchess");
  set_race("human");
  set_long(
"Duchess Rochester is a plump, middle aged woman. She is a greedy\n"+
"backstabbing type. She has short, greying hair that she wears in a\n"+
"tight bun.\n");

  set_gender(2);
  set_level(32);
  set_ac(17);
  set_wc(30);
  set_al(-500);

  add_money(3000 + random(2000));
  add_class("mage");
  add_class("cleric");

  load_spells(40,({ "heal", "hurt", "fireball", "acid arrow", }));

  load_chat(5, ({"Duchess says: My husband is so cheap.\n",
"Duchess says: When he dies, it'll all be mine.\n",

    }));

  load_a_chat(5,({"Duchess says: Oh,no..I'll not die before he does!\n",
    }));


  }

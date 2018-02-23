/* Duke Rochester*/
/* Author:DarkBringer */
/* 04-26-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  if(!present("sword")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/weapon/lsword1.c"),this_object());
    init_command("wield sword");
    }

  if(!present("armour")) {

move_object(clone_object("d/coronos/w/nightbringer/manor/armour/banded1.c"),this_object());
    init_command("wear armour");
    }


  set_short("Duke Rochester");
  set_name("duke rochester");
  set_alias("rochester");
  set_race("human");
  set_long(
"Duke Rochester is a prominent member of the Ille Coronos community.\n"+
"He and his family often take advantage of the Penors good nature and\n"+
"stay at the Manor. He is a shifty man who is always looking out for\n"+
"himself.\n");

  set_gender(1);
  set_level(32);
  set_ac(17);
  set_wc(30);
  set_al(-500);

  add_money(3000 + random(2000));
add_class("fighter");
  add_class("cleric");

  load_spells(40,({ "heal", "hurt", "bless", "curse", "earthquake", }));

  load_chat(5, ({"Rochester says: This way I don't have to spend my money.\n",
"Rochester says: Maybe the hauntings will drive the Penors out!\n",
"Rochester says: Then I could buy this place dirt cheap and make a\n"+
"profit\n",

    }));

  load_a_chat(5,({"Rochester smiles slyly at you.\n",
    }));


  }

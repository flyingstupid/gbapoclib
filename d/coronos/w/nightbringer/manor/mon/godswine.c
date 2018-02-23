/* Sir Walter Godswine*/
/* Author:DarkBringer */
/* 04-26-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  if(!present("sword")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/weapon/lsword.c"),this_object());
    init_command("wield sword");
    }

  if(!present("armour")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/armour/plate.c"),this_object());
    init_command("wear armour");
    }

  if(!present("shield")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/armour/lshield.c"),this_object());
    init_command("wear shield");
    }

  set_short("sir walter godswine");
  set_name("sir walter godswine");
  set_alias("godswine");
  set_race("human");
  set_long(
" Sir Walter Godswine is a prominent member of the All-God church. He\n"+
" is a Paladine and serves the church without a fault. He is a powerful\n"+
" human male of about 35 years of age. He has long flaxen hair and a\n"+
" thick handlebar mustaches and a goatte. \n");

  set_gender(1);
  set_level(28);
  set_ac(17);
  set_wc(30);
  set_al(1000);

  add_money(3000 + random(2000));
add_class("paladin");

  load_spells(40,({ "heal", "hurt", "bless", "curse", "earthquake", }));

  load_chat(5, ({"Godswine says: The Penors are such nice people.\n",
"Godswine says: I personally haven't heard the noises.\n",
    }));

  load_a_chat(5,({"Godswine shakes his head sadly\n",
    }));

}
  

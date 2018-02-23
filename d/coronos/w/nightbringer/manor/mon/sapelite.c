/* MAGUS SAPELITE*/
/* Author:DarkBringer */
/* 04-26-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  if(!present("robe")) {
       move_object(clone_object("/d/coronos/w/nightbringer/manor/armour/brobe.c"),this_object());
    init_command("wear robes");
    }

  set_short("Magus Sapelite");
  set_name("magus sapelite");
  set_alias("sapelite");
  set_race("dark elf");
  set_long(
"Magus Sapelite is a evil twisted dark elf. He is cruel and mean and\n"+
"immensley enjoys the sufferings of others. He stands five feet tall,\n"+
"long flowing silver hair, but it is his eyes that draws the attention\n"+
"of others as they are as black as the robes that he wears.\n");

  set_gender(1);
  set_level(30);
  set_ac(30);
  set_wc(17);
  set_al(-1000);

  add_money(700 + random(300));
  add_class("mage");

  load_spells(40,({ "fireball", "lb", "acid arrow",
     "magic missile", "meteor swarm", "coc", }));

  load_chat(5, ({"Magus says: I think the hauntings are funny.\n",
"Mages says: Serves the holly rollers right.\n",
    }));

  load_a_chat(5,({"Magus cackles evily.\n",
"Magus laughs at you.\n"
    }));


  }

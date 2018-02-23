/*HERMAN.C */
/* Author:DarkBringer */
/* 04-24-97 */


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

move_object(clone_object("d/coronos/w/nightbringer/manor/armour/herchain.c"),this_object());
    init_command("wear armour");
    }


  set_short("herman");
  set_name("herman");
  set_race("high elf");
  set_long(
"    Herman is an afluent elvin noble. He stands about five and a half\n"+
"    feet tall, but his regal bearing makes him appear to people as \n"+
"    much taller than that. He has long flaxen blonde hair, and brown\n"+
"    almond shaped eyes. He is wearing a extremely nice looking set of\n"+
"    chain mail armour, that bears the creast of the D'ghoe family. He\n"+
"    wears a longsword at his side with practiced ease.\n");


  set_gender(1);
  set_level(20);
  set_ac(17);
  set_wc(30);
  add_class("fighter");


  add_money(2000 + random(1000));

  load_chat(5, ({"Herman says: I think the game is crooked.\n",
    "Herman says: I think Lord Penors' getting senile.\n",
    " Herman says: He keeps talking about noises coming from the cellar?\n",
    }));

  load_a_chat(5,({"Heram says: You fool, I will slay you.\n",
    "Herman screams with rage.\n",
    }));


  }

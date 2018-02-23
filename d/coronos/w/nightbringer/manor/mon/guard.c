/* GUARD */
/* Author:NightBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {
  ::reset(arg);


  if(!present("sword")) {
       move_object(clone_object("d/coronos/w/nightbringer/manor/weapon/lsword.c"),this_object());
    init_command("wield sword");
    }

  if(!present("armour")) {

move_object(clone_object("d/coronos/w/nightbringer/manor/armour/bandmail.c"),this_object());
    init_command("wear armour");
    }
if(arg) return;


  set_short("guard");
  set_name("guard");
  set_alias("guard");
  set_race("human");
  set_long(
"A guard of the Penor Manor, he looks very alert and competent in his job\n"+
"probably due to the high level of training he has received from his\n"+
"captain. He is wearing the standerd issue of banded mail armour and wields\n"+
"a longsword with practiced ease.\n");


  set_gender(1);
  set_level(15 + random(10));
  set_ac(16);
  set_wc(20);
  add_money(1000 + random(600));
  add_class("fighter");

  load_chat(5, ({"Guard says: I'm looking for the source of the noises.\n",
    "Guard says: Frankly, I think the Penors' are off their rockers.\n",
    }));

  load_a_chat(5,({"Guard say: The captain will hear of this.\n",
    "Guard says: Stop! Or i'll report you.\n",
    "Guard says: Hey you can't attack a  guard...it's against the law!\n",
    }));


  }

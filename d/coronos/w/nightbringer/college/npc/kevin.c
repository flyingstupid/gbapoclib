/* KEVIN.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Kevin Stoney");
  set_name("kevin");
  set_race("elf");
  set_long(
"Kevin is a burned out long hair who is at the Univeristy studying\n"+
"the Clerical arts as a final chance by his father. If he washes\n"+
"out of this school, his father will force him to join the Ille \n"+
"Coronos Navy.\n");

  set_gender(1);
  set_level(8);
  set_ac(7);
  set_wc(12);
  add_money(300 + random(50));
  set_hp(130);
  set_max_hp(130);
  set_al(50);
  add_class("cleric");
  load_spells(20,({ "cure light wounds", "bless", "curse", "prayer",
  }));


  load_chat(5, ({"Kevin says: Hey, dude....let's party.\n",
    "Kevin says: Wanna party.\n",
    "Kevin laughs at something that only he can see.\n",
    }));

  load_a_chat(5,({"Kevin says: Bummer, dude.\n",
    "Kevin says: Make love, not war.\n",

    }));


  }

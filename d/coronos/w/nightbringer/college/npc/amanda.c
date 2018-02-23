/* AMANDA.C
   Author:DarkBringer
   05-04-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Amanda Lynn");
  set_name("amanda");
  set_race("human");
  set_long(
"Amanda is a teen-aged human girl. She is tall and wants to be a \n"+
"grown-up more than anything. She is here to learn the arts of magic,\n"+
"but doesn't take her studies very seriously. She spends too much time.\n"+
"dreaming of marrying Gavin, who lives upstairs.\n");

  set_gender(2);
  set_level(10);
  set_ac(8);
  set_wc(14);
  add_money(600 + random(100));
  set_hp(175);
  set_max_hp(175);
  set_al(0);
  add_class("mage");
  load_spells(20,({ "acid arrow", "magic missile", "chill touch" }));



  load_chat(5, ({"Amanda says: I love Gavin.\n",
    "Amanda says: Gavin loves me.\n",
    "Amanda says: We are gonna be a happy family.\n",
    }));

  load_a_chat(5,({"Amanda says: Gavin, help me.\n",
    "Amanda says: Gavin will get you for this!\n",

    }));


  }

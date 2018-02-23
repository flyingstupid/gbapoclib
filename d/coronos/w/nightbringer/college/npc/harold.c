/* HAROLD.C 
   Author:DarkBringer 
   05-30-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("Harold Holis");
  set_name("harold");
  set_race("gnome");
  set_long(
"Harold Holis strongly resembles a small, thin dwarf, with the \n"+
"exception of two notable facial features: his beard is is short\n"+
"and stylishly trim, and his enourmous nose, which is nearly twice\n"+
"the size of any dwarfs. Harold refuses to recognize the fact that\n"+
"Gnomes and Dwarfs are cousins, refusing to believe that a race of\n"+
"intellectual inferiors could be relatives.\n");

  set_gender(1);
  set_level(4);
  set_ac(4);
  set_wc(8);
  add_money(100 + random(50));
  set_hp(70);
  set_max_hp(70);
  set_al(100);
  add_class("mage");
  load_spells(20,({ "magic missile", "bbb", }));



  load_chat(5, ({"Harold says: Dwarves are such stupid animals.\n",
    "Harold says: Gnomes ARE NOT related to Dwarves.\n",
    "Harold snorts with contempt.\n",
    }));

  load_a_chat(5,({"Harold sighs sadly.\n",
    "Harold says: Now how did that spell go....\n",

    }));


  }

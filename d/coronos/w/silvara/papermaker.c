#include <mudlib.h>
inherit MONSTER;


void reset(status arg) {
   if (arg) {
    return;
}

::reset(arg);
set_name("Gilthea");
set_alt_name("papermaker");
set_short("Gilthea, the papermaker");
set_long(
"Gilthea, the papermaker, gazes greedily down her hawk-like nose about\n"+
"her.  Her raven hair is shot through with silver, yet her dark skin\n"+
"is as smooth as her paper.  Full, multi-coloured robes drape\n"+
"over her thin frame, and bracelets of silver jangle as she pads\n"+
"around on bare feet.  \n");

load_chat(10, ({
   "Gilthea says: The need for scrolls keeps me in business.\n",
   "Gilthea says: If ye are not a mage, ye better have plenty of coins \n"+
   "for my paper.\n",
   "Gilthea says: Magic is a power force, and it is mighty\n"+
   "profitable.\n",
}));

load_a_chat(6, ({
  "Gilthea grabs up a pile of scrools and runs for the door.\n",
  "Gilthea screams and throws paper at you.\n",
   "Gilthea asks: What will the mages do without my paper?\n",
}));

set_attack_msg(({
  "slaps", "with her strong hands",
  "scratches", "with her sharp finger nails",
  "pushes", "with all her strength",
}));

set_al(0);
set_level(18);
set_gender(2);
set_race("human");
}

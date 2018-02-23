/*****************************************************************************
 * mage.c
 * Mage class for Mage University mages
 * 
 * Pulse
 * October, 1996
 */
 
#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  ::reset(arg);
  if (arg) {
    return;
  }
  
  set_name("apprentice");
  set_alias("mage");
  set_al(200);
  set_level(10);
  set_short("A young apprentice");
  set_gender(random(2)+1);
  set_race("human");
  set_long(
    "This young apprentice has sought the ways of magic through the masters\n"+
    "at the College.\n"
  );
  
  set_wc(14);
  set_ac(9);
  add_money(200 + random(300));
  
  load_chat(10, ( {
    "Apprentice says: I'd love to talk, but I'm *really* late.\n",
    "Apprentice seems overwhelmed with work and worries.\n",
    "Apprentice furls his brow over a complex problem.\n",
    "Apprentice says: Some of these professors think they know *everything*\n",
  } ));
  
  load_a_chat(10, ( {
    "Apprentice says: You dare attack me?  The arch mage will surely\n"+
      "find out about this!\n",
    "Apprentice exclaims: I don't have time to fight!  I'm late for a lab!\n",
    "Apprentice sobs sadly.\n",
    "Apprentice screams for help!\n",
  } ));
  
  load_spells(40, ( {
    "burning hands", "monster summon 1", "shadow door" 
  }));
  
  set_magic_resist(10);
}

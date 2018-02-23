/******************************************************************************
 * rhiannon
 * Rhiannon, Mistress of Illusion
 * Mage University
 * 
 * Pulse
 * October, 1996
 */
 
#include <mudlib.h>
inherit MONSTER;
 
void init() {
  call_out("chat",1);
  ::init();
}
 
void reset(status arg) {
  if (arg) {
    return;
  }
  
  ::reset(arg);
  set_name("roc");
  
  set_short("Roc Moderne, the Infinitely Sad");
  set_long(
    "Roc Moderne is dressed completely in black, head to toe; his hair is\n"+
    "dyed black to match.  He seems to have suffered some great loss,\n"+
    "though it's questionable whether any loss could have produced the\n"+
    "wraith-like figure you see in front of you.  He is technically human,\n"+
    "but immerses himself so much in death and its related magics, that\n"+
    "he seems dead himself.\n"
  );
  
  set_al(-200);
  set_level(15);
  set_gender(1);
  set_race("human");
  add_class("mage");
  
  set_wc(15);
  set_ac(15);
  set_magic_resist(30);
 
  set_hp(1000);
  
  load_spells(30, ( {
    "animate zombie", "chill touch",
    "vampiric touch", "minor malison", "bbb", 
    "monster summon 3"
  } ));
  
  if (!present("wand")) {
    move_object(clone_object("/d/coronos/w/solstice/univ/objects/icewand"),
  	        this_object());
  }
  
  load_a_chat(15, ( {
    "Roc pulses with the power of the dead.\n",
    "Roc laughs at you.\n",
    "Roc says: Humble students should not test their professors.\n"
  } ));
  
  load_chat(15, (  {
    "Roc mopes around, mulling over his pain.\n",
    "Roc's nerves are grated by your presence.\n",
    "Roc asks: Are you in my necromancy class?\n"
  } ));
}
 

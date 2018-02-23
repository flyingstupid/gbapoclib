 
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
  set_name("rhiannon");
  
  set_short("Rhiannon, Mistress of Illusion");
  set_long(
    "Rhiannon is a shifty character, never appearing to be what she seems\n"+
    "to be.  She has a nasty propensity to appear to be in several places\n"+
    "at once, and, combined with the effects the mirrors have, she seems\n"+
    "to be everywhere at once.  She is a young elf with beauty on her side,\n"+
    "but appears well versed in the practices of illusion.  Aspiring mages\n"+
    "flock to her to learn from her experience.\n"
  );
  
  set_al(100);
  set_level(12);
  set_gender(2);
  set_race("high elf");
  add_class("mage");
  
  set_wc(12);
  set_ac(12);
  set_magic_resist(15);
 
  set_hp(300);
  
  load_spells(13, ( {
    "phantasm", "phantasmal force",
    "shadow monster", "phantasmal armour", "bbb", "fire ball",
    "monster summon 2"
  } ));
  
  if (!present("wand")) {
    move_object(clone_object("/d/coronos/w/solstice/univ/objects/icewand"),
  	        this_object());
  }
  
  load_a_chat(15, ( {
    "Rhiannon face furrows up like a volcano.\n",
    "Rhiannon eminates powerful magical energies.\n",
    "Rhiannon says: For this you will pay.\n"
  } ));
}
 
void chat() {
  if (!this_player()->query_stealth_on() && !this_player()->query_npc()) {
    tell_object(this_player(), "Rhiannon pops up out of nowhere!\n");
  }
  
  if(this_player()->query_class("mage")) {
    tell_object(this_player(), 
		"Rhiannon asks: Have you come to take illusion classes with me?\n");
  }
  else  {
    tell_object(this_player(),
		"Rhiannon ignores you and goes about her business.\n");
  }
  
}

/******************************************************************************
 * greeter.c
 * Greeter for the Mage College
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
  set_name("oshido");
  set_alias("guard");
  
  set_short("Oshido, Guard of the College");
  set_long(
    "Oshido watches over the college, making sure things are running\n"+
    "smoothly.  He has a smile for everyone he meets, but as he stands well\n"+
    "over six feet and is well built, he is capable of handling most every\n"+
    "problem that might arise.\n"
  );
  
  load_chat(5, ( {
    "Oshido says: Welcome to the College!\n",
    "Oshido says: How are classes going?\n",
    "Oshido smiles happily.\n",
    "Oshido says: Tell me if you see any problems.\n",
  }));
  
  set_al(300);
  set_level(20);
  set_gender(1);
  set_race("human");
  add_class("mage");
  add_class("fighter");
  
  set_wc(20);
  set_ac(15);
  set_magic_resist(30);
 
  load_spells(20, ( {
    "chill touch", "cone of cold", "ice storm", "shadow door",
    "phantom armor"
  } ));
  
  if (!present("wand")) {
    move_object(clone_object("/d/coronos/w/solstice/univ/objects/icewand"),
  	        this_object());
  }
  
  if (!present("sword")) {
    move_object(clone_object("/d/coronos/w/solstice/univ/objects/sword"),
  	        this_object());
    init_command("wield sword");
  }
}
 
void chat() {
  if (!this_player()->query_stealth_on() && !this_player()->query_npc()) {
    tell_object(this_player(), "Oshido bows as you arrive.\n");
    say("Oshido bows to "+this_player()->query_name()+".\n", this_player());
  }
}

/******************************************************************************
 * amani.c
 * Amani, the Relaxed
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
  set_name("amani");
  
  set_short("Amani, the Relaxed");
  set_long(
    "Amani is one charming guy.  He lounges about the room and seems to\n"+
    "know everyone who passes by his class.  Students make it a point to\n"+
    "come see him and hang around with him.  He often resolves conflicts\n"+
    "and makes it a point to be relaxed rather than ruffled by others\n"+
    "who don't necessarily hold the same views as him.  Those wishing to\n"+
    "learn how to charm others should take a tip from him; in fact, he\n"+
    "teaches the arts of charm to students.\n"
  );
  
  set_al(300);
  set_level(15);
  set_intelligence(20);
  set_gender(1);
  set_race("human");
  add_class("cleric");
  add_class("mage");
  
  set_magic_resist(30);
 
  set_hp(350);
  
  load_spells(30, ( {
    "friends", "charm monster",
    "vampiric touch", "minor malison", "bbb", 
    "monster summon 3"
  } ));
  
  load_a_chat(15, ( {
    "Amani says: Hey, we can work it out.\n",
    "Amani says: It's all good.\n",
    "Amani says: This can't be good for either of us.\n"
  } ));
  
  load_chat(10, (  {
    "Amani asks: Hey, how you doin' today?\n",
    "Amani says: Always nice to see you.\n",
    "Amani says: Relax there, guy.  We're all in it together.\n",
    "Amani whistles a tune from a really awful lounge act.\n",
    "Amani says: If you want to learn how to charm women, take it from me.\n"
  } ));
  
  move_object(clone_object("/objects/components/gem"), this_object());
}
 
 

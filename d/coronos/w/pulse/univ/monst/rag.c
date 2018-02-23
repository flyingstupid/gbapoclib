/******************************************************************************
 * rag.c
 * Rag, the Tiger
 * Mage University
 * 
 * Pulse
 * October, 1996
 */
 
#include <mudlib.h>
inherit MONSTER;
 
void reset(status arg) {
  object fang, eye;
  
  if (arg) {
    return;
  }
  
  ::reset(arg);
  set_name("rag");
  set_short("Rag");
  set_long(
    "Rag is a fierce bengal tiger, who has really long teeth and uses\n"+
    "them when he is hungry.  He looks hungry.\n");
  
  set_level(10);
  set_strength(15);
  set_gender(0);
  set_al(0);
  set_hp(175);
  set_race("bengal tiger");
  
  load_chat(5, ( {
    "Rag purrs contentedly.\n",
    "Rag mopes about the room.\n",
    "Rag switches his tail back and forth.\n"
  } ));
  
  load_a_chat(5, (  {
    "Rag pounces on you, ripping chunks of flesh out!\n",
    "Rag lets out a ferocious growl that resounds throughout the room.\n",
    "Rag bares his fangs threatingly.\n"
  } ));
  
  if(!present("fang")) {
    fang = clone_object(WEAPON);
    fang->set_name("fang");
    fang->set_short("A glittering white fang");
    fang->set_long(
      "A razor sharp fang that measures about four inches long.  This thing\n"+
      "could do some serious damage.\n"
    );
    fang->set_weight(4);
    fang->set_ac(3);
    fang->set_length(4);
    fang->set_value(400);
    move_object(fang, this_object());
  }
  
  if(!present("eye"))  {
    eye = clone_object(TREASURE);
    eye->set_name("eye");
    eye->set_short("Tiger Eye");
    eye->set_long(
      "A much sought after tiger's eye.  This would be the prize of any\n"+
      "fighter's treasure collection.\n"
    );
    eye->set_weight(1);
    eye->set_value(3000);
    move_object(eye, this_object());
  }
    
  
}
 
 
  

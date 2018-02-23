/* Malf -- Malf picks up objects laying on the ground about once every 4 minutes 
   and wanders fairly often.  He will not pick up Magic objects, Treasure, and
   Coins.  He only picks up Weapons, Armour, and Clothing. */
/* Darkness */

#include <mudlib.h>
inherit MONSTER;
 
 
void reset(status arg) {
  if (arg) {
  return;  
  }
 
  ::reset(arg);
  set_name("malf");
  set_alias("dwarf");
  set_short("Malf");
  set_long(
    "Malf is a smallish Gully Dwarf wearing layer upon layer or ragged shirts,\n"+
    "tunics, and all other sorts of clothing.  He has a rather large nose and\n"+
    "squinty brown eyes.  He carries a small bag with him in which he carries\n"+
    "around all the things that he finds on his journies.\n");

  load_chat(1, ({
    "Malf looks at you.\n",
    "Malf checks his belongings.\n",
    "Malf looks around for something worth collecting.\n",
    "Malf hums a tune as he strolls along.\n",
    })); 
 
  load_a_chat(4, ({
    "Malf: HELP!\n",
    "Malf: Help!  Someone help me!\n",
    "Malf: Help!  Guards!\n",
    "Malf tries to run away.\n",
    }));

  set_al(0);
  set_level(2);
  set_wisdom(20); /* To help him wimpy well. */
  set_wimpy(55);
  set_gender(1);
  set_race("gully dwarf");
  set_wander(50, 30);  /* 50% every 30 heartbeats */
  add_money(random(30)+30); 
  set_heart_ob(this_object());
}



void monster_heart_beat()  {
  int RANDOM;
  object OBJ1, OBJ2, OBJ3;
  string name_OBJ1, name_OBJ2, name_OBJ3;

  RANDOM = random(19) + 1; /* 1 in 20 chance */

  if(RANDOM==10) {

    if(present("clothing")) { 
      OBJ1 = present("clothing");
      name_OBJ1 = OBJ1->query_name();
    }
    if(present("armour")) { 
      OBJ2 = present("armour");
      name_OBJ2 = OBJ2->query_name();
    }
    if(present("weapon")) { 
      OBJ3 = present("weapon");
      name_OBJ3 = OBJ3->query_name();
    }
   
    if(OBJ1) {
      destruct(OBJ1);
      say("Malf puts "+name_OBJ1+" in his bag.\n");
    }
    if(OBJ2) {
      destruct(OBJ2);
      say("Malf puts "+name_OBJ2+" in his bag.\n");
    }
    if(OBJ3) {
      destruct(OBJ3);
      say("Malf puts "+name_OBJ3+" in his bag.\n");
    }
  }
}

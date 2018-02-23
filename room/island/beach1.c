#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob;

  if(!present("sand crab")) {
    ob = clone_object(MONSTER);
    ob -> set_name("sand crab");
    ob -> set_alias("crab");
    ob -> set_race("crab");
    ob -> set_short("A small sand crab");
    ob -> set_long(
          "The crab scuttles sideways as you look in its direction.  \n"+
          "Dispite its size its little nippers could cause you quite \n"+    
          "an injury, yet it does look good to eat.\n");
    ob -> set_attack_msg(({
          "nips",        "with its claws",
          "grazes",      "with its claws",
          "grabs",       "with its claws",
          "bruises",     "with its claws",
          "crunches",    "with its claws",
          "smashes",     "with its claws",
          "crushes",     "with its claws",
    }));
    ob -> set_level(1);  /* will handle all its hp/ac/wc etc */
    ob -> set_gender(2);
    ob -> load_chat(5,({ "Sand crab scuttles across the beach.\n",
          "Sand crab looks up at you with its beedy eyes.\n",
          "Sand crab digs a little hole.\n",
    }));
    ob -> load_a_chat(6,({ "Sand crab scuttles around you.\n",
          "Sand crab tries to scuttle away.\n",
          "Sand crab snaps its nippers angrily.\n",
    }));
    move_object(ob, this_object());
  }

  if(arg) return;

  set_short("Skol island");
  set_long(
     "A small jetty extends outward from the beach toward a tall sailing \n"+
     "ship, bobbing up and down with the waves that wash against its hull.\n"+
     "The beach extends far to the east and west, while a small sandy trail\n"+
     "meanders its way through many tall trees to the south.\n");
  set_weather(1, 4, 6);
  set_exits(({ 
     "room/island/jetty",  "north",
     "room/island/beach2", "east",
     "room/island/beach5", "west",
  }));
  set_listen("You hear the soothing sounds of the waves against the beach.\n");
  set_smell("Sea salt is strong in the air here.\n");
  set_items(({
     "sand",  
          "Soft, yellow sand. It feels wonderful beneath your feet",
     "beach", 
          "A small beach which extends up and down the coast of the island",
     "ship#sailing ship",
          "A tall sailing ship with white sails. Atop its \n"+
          "mast is a flag waving in the salty sea breeze    ",
     "hull",
          "The outside of the ship is covered in barnacles",
     "barnacles",
          "They cling to the hull of the ship at the jetty",
     "sails#sail",
          "They are waving slowly in the sea breeze",
     "flag",
          "The flag bears the symbol of Tempus",
     "waves#wave",
          "Strong waves crash on the beach",
     "jetty",
          "The jetty leads out to a tall sailing ship",
     "mast",
          "Atop the mast is a flag",
  }));

  set_search_array(({
     "sand#beach",
          "All you find is sand, and more sand.\n",
  }));
}


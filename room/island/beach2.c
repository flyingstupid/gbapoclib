#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("Skol island");
  set_long(
     "Far away to the north west a small jetty extends outward from the \n"+
     "beach toward a tall sailing ship. The beach you stands on extends \n"+
     "far to the east and west.\n");
  set_weather(1, 4, 6);
  set_exits(({ 
     "room/island/beach3", "east",
     "room/island/beach1", "west",
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
          "All you find is sand. Did you expect to find anything else?\n",
  }));
}


#define PATH	"/d/affils/ships/island"

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob;
  if(!present("seal")) {
    ob = clone_object(MONSTER);
    ob -> set_name("seal");
    ob -> set_race("seal");
    ob -> set_short("A grey seal");
    ob -> set_long(
          "Seals have been called the dogs of the ocean, possibly because \n"+
          "of their playfulness. This one is not protecting its young, so \n"+
          "its possibly just here to sit in the sunshine, or to find food.\n");
    ob -> set_level(3);
    ob -> load_chat(5, ({ "Seal claps its flippers.\n",
          "Seal twitches its whiskers",
          "Seal barks playfully.\n",
          "Seal barks happily.\n",
    }));
    ob -> set_gender(2);
    ob -> load_a_chat(6, ({ "Seal darts about the rocks.\n",
          "Seal tries to get away, back into the water.\n",
          "Seal barks angrily.\n",
    }));
    ob -> set_attack_msg(({
          "grazes",      "with her flippers",
          "bruises",     "with her flippers",
          "bashes",      "with her flippers",
          "gnaws",       "with her teeth",
          "bites",       "with her teeth",
          "crushes",     "with her tail flippers",
          "smashes",     "with her tail flippers",
    }));
    move_object(ob, this_object());
  }

  if(arg) return;
  set_short("Skol island");
  set_long(
     "You have come to the end of the beach along skol island. A rocky  \n"+
     "outcrop leads into the water, meeting the waves as they splash up \n"+
     "against them. A set of footprints also leads east up a steep \n"+
     "cliff face.\n");

  set_weather(1, 4, 6);
  set_exits(({ 
	PATH+"/beach3", "west",
        PATH+"/cliff1", "east",
  }));
  set_listen("You hear the soothing sounds of the waves against the rocks.\n");
  set_smell("Sea salt is strong in the air here.\n");
  set_items(({
     "sand",  
          "Soft, yellow sand. It feels wonderful beneath your feet",
     "beach", 
          "A small beach which extends up and down the coast of the island",
     "waves#wave",
          "Strong waves crash on the beach",
     "rocks#outcrop#rocky outcrop",
          "A formation of rocks, extending out into the water",
     "footprint#footprint",
          "They looks remarkably familiar",
     "water pools#pools#water",
          "A little star fish sits at the bottom",
     "star fish",
          "A small, orange star fish. It's quite beautiful to look at",
  }));

  set_search_array(({
     "sand#beach",
          "All you find is sand. Did you expect to find anything else?\n",
     "rocks#outcrop",
          "You find little star fish in water pools",
  }));
}


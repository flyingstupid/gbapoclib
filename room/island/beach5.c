#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  object ob, obj;
  int i, j;

  if(!present("turtle")) {
    for(i=0; i<(3+random(5)); i++) {
      ob = clone_object(MONSTER);
      ob -> set_name("sea turtle");
      ob -> set_race("turtle");
      ob -> set_gender(2);
      ob -> set_short("A giant sea turtle");
      ob -> set_long(
          "This huge turtle has probably come to this distant part   \n"+
          "of the beach in order to lay her eggs. She will obviously \n"+
          "protect them to the death.\n");
      ob -> set_level(5);
      ob -> load_chat(3, ({ "Sea turtle moves slowly up the beach.\n", }));
      ob -> load_a_chat(5, ({ "Sea turtle snaps angrily.\n", }));
      ob -> set_attack_msg(({
          "grazes",      "with her flippers",
          "bruises",     "with her flippers",
          "bashes",      "with her flippers",
          "bites",       "with her snapping jaws",
          "smashes",     "with her flippers",
          "smatters",    "with her snapping jaws",
          "crushes",     "as she rolls over",
      }));
      move_object(ob, this_object());

      for(j=0; j<3; j++) {
        obj = clone_object(FOOD);
        obj -> set_name("egg");
        obj -> set_short("A turtle egg");
        obj -> set_long(
          "It looks kind of green, soft and leathery. "+
          "Not really good to eat.\n");
        obj -> set_sell_destruct(1);
        obj -> set_strength(3);

        obj -> set_room_msg(  /* pretty yucky hu? */
        "@@query_name:$this_player()$@@ cracks open the shell of an egg and\n"+
        "swallows its contents whole. \n@@query_name:$this_player()$@@ "+
        "suddenly turns a pale shade of green... you wonder why?\n");

        obj -> set_consumer_msg(
        "You crack open the shell and swallow its contents.\n"+
        "You almost vomit the contents as you feel a small \n"+
        "turtle embrio wriggle down your throat.\n");

        move_object(obj, ob);
      }
    }
  } 


  if(arg) return;
  set_short("Skol island");
  set_long(
     "The sand here is very soft beneath your feet, and the sound of     \n"+
     "the waves against the shore make it very peaceful here indeed.     \n"+
     "There are strange marks from the beach toward the high sand banks. \n");

  set_weather(1, 4, 6);
  set_exits(({ 
     "room/island/beach1", "east",
     "room/island/beach6", "west",
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
     "mark#marks",
          "It appears something heavy was dragged up the beach",
  }));

  set_search_array(({
     "sand#beach",
          "All you find is sand. Did you expect to find anything else?\n",
  }));
}


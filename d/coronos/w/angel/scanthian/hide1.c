#include <mudlib.h>
#include "paths.h"
inherit ROOM;

object gmas;
object sd;

void reset(status arg) {
  if(!arg) {
     set_short("Hideout");
     set_long(
"You are in the thieves' hideout. This is were they bring lots of their\n"+
"stolen loot. The elves live quite comfortably in this hole in the ground.\n"+
"The walls are made of dirt, and there are a few furnishing in here.\n");
     set_exits(({
	PATH+"new15", "out",
     }));
     set_items(({
       "walls",      "dirt walls",
       "furnishing", "a few chairs and tables",
     }));
     set_weather(2,4,3);
  }
  if(!present("elf")) {
    gmas = clone_object(MONSTER);
    gmas->set_name("elf");
    gmas->set_alias("grand master");
    gmas->set_short("Grandmaster Elf");
    gmas->set_short("Grandmaster elves");
    gmas->set_long(
"One of the toughest elves in the forest.  He leads the thieves on their\n"+
"quest for stolen loot. He stands an amazing 6ft high, and his ears aren't\n"+
"quites as pointy. It appears he is part human.\n");
    gmas->set_level(7);
    gmas->set_ac(7);
    gmas->set_wc(11);
    gmas->set_race("half elf");
    gmas->set_gender(1);
    gmas->add_class("mage");
    gmas->load_spells(20,({ "burning hands", "chill touch", }));
    gmas->set_al(-100); 
    move_object(gmas,this_object());
  }

  if(!present("sword", gmas)) {
    sd = clone_object(WEAPON);
    sd->set_name("shortsword");
    sd->set_short("An elven shortsword");
    sd->set_plural("elven shortswords");
    sd->set_long(
"This weapons was designed for elves in mind.  The blade is very short,\n"+
"but effective.  The handle is made of wood and the blade is held in it\n"+
"by leather straps.\n");
     sd->set_wc(9);
     sd->set_weight(6);
     sd->set_value(260);
     sd->set_type("slash");
     sd->set_length(25);
     sd->query_length();
     move_object(sd, gmas);
     command("wield blade", gmas);
  }
}

#include <mudlib.h>
inherit ROOM;

void reset(status arg) {
  reset_doors(arg);
  load_door(({
     "long",
          "Great iron gates, leading into the colosseum.\n",
     "direction", "west gate",
     "file",  "room/city/arena2",
     "key id", "city key",
  }));

  if(arg) return;
  set_short("the city colosseum");
  set_long(
     "Huge walls tower above you, leading the way toward the colosseum.\n"+
     "Here, many adventurers and famour gladiators have come to combat \n"+
     "each other, fighting for glory and honour.\n");
  set_exits(({
  }));
  set_smell("The air is thick with excitement.\n");
  set_listen("The air is full of chanting and talking voices, awaiting \n"+
     "the new gladiators to come into the arena.\n");
  set_items(({
     "walls", "Tall walls, built by dwarvish stonemasons",
  }));
  set_weather(2,1,0);
}

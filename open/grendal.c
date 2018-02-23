#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
set_name("grendal");
set_race("swamp monster");
  set_gender(1);
set_alignment(-250);
set_short("Grendal, the monster of the moors");
  set_long(
"Grendal is a fearsome monster who comes up out the cold depths\n"+
"of the moors to prey on man or beast.\n"+
"Only a powerful warrior indeed can defeat him.\n"+
"      \n");
set_level(16);
add_money(250 + random(75));
load_chat(10,({ "Grendal bellows his challenge!\n",
"Grendal eyes you hungrily.\n",
"Grendal howls at you.\n",
"Grendal knocks down a tree in his rage!\n",
"Grendal eyes you with contempt.\n",
"Grendal eyes you with contempt.\n",
  }));
}


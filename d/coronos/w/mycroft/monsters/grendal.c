#include <mudlib.h>
inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
set_name("Grendal");
set_alias("grendal");
set_race("swamp monster");
  set_gender(1);
set_alignment(-250);
set_short("Grendal, the monster of the moors.");
  set_long(
"Grendal is a blood-thirsty monster who emerges from the moors\n"+
"only to satisfy his inhuman hunger.  Only the mightiest of \n"+
"warriors can possibly defeat him!\n");
set_level(16);
set_hp(500);
set_max_hp(500);
set_strength(18);
set_dexterity(20);





add_money(2500 + random(1000));
load_chat(10,({"Grendal howls in rage!\n",
"Grendal eyes you hungrily.\n",
"Grendal thrashes about in frustration and hunger.\n",
  }));
load_a_chat(10,({ "Grendal bellows his challenge.\n",
  }));
}


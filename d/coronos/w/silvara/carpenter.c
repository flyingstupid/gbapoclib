#include <mudlib.h>
inherit MONSTER;


void reset(status arg) {
  if (arg) {
  return;
}

::reset(arg);
set_name("Tanthalas");
set_alt_name("carpenter");
set_short("Tanthalas, the carpenter");
set_long(
"Tanthalas, an elven carpenter, with icy blue eyes, stares haughtily\n"+
"down his nose.  His sculpted features are hardened by the coolness\n"+
"in his eyes.  His long black hair is pulled back by a strip of \n"+
"leather, and clothing of browns and greens cover his lean body.\n");

load_chat(10, ({
  "Tanthalas smirks as he says: My talent is sought by the richest\n"+
  "of all races.\n",
  "Tanthalas puffs out his chest and says: Even amongst my own people\n"+
  "of Scianthia, I am the best carpenter in these realms.\n",
  "Tanthalas sneers: Noone can or ever shall out do me.\n",
}));

load_a_chat(6, ({
  "Tanthalas hisses: What are ye doing, fool?\n",
  "Tanthalas screams: Ye know ye shall regret this when ye need a \n"+
  "new chair!\n",
  "Tanthalas backs away, trying to protect his wares.\n",
}));

set_attack_msg(({
  "slaps", "with his hands",
  "kicks", "with his booted feet",
  "punches", "with his hard fists",
}));

set_al(0);
set_level(18);
set_gender(1);
set_race("high elf");
}

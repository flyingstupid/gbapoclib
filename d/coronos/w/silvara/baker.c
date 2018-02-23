#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  if (arg) {
  return;
}

::reset(arg);
set_name("Horratio");
set_alt_name("baker");
set_short("Horratio, the baker");
set_long(
"Horratio stands relaxed but always attentive.  His light\n"+
"brown hair falls down to the collar of his bright blue\n"+
"tunic.  Red and white striped leggings catches the eyes, as\n"+
"does his bright green shoes.  An interesting cap adorns his head,\n"+
"while his hazel eyes take in his surroundings.\n");

load_chat(10, ({
  "Horratio says: I don't have time to chat, my friend, always busy.\n",
  "Horratio says: Come son, we have work to do.\n",
  "Horratio asks: Have ye tried my famous gnomeclaire?\n",
}));

load_a_chat(6, ({
  "Horratio shouts: No, no..I have work to do!\n",
  "Horratio backs away, trying to protect his son.\n",
}));

set_attack_msg(({
  "slaps", "with his hands",
  "kicks", "with his bare feet",
  "punches", "with his hard fists",
}));

set_al(0);
set_level(16);
set_gender(1);
set_race("halfling");
}

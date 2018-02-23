#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  if (arg) {
  return;
}

::reset(arg);
set_name("Maddin");
set_alt_name("son");
set_short("Maddin, the baker's son");
set_long(
"Maddin, is Horratio's four-year-old son.  He seems to be a smaller\n"+
"version of his father, except for his bright blue eyes which sparkle\n"+
"mischievously.  He holds a half eaten chocolate cupcake, with\n"+
"chocolate smeared all over his chubby cheeks and mouth.\n");

load_chat(10, ({
  "Maddin reaches out his chocolate covered chubby fingers for a hug.\n",
  "Maddin looks about with a sneaky grin on his little face.\n",
  "Maddin begs for a hug.\n",
}));

load_a_chat(6, ({
  "Maddin screams: Not me!!  Kill my father!\n",
  "Maddin cries and tries to run away.\n",
}));

set_attack_msg(({
  "slaps", "with his hands",
  "kicks", "with his bare feet",
}));

set_al(0);
set_level(12);
set_gender(1);
set_race("halfling");
}

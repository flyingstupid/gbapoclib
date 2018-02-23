#include <mudlib.h>
inherit MONSTER;

  void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bird");
  set_alias("seagull");
  set_race("seagull");
  set_short("a large seagull");
  set_long("\
This is a large white seagull. He seems to be looking for food. Being\n\
so near the ocean, he is well fed.\n");
  set_level(6);
  set_gender(1);
  set_ac(5);
  set_wc(10);
  add_money(100);
  set_attack_msg(({
"misses",       "",
"bites down",   "with his beak",
"tries to dodge", "",
"thwaps",       "with his large wings",
}));

  load_a_chat(8, ({
"The seagull screams loudly and tries to fly away.\n",
"You are thwapped loudly in the head by the seagull's great wings.\n",
}));
}

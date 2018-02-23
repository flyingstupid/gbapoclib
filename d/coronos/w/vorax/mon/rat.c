#include <mudlib.h>
inherit MONSTER;
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rat");
  set_race("rat");
  set_gender(1);
  set_short(
    "A large plump rat");
  set_long(
    "This is one of the infamous alley rats. His teeth come out over his\n"+
    "lip, and he is filthy. You had better not touch him, because he might\n"+
    "bite.\n");
  set_plural("rats");
  set_level(5);
  set_al(0);
  set_wc(9);
  set_ac(5);
  set_hp(80);
  set_max_hp(80);
  load_chat(2, ({
    "The rat sniffs at your leg.\n",
    "The rat bares his teeth at you.\n",
  }));
  set_attack_msg(({
    "nips","with his teeth",
    "scratches","with his claws",
    "slashes","with his fangs",
  }));
}

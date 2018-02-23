#include <mudlib.h>
inherit MONSTER;

  void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("child");
  set_race("human");
  set_short("a young child");
  set_long("This small child looks very bored. His wide blue eyes look full of wonder,\n\
and somehow that frightens you. Once he opens his mouth, he's not going\n\
to stop, somehow...you know this.\n");
  set_level(3);
  set_gender(1);
  set_ac(4);
  set_wc(7);
  add_money(90+random(20));
  load_chat(9, ({
"The child says: My dad could whip your dad!\n",
"The child asks: Hmm..Why are you so ugly?\n",
"The child stares at you in wild wonder.\n",
"The child asks: Why is the sky blue?\n",
"The child asks: Why is the grass green?\n",
"The child asks: Hey, why are there stones in this road?\n",
"The child asks: Why is there a railing here?\n",
"The child plays precariously on the railing..you find yourself\n\
evilly wishing he would slip.\n",
"The child asks: Why Why Why Why Why!?\n",
}));
  load_a_chat(9, ({
"The child asks: Why are you killing me?\n",
"The child screams and pain and asks, 'Why?'\n",
"The child says: I'm gonna tell my daddy on you!\n",
"The child says: I can whip your butt.\n",
"The child asks: Why are you so wimpy?\n",
}));
}

void catch_tell(string str) {
  return;
}

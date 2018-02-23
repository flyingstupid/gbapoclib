#include <mudlib.h>
inherit MONSTER;

  void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("drunk");
  set_alias("willy");
  set_short("a drunk named Willy");
  set_long("\
This guy looks like he's been boozing it up since before you were born.\n\
If he had any hair it would be a dirty grey color, and his clothes\n\
smell as if they had been soaked in beer and bourbon.\n");
  set_gender(1);
  set_race("human");
  set_level(8);
  set_wc(12);
  set_ac(7);
  add_money(12);
  load_chat(6, ({
"Willy licks some beer off of his hand.\n",
"The drunk stumbles towards you then falls on his butt.\n",
"A passerby throws a crumpled peice of paper at the drunk.\n",
"Willy says: Now wh-wh-why did they g-g-go and throw me outta da bar?\n",
"Willy asks: Hey, there, you, be a s-s-sport and buy me a beer eh?\n",
}));
  load_a_chat(6, ({
"Willy tries to kick you but falls flat on his face.\n",
"Willy screams: HEY, c-c-can't a feller drink in p-p-piece?\n",
"Willy throws a dirty bottle at you.\n",
"Willy says: Ya know, I've fought t-t-tougher guys than you!\n",
"Willy sighs in resignation, and sits here letting you wail on him.\n",
"Willy says: Least buy me a spot of bourbon before you dice me c-c-chum.\n",
}));
}

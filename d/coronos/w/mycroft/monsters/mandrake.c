#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
set_name("mandrake");
set_alias("man");
set_race("swamp monster");
set_max_hp(400);
  set_gender(1);
set_alignment(-150);
set_short("a slavering mandrake");
  set_long(
"A horrible creature that takes human-like form \n"+
"enare it's prey.\n"+
"And YOU are it!\n");
set_level(9);
add_money(1500 + random(1000));
load_chat(10,({"The mandrake sizes you up as a potential meal.\n"}));
}

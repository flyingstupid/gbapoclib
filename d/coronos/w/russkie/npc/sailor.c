#include <mudlib.h>
inherit MONSTER;

  void reset(status arg) {
  if(!present("sword")) {
move_object(clone_object("/d/coronos/w/russkie/obj/sword"),this_object());
  }
  set_wc(29);
  ::reset(arg);
  init_command("wield sword");
  if(arg) return;

  set_name("sailor");
  set_alias("man");
  set_short("a rugged sailor");
  set_long("This tall man looks like the type who chops wood with his bare hands. He has\n\
shining brown eyes, and sun-streaked dark hair. His large sword stands\n\
to prove what a worthy fighter he is.\n");
  set_gender(1);
  set_level(20);
  set_wc(29);
  set_ac(17);
  add_money(1800);
  load_chat(5, ({
"The sailor stares intently at you.\n",
"The sailor asks: Are you looking for trouble?\n",
}));
  load_a_chat(3, ({
"The sailor laughs at your pitiful attempt.\n",
}));
}

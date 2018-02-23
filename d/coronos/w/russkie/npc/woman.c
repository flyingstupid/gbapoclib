#include <mudlib.h>
inherit MONSTER;
    void reset(status arg) {
  if(!present("amulet")) {
  move_object(clone_object("/d/coronos/w/russkie/obj/amulet"),this_object());
}
  ::reset(arg);
  init_command("wear amulet");
  if(arg) return;

  set_name("woman");
  set_short("a young woman");
  set_long("This short young woman is happily looking out to sea.\n");
  set_gender(2);
  set_level(8);
  set_race("elf");
  set_wc(12);
  add_money(340+random(10));
}

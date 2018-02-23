#include <mudlib.h>
inherit MONSTER;
 
void init() {
  call_out("chat",1);
  ::init();
}
 
void reset(status arg) {
  if (arg) {
  return;
  }
 
  ::reset(arg);
  set_name("drow warrior");
  set_alias("drow");
  set_short("a drow warrior");
  set_long(
    "This is a Drow warrior.  She stands just over five feet tall, with\n"+
    "a slender and yet powerfull frame.  Her long, light grey hair is tied\n"+
    "tied in a top knot with a black cloth. The cloth and her hair reach\n"+
    "down to the small of her back.  Her skin is a very dark grey, which\n"+
    "contrast her light grey hair and eyes.\n");

   load_chat(5, ({
    "The Drow warrior stands tall and proud.\n",
    "The Drow warrior scans the area.\n",
    "The Drow warrior stares at something in the distance.\n",
    "The Drow warrior keeps an eye on her party.\n",
    "The Drow warrior moves silently.\n",
    }));
 
  load_a_chat(40, ({
    "The Drow screams with rage.\n",
    "The Drow fights elegantly and fiercly.\n",
    "The Drow curses violently.\n",
    "The Drow spins quickly, dodging blows.\n",
    "The Drow doesn't look afraid at all.\n",
    }));
 
  set_al(-350);
  set_level(8);
  set_wc(11);
  set_ac(6);
  set_max_hp(130);
  set_hp(130);
  set_gender(2);
  set_money(250 +random(100));
  set_race("drow elf");
  set_plural("drow warriors");
  add_class("fighter");

 if (!present("shortsword")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/items/sword3"),
    this_object());
    command("wield sword");
  }
}
 

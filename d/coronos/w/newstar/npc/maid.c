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
  set_name("maid");
  set_short("a maid");
  set_long(
    "A middle aged woman dressed in a plain brown smock and a long \n"+
    "white apron.  Her gray streaked, blond hair is done up in a tight\n"+
    "bun.  Her stern, brown eyes can spot a speck of dust from anywhere\n"+
    "in the room.  As maid, her job is to keep the place in tip top order\n"+
    "and she does so with a no nonsense attitude.\n");
  load_chat(4, ({
    "The maid puts her hands on her hips and surveys the room.\n",
    "The maid barely notices you as she goes about her work.\n",
    "The maid acknowledges you with a nod of her head.\n",
    "The maid looks for something to clean.\n",
    "The maid wipes her hand off on her apron.\n",
    }));
 
  load_a_chat(40, ({
    "The maid yells, 'I can take you on any day!'\n",
    "The maid shrieks out in fear and anger.\n",
    "The maid runs around, flailing her arms about.\n",
    "The maid cries out, 'You baffoon!  I just cleaned this room!'\n",
    "The maid tries to fend off the assault.\n",
    }));
 
  set_al(275);
  set_level(3);
  set_wc(7);
  set_ac(4);
  set_max_hp(60);
  set_hp(60 + random(10));
  set_gender(2);
  set_money(20 +random(10));
  set_race("human");
 
 
if (!present("duster")) {
    move_object(clone_object(
    "/d/coronos/w/newstar/items/duster"),
    this_object());
    command("wield duster");
  }
}

#include <mudlib.h>
#include "path.h"

inherit ROOM;
void reset(status arg) {
  object money, gem;
  int i;

  if(!money) {
    money = clone_object("obj/money");
    money -> set_money(2000 + random(10000));
    move_object(money, this_object());
  }

  if(!present("gem")) {
    for(i=0; i<6; i++) {
      gem = clone_object("objects/components/gem");
      move_object(gem, this_object());
    }
  }

    
  if(arg) return;

  set_short("the wyvern's lair");
  set_long(
"Large broken shells lay in the dark shadows on the far side of the cavern.\n"+
"A mess of feaces makes remaining here almost unbearable.\n");

  set_items(({
	"shells", "They looks very large",
	"feaces", "They smell",
  }));

  set_smell("This place smells to high heaven!\n");
  set_listen("You can hear the hissing of a large creature nearby.\n");

  set_exits(({
	PATH+"/l1r20", "up",
  }));

  set_climb(15);
  set_fall_dam(20);

  set_weather(0, 1, 0);
}

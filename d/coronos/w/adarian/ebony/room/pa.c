#include <mudlib.h>
#include <ansi.h>
#include "path.h"

inherit "inherit/room2";

void reset(status arg) {
  reset_doors(arg);

  load_door(({
    "file", EDOOR "ds01.c",
    "direction", "south door",
    "closed",
  }));
  if(arg) return;
  set_short("Ebony Port Authority");
  set_long(BLUE_F+"\t--<Ebony Port Authority>--\n"+OFF+
"This is Ebony's port authority.  All decisions about what is accepted,\n"+
"turned away or confiscated is made here.  This is also where you can\n"+
"have things delivered to other players in the realms.  There is a sign\n"+
"on the north wall above the port administrators head.\n");
  set_weather(5, 2, 6);
  set_items(({"sign",
    "Maybe you should try reading it.",
  }));
}

void init() {
  ::init();
  add_action("read", "read");
}

status read(string str) {
  if(!str) return 0;
  else if(str == "sign") {
    tell_object(this_player(),
"You can deliver an item to another player on the realm.  The cost for this\n"+
"service is 15 copper per unit of weight of the item to be delivered.  To\n"+
"find out how much it will cost to deliver an item type 'cost <item>'.  To\n"+
"deliver an item to another player type 'deliver <item> to <player>'.\n"+
"Warning:  There is a possibility the item will be damaged or destroied in\n"+
"delivery (wow, just like the USPS.)\n");
  return 1;
  }
  return 0;
}

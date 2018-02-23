#include <mudlib.h>
#include "paths.h"

inherit ROOM;

string *prayed;

void reset(status arg) {

  prayed = ({ });  /* reset the prayed list */

  if(arg) return;

  set_short("a temple for weary travellers");

  set_long(
"This temple has a small altar in the north, surrounded by candles. Travellers\n"+
"come here to stop, rest and pray for guidance to Susabo, patron of voyages.  \n"+
"There is a fire pit in the centre of the room and a few comfortable benches  \n"+
"around the room.\n");


  set_no_fight(1);

  set_items(({
	"candles",
	"Small candles line the front of the altar as offerings to those people\n"+
	"who have embarked on voyages. It is said to bring them good luck",

	"altar",
	"The altar is made from marble and bears the symbol of Susabo",

	"symbol",
	"The symbol of Susabo is carved into the altar at the north end of the \n"+
	"temple. It depicts a worn circle of sand with a shoe in the centre",

	"pit#fire pit",
	"The fire pit is burning and offers warmth during the night for wayward\n"+
	"travellers who visit here and stop for the night",

  }));

  set_weather(3,0,0);

  set_exits(({
        PATH+"road3",  "south",
  }));

}


void init() {
  ::init();
  add_action("pray", "pray");
}

status pray(string str) {
  string tmp1, tmp2;
  object spell, ob, dead;

  ob = this_player();


  if(this_player()->query_ghost()) {
    write("Susabo hears your prayers...\n");
    ob->toggle_ghost();
    return 1;
  }

  if(!str) {
    notify_fail("Pray for what?\n");
    return 0;
  }

  if(this_player()->query_class("cleric")) {
    notify_fail("Susabo doesn't want your prayers. Pray to your own god!\n");
    return 0;
  }

  if(member_array(ob->query_name(1), prayed) != -1) {
    notify_fail("But you have already received a blessing today.\n");
    return 0;
  }

  say(ob->query_name()+" prays to Susabo.\n", ob);
  write("You pray to Susabo "+ (str ? str : "") +"\n");

  if(sscanf(str, "for %s", tmp1)) {
    if(sscanf(tmp1, "%sluck%s", tmp1, tmp2)) {
      if(!random(10)) {
        write("\n\nSusabo hears your prayers...\n\n");
        spell = clone_object(BLESS);
	move_object(spell, ob);
        spell -> cast_spell(ob, ob, 0, DURATION);
        prayed += ({ ob->query_name(1), });
        return 1;
      }
      notify_fail("Nothing happens. Perhaps you're not praying hard enough.\n");
      return 0;
    }
    else if(sscanf(tmp1, "%shealing%s", tmp1, tmp2)) {
      if(!random(10)) {
        write("\n\nSusabo hears your prayers...\n\n");
        spell = clone_object(CURE);
        move_object(spell, ob);
        spell->cast_spell(ob, ob, 0, 10); /* good enough for a freebie! */
        prayed += ({ ob->query_name(1), });
        return 1;
      }
      notify_fail("Nothing happens. Perhaps you're not praying hard enough.\n");
      return 0;
    }        
    else if(dead = find_player(tmp1)) {
      if(!random(10)) {
        if(!dead->query_ghost()) {
          notify_fail("But "+dead->query_name()+" is not dead!\n");
          return 0;
        }

        write("\n\nSusabo hears your prayers...\n\n");
        say(ob->query_name()+" prays to Susabo.\n", ob);
        spell = clone_object(RESURRECT);
        move_object(spell, ob);
        spell -> cast_spell(ob, dead, 0, DURATION);

        prayed += ({ ob->query_name(1), dead->query_name(1), });
        return 1;
      }
      notify_fail("Nothing happens. Perhaps you're not praying hard enough.\n");
      return 0;
    }

    notify_fail("Nothing happens. Perhaps you're not praying for\n"+
                " right thing.\n");
    return 0;
  }

  notify_fail("Nothing happens. Perhaps you're not praying hard enough.\n");
  return 0;
}



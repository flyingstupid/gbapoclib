#include <mudlib.h>

#define PATH 	"d/coronos/w/angel/ud/l1/"
#define OBJ	"d/coronos/w/angel/ud/obj/"
#define MONST	"d/coronos/w/angel/ud/monst/"

inherit ROOM;

object chest;
object sword;
object money;

void reset(status arg) {
object mon;
int i;

  if(!present("spider")) {
    for(i=0; i<7; i++) {
      mon = clone_object(MONST+"spider");
      move_object(mon, this_object());
    }
  }

  if(!present("chest")) {
    chest = clone_object(OBJ+"chest");
    move_object(chest, this_object());
  }
  
  if(!present("money", chest)) {
    money = clone_object("obj/money");
    money -> set_money(10000);
    move_object(money, chest);
  }

  if(!sword) { /* only want one of these items to appear per reset! */
    sword = clone_object(OBJ+"life");
    move_object(sword, chest);
  }    

  if(arg) return;

  set_short("a cave");
  set_long(
"This small cave appears to have been used at some time    \n"+
"as a small base of operation for some creatures. A small\n"+
"round table sits in the centre with several stools around \n"+
"its edge, awaiting with patience, the return of its owners.\n");

  set_items(({
	"table",
	"It's made from stone and appears to be very heavy.\n"+
	"On the table are some playing cards and a few dice.\n"+
	"It looks like who ever was here left in a hurry.\n",

	"dice", "The dice show a pair of ones; \"snakes eyes\"\n",
	"cards#playing cards",
	"One hand shows a pair of orcs, and another a full house;\n"+
	"a full house of Noquar that is",

	"stools",
	"The stools are simple and made from wood",
  }));


  set_listen("You can hear the occasional drip of water from "+
	"the ceiling.\n");

  set_weather(2, 1, 0);

  set_exits(({
	PATH+"n_path2", 	"south",
  }));
}



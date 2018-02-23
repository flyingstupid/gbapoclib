#include <mudlib.h>

#define CHARISMA	(int)this_player()->query_charisma()
#define MY_CHARISMA	15
#define DEFAULT_COST	1000
#define NAME		(string)this_player()->query_name()

inherit MONSTER;

static int i;
static object bag, arrow, hammer;

void reset(status arg) {
  ::reset(arg);

  if(!present("hammer")) {
    hammer = clone_object(WEAPON);
    hammer -> set_type("crush");
    hammer -> set_wc(11);
    hammer -> set_length(24);
    hammer -> set_name("hammer");
    hammer -> set_weight(6);
    hammer -> set_value(620);
    hammer -> set_short("A small hammer");
    hammer -> set_long(
	"Far from being a war hammer, this small weapon would be better \n"+
	"thrown at an opponent. The head is a little damaged, and from  \n"+
	"the general condition of the weapon it would appear to have    \n"+
	"been mainly used as a minning tool.\n");
    move_object(hammer, this_object());
    init_command("wield hammer");
  }

  if(!present("bag")) {
    bag = clone_object("objects/bag");
    bag -> set_name("bag");
    bag -> set_short("A small leather pouch");
    bag -> set_alias("pouch");
    bag -> set_long("A simple leather pouch made from drow-hide.\n");
    bag -> set_info("It has the name Malz branded on the inside.\n");
    bag -> set_closed(1);
    move_object(bag, this_object());
  }

  if(!present("arrow head", bag)) {
   for(i=0; i<5; i++) {
      arrow = clone_object("objects/head");
      arrow -> set_short("A stone arrow head");
      arrow -> set_long("This is a fine arrow head, obviously crafted \n"+
                        "by a dwarvish stone mason. \n");
      arrow -> set_value(random(10) + 10);
      move_object(arrow, bag);
    }
  }

  if(arg) return;

  set_name("malachite");
  set_short("Malachite, the stonemason");
  set_alias("dwarf");
  set_long(
	"Malachite is a simple apprentice stonemason who spends \n"+
	"his time deep within the mountains and caves practising\n"+
	"his skills on small rocks.\n");
  set_race("mountain dwarf");
  set_level(5);
  set_hp(80);

  load_chat(5, ({ "Malachite chips away at some stone.\n",
	"Malachite says: I'll sell you an arrow head if you like.\n",
	"Malachite works on an arrow head.\n",
	"Malachite looks at his arrow head.\n",
  }));

}

void init() {
  ::init();
  add_action("buy", "buy");
}

status buy(string str) {
  string tmp1, tmp2;
  int cost;
  object ob;

  if(!str) {
    write("Malachite says: What did you want to buy from me?\n");
    return 1;
  }
  if(str == "stone") {
    write("Malachite says: But there's lots of stone here. Just look around.\n");
    return 1;
  }
  if(sscanf(str, "%sarrow%s", tmp1, tmp2)) {
    write("Malachite exclaims: I have some arrow heads! \n");
    cost = DEFAULT_COST;
    
    write("Malachite bargains with you over the price of the arrow head.\n");
    if(random(CHARISMA) > random(MY_CHARISMA))
      cost -= cost/4;
    else
      cost += cost/3;

    if(this_player()->query_money() < cost) {
      write("Malachite says: You don't seem to have "+MONEY->convert(cost)+
      " coins for the arrow head.\n");
      return 1;
    }
    
    if(!this_player()->add_weight(1)) {
      write("Malachite says: You can't carry anymore.\n");
      return 1;
    }

    this_player()->add_money(-cost);
    write("Malachite takes "+(string)MONEY->convert(cost)+" coins "+
    "for the arrow head.\n");

    write("Malachite hands you an arrow head.\n");
    say("Malachite gives "+NAME+" an arrow head.\n", this_player());
    arrow = clone_object("objects/head");
    arrow -> set_long("This is a fine arrow head, obviously crafted \n"+
                      "by a dwarvish stonemason.\n");
    move_object(arrow, this_player());
    return 1;
  }
  write("Malachite asks: What do you want from me? I only make arrow heads.\n");
  return 1;
}


void catch_tell(string str) {
  string tmp1, tmp2;
  if(sscanf(str, "%s says: arrow%s\n", tmp1, tmp2) ||
     sscanf(str, "%s says: buy%s\n", tmp1, tmp2)) {
    buy("arrow");
    return;
  }
}

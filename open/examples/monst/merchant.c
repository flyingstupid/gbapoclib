#include <mudlib.h>
#define CHA		(int)this_player()->query_charisma()
#define CHANCE	12
#define COST		20

inherit MONSTER;



object ob1, ob2;

status buy_potato();

void reset(status arg) {
  int i;
  if(!present("bag")) {
    ob1 = clone_object("objects/bag");
    move_object(ob1, this_object());
  }
  if(!present("potato", ob1)) {
    for(i=0; i<5; i++) {
      ob2 = clone_object(FOOD);
      ob2 -> set_name("potato");
      ob2 -> set_short("A potato");
      ob2 -> set_long("It looks like an ordinary potato!\n");
      ob2 -> set_strength(2);
      ob2 -> set_value(10);
      ob2 -> set_weight(1);
      ob2 -> set_eater_mess("Raw potatos were always a bit crunchy\n");
      move_object(ob2, ob1);
    }
  }


  ::reset(arg);
  if(arg) return;

  set_level(10);
  set_alignment(-100);
  set_name("galaon"); 
  set_race("human");
  set_short("Galaon, the humble merchant");
  set_long(
	"Galaon has travelled on the Tamiel with his wares to sell \n"+
	"in the street markets of Ille Coronos, while he looks like\n"+
	"an honest merchant, there is something shifty about him.\n");
  set_gender(1);
  load_chat(4, ({
	"Galaon says: Want to buy a potato?\n",
	"Galaon says: I have some nice potatos.\n",
	"Galaon polishes a potato.\n",
  }));

  set_wimpy(50);

  load_a_chat(5, ({
	"Galaon exclaims: The commerce guild will hear about this!\n",
	"Galaon says: Go away.\n",
	"Galaon exclaims: Leave me alone\n",
	"Galaon cries out in pain.\n",
	"Galaon bursts into tears.\n",
  }));
}

void catch_tell(string str) {
  string tmp1, tmp2, tmp3;

  ::catch_tell(str);

  if(sscanf(str, "%s says: yes %s", tmp1, tmp2) ||
     sscanf(str, "%s says:%spotato%s", tmp1, tmp2, tmp3)) {
    buy_potato();
  }
}

status buy_potato() {
  int cost;
  object ob;
  ob = present("potato", ob1);
  if(!ob) {
    write(query_name()+" says: I've run out of potatos.\n");
    return 1;
  }
  write(query_name()+" haggles for the price of a potato.\n");
  cost = COST;
  if(random(CHA) < random(CHANCE))
    cost -= cost/4;
  else
    cost += cost/3;

  write(query_name()+" says: That will cost you "+
	MONEY->convert(cost)+" coins!\n");
  if(cost > (int)this_player()->query_money()) {
    write(query_name()+" says: You seem to have a cash flow problem\n");
    return 1;
  }
  write(query_name()+" takes "+MONEY->convert(cost)+" coins from you.\n");
  this_player()->add_money(-cost);
  move_object(ob, this_player());
  this_player()->add_weight((int)ob->query_weight());
  return 1;
}
    





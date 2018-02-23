/* Frank */
/* Darkness */

#include <mudlib.h>
inherit MONSTER;
 
 
void reset(status arg) {
  if (arg) {
  return;  
  }
 
  ::reset(arg);
  set_name("Frank, the vendor");
  set_alias("frank");
  set_short("Frank, the vendor");
  set_long(
    "Frank looks to be in his late forties, brown hair and a pointy\n"+
    "mustache.  He wears a white apron with a turkey leg painted on\n"+
    "the front.  He pushes around his cart that holds his turkey\n"+
    "legs wherever he walks.  The cart has a large sign nailed to\n"+
    "side.  Through rain or shine, night and day, he sells his\n"+
    "famous smoked turkey legs to any that will buy them.\n");
  load_chat(5, ({
    "Frank smiles at you.\n",
    "Frank checks on his smoking turkey legs.\n",
    "Frank bellows, 'Get your smoked turkey legs here!'\n",
    "Frank says, 'Would you like to buy a turkey leg?\n'",
    "The scent of smoking turkey legs lingers in the air.\n",
    })); 
 
  load_a_chat(4, ({
    "HELP!\n",
    "Help!  Someone help me!\n",
    "Help!  Guards!\n",
    "Frank tries to run away.\n",
    "Frank throws a turkey leg at you.\n",    
    }));
  set_al(250);
  set_level(14);
  set_gender(1);
  set_race("human");
  set_domain("darkness");
  set_wander(30, 120);
  add_money(300); 
  add_class("fighter");
}



void init() {
  call_out("chat",1); 
  add_action("buyer", "buy");
  add_action("read1", "read");
  ::init();
}



void chat() {
  if (!this_player()->query_stealth_on() && !this_player()->query_npc()) {
    tell_object(this_player(), 
      "Frank smiles at you and asks, 'Would you like to buy a turkey leg?'\n");
  }
}



status read1(string str) {
  string tmp1, tmp2;

  if(!str) {
    write("Read what?\n");
    return 1;
  }
 
  if(sscanf(str, "%ssign%s", tmp1, tmp2)) { 
    write(
    " _________________________________   \n"+
    "|                                 |  \n"+
    "|  ~Frank's Smoked Turkey Legs~   |  \n"+
    "|                                 |  \n"+
    "|    Only 2 silver a piece!       |  \n"+
    "|                                 |  \n"+
    " ---------------------------------   \n");
    return 1;
  }

  else { 
    return 0;
  }  
}

status buyer(string str) {
  int player_money, cost_money;
  string tmp1, tmp2;

  player_money=this_player()->query_money();
  cost_money=200;
  
  if(!str) {
    write("Do you wish to buy a leg?\n");
    return 1;
    }

  if (cost_money > player_money) {
    write("Frank says, 'Sorry.  No cash, no leg'.\n");
    return 1;
    }

  else if(sscanf(str, "%sleg%s", tmp1, tmp2)) { 
    write(
      "Frank takes "+cost_money+" coins from you, and\n"+
      "hands you a steaming turkey leg.\n");
    say(this_player()->query_name()+
      " buys a steaming turkey leg from Frank.\n", this_player());
    this_player()->set_money(player_money - cost_money);
    move_object(clone_object(
      "d/coronos/w/darkness/items/tleg"), this_player());
    return 1;
    }
 
  return 0;
}

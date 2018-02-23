#include <mudlib.h>
 
inherit "inherit/chair";
 
 
void init() {
  ::init();
  add_action("put_money", "put");
  add_action("throw_money", "toss");
  add_action("throw_money", "throw");
}
 
 
reset(string arg)  {
  if (arg) 
    return;
 
  ::reset();
 
  set_name("fountain");
  set_short(0);
  set_long(
    "This is a fairly large fountain made of smooth grey stone.  Water\n"+
    "trickles down the from the top into each of three layered resevoirs.\n"+
    "The top of the fountain is decorated with a small statue of an angel.\n"+
    "Various runes and carvings are etched upon the stone.  The outer rim\n"+
    "of the fountain can be used as a bench for people to relax on.  There\n"+
    "also seems to be a small amount of coins in the fountain, possibly\n"+
    "thrown in for good luck by the fountain's last visitor.\n"
    );
   
 
  set_weight(10000);
  set_max_sitters(10);
}
 
 
status put_money(string arg)  {
  return 0;  
}
 
 
 
status throw_money(string arg) {
  int player_money, thrown_money;
  string item, preposition, container;
  
  if(!arg) {
    notify_fail("Toss what?\n");
    return 0;
  }

  player_money=this_player()->query_money();
  
  sscanf(arg, "%d %s %s %s", thrown_money, item, preposition, container);
   
  /* make sure we're talking about the right thing */
  if (container != "fountain") {
    write("That didn't seem to accomplish anything.\n");
    write("Perhaps you should toss the coins into the fountain this time?\n");
    return 1;
  }
  
  if (item != "coins") {
    write("You think twice about littering in the fountain.\n");
    return 1;
  }
  
  /* parse preposition */
  switch(preposition) {
    case "in":
    case "into":
      break;
    default:
      write("Throw coins into fountain, maybe?\n");
      return 1;
      break;
  }
  
  if (thrown_money < 1) {
    write("You have to at least throw in one coin.\n");
  }
  if (thrown_money > player_money) {
    write("But you haven't got "+call_other(MONEY, "convert",  thrown_money)+
	  "to throw!\n");
  }
  else {
    write("You toss "+call_other(MONEY, "convert", thrown_money)+
	  "into the fountain.\n"+
	  "Maybe your wish will come true...\n");
    this_player()->set_money(player_money - thrown_money);
  }
  
  return 1;
}
 
 

/*****************************************************************************
 * fountain.c
 * Fountain in the Plaza of the Mage University
 * 
 * November, 1996
 * Pulse
 * <johnw@bitsmart.com>
 */


#include <mudlib.h>
 
inherit "inherit/chair";
 
 
void init() {
  ::init();
  add_action("throw_money", "toss");
  add_action("throw_money", "throw");
}
 
 
reset(string arg)  {
  if (arg) 
    return;
 
  ::reset();
 
  set_name("fountain");
  set_short("a sparkling fountain");
  set_long(
    "Truly a work of art, this massive fountain is constructed out of a brilliant\n"+
    "white, smooth stone with numerous runes and pictures depicting the\n"+
    "illustrious history of the university.  The fountain juts out on the\n"+
    "sides to form a bench for people to sit on.  Crystal clear water\n"+
    "sparkles out from the middle of the fountain in a beautiful pattern\n"+
    "at least partly helped by magic.  The bottom is littered with coins;\n"+
    "perhaps in the hopes of a wish coming true.\n"
  );
 
  set_weight(10000);
  set_max_sitters(10);
}
 
 
status throw_money(string arg) {
  int player_money, thrown_money;
  string item, preposition, container;
  
  player_money=this_player()->query_money();
  
  /* parse expression - should be like "10 coins into fountain" */
  sscanf(arg, "%d %s %s %s", thrown_money, item, preposition, container);
   
  /* make sure we're talking about the right thing */
  if (container != "fountain") {
    write("That didn't seem to accomplish anything.\n");
    return 1;
  }
  
  /* make sure we're throwing coins.  we have the right #args if we're here */
  if (item != "coins" && item != "coin") {
    write("If the mages caught you throwing trash in their prize fountain. . .\n");
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
  }
  
  if (thrown_money < 0) {
    write("Don't be cheap.  Taking money from the fountain would be\n"+
	  "most uncouthed.\n");
  }
  if (thrown_money > player_money) {
    write("But you haven't got "+call_other(MONEY, "convert",  thrown_money)+
	  "to throw!\n");
  }
  else {
    write("You toss "+call_other(MONEY, "convert", thrown_money)+
	  "into the fountain.\n"+
	  "The spot the coins hit lights up a little with a magic glow.\n");
    this_player()->set_money(player_money - thrown_money);
  }
  
  return 1;
}
 

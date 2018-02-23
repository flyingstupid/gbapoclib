/* egg.c */
/* Darkness */

#include <mudlib.h>
inherit TREASURE;

void reset(status arg) {

  ::reset(arg);

  if(arg) return;

  set_name("chicken egg");
  set_short("a chicken egg");
  set_alias("egg");
  set_long(
    "This is a brown chicken egg.  Its shell is intact and it doesn't look\n"+
    "rotten.  It looks tasty, but it would probably be better if it were\n"+
    "cooked first.\n");
  set_smell(
    "The chicken egg doesn't really smell at all.\n");
  set_value(1);                
  set_weight(1);              
  set_sell_destruct(1);
}



void init() {
  add_action("eat1", "eat");
  ::init(); 
}



status eat1(string str) {
  string tmp1, tmp2;

  if(!str) {
  write("Eat what?\n");
  return 1;
  }

  else if(sscanf(str, "%segg%s", tmp1, tmp2)) { 
  write(
    "\nYou eat the chicken egg.\n"+
    "The raw egg is is warm and tastes disgusting.\n"+
    "It may have been better if you cooked it first.\n");
  say(this_player()->query_name()+" eats a chicken egg.\n", this_player());
  this_player()->hit_player(random(4)+1);
  destruct(this_object()); 
  return 1;
  }

  return 0;

}

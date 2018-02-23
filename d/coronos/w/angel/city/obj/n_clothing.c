#include <mudlib.h>

inherit CLOTHING;

void reset(status arg) {
  if(arg) return;

  set_short("A surcoat");
  set_name("surcoat");
  set_long(
"This fine surcoat is made from yellow simple cotton and    \n"+
"bears a large eagle, half black and half red on it's front.\n"+
"This symbol is the coat of arms of Lord Shadowbane, marking\n"+
"you as one of his men, in his infantry.\n");

  set_weight(1);
  set_sell_destruct(1);
  set_value(1); /* a newbie item */
}

string extra_look() {
  object ob;
  ob = environment();

  if(interactive(ob)) {
    return ob->query_name()+" is an infantryman in Shadowbane's army.";
  }
}

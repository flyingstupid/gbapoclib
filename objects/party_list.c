#include <mudlib.h>
inherit TREASURE;

#ifndef PAGER
#define PAGER "obj/pager"
#endif /*  PAGER */

void reset(status arg) {
  if(arg) return;
  set_sell_destruct(1);
  set_name("list");
  set_short("The list of best parties");
  set_long(
	"Written here is the list of the best parties on the mud.\n"+
	"Perhaps you could read it?\n");
  set_weight(1);
  set_value(10);
}

init() {
  ::init();
  add_action("read_me", "read");
}

status read_me(string str) {
  object pager_ob;
  string tmp;
  if(!str) return 0;
  if(present(str, this_player())) {
    if(str == "list") {
      if(this_player()->ansi_on())
        tmp = (string)PARTY_DAEMON->get_best_party();
      else
        tmp = this_player()->filter_ansi((string)PARTY_DAEMON->get_best_party());
#ifdef PAGER
      pager_ob = clone_object(PAGER);
      move_object(pager_ob, this_player());
      pager_ob->page(tmp);
#else
      write(tmp);
#endif /* PAGER */
      return 1;
    }
  }
  return 0;
}

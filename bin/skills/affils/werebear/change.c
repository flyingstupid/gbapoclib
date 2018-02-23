#include <mudlib.h>

#define NAME	(string)this_player()->query_name()
#define RACE	(string)this_player()->query_race()

status change() {
  object ob;

  if(this_player()->query_primary_attack()) {
    notify_fail("You can not change mid way during combat.\n");
    return 0;
  }

  if(ob = present("werebear", this_player())) {
    if(ob->query_wereform()) {
      write("You change back into "+ RACE +" form.\n");
      say(NAME +" changes back into "+ RACE +" form.\n",this_player());
      ob->set_wereform(0);
      return 1;
    }
    ob->set_wereform(1);
    write("You change into a werebear!\n");
    say(NAME +" changes into a werebear!\n", this_player());
    ob->drop_equipment();
    return 1;
  }
  notify_fail("Nothing happens. Perhaps you have been forsaken by Hoturu.\n");
  return 0;
}

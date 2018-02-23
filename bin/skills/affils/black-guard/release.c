#include <mudlib.h>
//#include <living.cfg>
#include <combat.cfg>

#define PRISON	find_object("/d/coronos/w/angel/city/chambers/gaol");

status release(string str) {
#ifndef PK
  return 0;
#else /* PK */
  object ob, Ob;

  if(!str) {
    notify_fail("Release who?\n");
    return 0;
  }

  str = lower_case(str);
  Ob = PRISON;
  if(!ob = present(str, Ob)) {
    notify_fail("That person is not currently in gaol.\n");
    return 0;
  }

  Ob = find_object(PK_OFFICE);
  if(!Ob) {
    notify_fail("Warning: Can't locate city gaol.\n");
    return 0;
  }

  if(!present(this_player(), Ob)) {
    notify_fail("You can't release a criminal from here.\n");
    return 0;
  }

  PK_OFFICE -> remove_villian(ob->query_name(1));
  write("You release "+ob->query_name()+" from gaol.\n");
  write("You gain some experience from the ordeal.\n");
  this_player()->add_exp(ob->query_level() * 250);

  tell_object(ob, "The gaol door opens.\n"+
	"Guard arrives.\n"+
	"Guard releases your manacles.\n"+
	"Guard escorts you from the gaol cell.\n");

  ob -> move_player("#"+PK_OFFICE);
  write("Guard arrives, escorting "+ob->query_name()+"\n");
  say("Guard arrives, escorting "+ob->query_name()+".\n", ob);

  return 1;
#endif /* PK */
}

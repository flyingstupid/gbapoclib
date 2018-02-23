#include <mudlib.h>
//#include <living.cfg>
#include <combat.cfg>
#include <player.cfg>

status arrest(string str) {
#ifndef PK
  return 0;
#else /* PK */
  object ob;

  if(!str) {
    notify_fail("Arrest who?\n");
    return 0;
  }

  if(!ob=present(lower_case(str), environment(this_player()))) {
    notify_fail("That person is not here!\n");
    return 0;
  }
  if(ob -> query_npc()) {
    notify_fail("You can't arrest "+ob->short()+"!\n"+
	ob->query_pronoun()+" hasn't done anything wrong!\n");
    return 0;
  }

  if(ob == this_player()) {
    notify_fail("You can't arrest yourself!\n");
    return 0;
  }

  if(!PK_OFFICE -> query_villian((string)ob->query_name(1))) {
    notify_fail(ob->short()+" isn't even a wanted criminal!\n");
    return 0;
  }


  write("You arrest "+ob->short()+".\n");
  tell_object(ob, this_player()->query_name()+" arrests you.\n");
  tell_room(environment(this_player()),
	"Guard arrives.\n"+
	"Guard escorts "+ob->query_name()+" to the local gaol.\n");
  ob -> move_player("with a few guards#d/coronos/w/angel/city/chambers/gaol");
  return 1;
#endif /* PK */
}

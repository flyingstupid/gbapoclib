#include <mudlib.h>

#define TP	this_player()
#define NAME	(string)TP->query_name()
#define BURRIED "objects/burried"
#define DIRT	"objects/dirt"

void bury_me(object *ob);


#if USE_PARSE_COMMAND

status bury(string str) {
  object *ob, ob1, ob2;
  object *items;
  string prep, verb;
  mapping result;

  if(!str) {
    notify_fail("Bury what?\n");
    return 0;
  }

  if(TP->query_ghost()) {
    notify_fail("It passes right through your hands.\n");
    return 0;
  }



  verb = query_verb();

  ob1 = environment(this_player());

  if(!parse_command(
    verb +" "+ str, ob1, " 'bury' %i %p %o", items, prep, ob2))
    parse_command(verb +" "+str, ob1, " 'bury' %i", items);

//remove blueprints... want only clones in the result
  if(pointerp(items))
  	items[1..] = filter(items[1..], #'clonep);

  result = SORTER->sorter(items, 0, 0, 0, environment(ob1));

  if(!mappingp(result)) {
    ob1 = present(str, TP);
    if(!ob1) {
      notify_fail("You don't have that to bury!\n");
      return 0;
    }
    bury_me(({ ob1, }));
    return 1;
  }

  ob = result["ob"];

  return (status)bury_me(ob);
}
#else
status bury(string str) {
	write("Bury isn't currently supported on "+MUDNAME+"\n);
	return 1;
}
#endif /* parse_command */

void bury_me(object *ob) {
  int i;

  if(!ob) {
    notify_fail("Bury what?\n");
    return;
  }  

  if(present("mound", environment(TP))) {
    notify_fail("There is no more room to bury more here.\n");
    return;
  }

  if(environment(TP)->query_inside()) {
    notify_fail("You can't bury that inside!\n");
    return;
  }


  for(i=0; i<sizeof(ob); i++) {
    if(ob[i]->drop()) continue;
  if(!ob[i]->get()) continue;

    if(living(ob[i])) {
      notify_fail(ob[i]->short() +" wouldn't be happy about that!\n");
      return;
    }

    if(!ob[i]->short()) continue;

    if(!present(ob[i], TP)) {
      notify_fail("You have to pick up "+ob[i]->short()+" before "+
	"you can bury it.\n");
      return;
    }

    write("You bury "+ob[i]->short()+".\n");
    say(NAME +" buries "+ob[i]->short()+".\n");

    move_object(ob[i], BURRIED);
  }

  move_object(clone_object(DIRT), environment(TP));
  TP->recalc_carry();
}


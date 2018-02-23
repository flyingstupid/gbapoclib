#include <linewrap.h>

status consider(string str) {
  object ob;
  if(!str) {
    notify_fail("Consider what?\n");
    return 0;
  }

  if(!ob=(present(str, environment(this_player())))) {
    notify_fail(capitalize(str) +" is not here.\n");
    return 0;
  }

  if(ob == this_player()) {
    write("You think you're tough enough.\n");
    return 1;
  }

  writelw("Only through experience will you learn the "+
	"strengths and weaknesses of "+ob->short()+".\n");
  return 1;
}


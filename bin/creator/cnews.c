#include <mudlib.h>

status cnews() {
  object ob;

/*
  ob = clone_object(MORE_OB);
  ob -> more("/data/news/WIZNEWS");
*/
  this_player()->more("/data/news/WIZNEWS");
  return 1;
}


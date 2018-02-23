#include <mudlib.h>

#define TP	this_player()
#define NAME	(string)this_player()->query_name()
#define BURRIED	"/objects/burried"
#define ROPE	"objects/rope"


status dig(string str) {
  object ob;
  object room;
  object *items;
  int i, j;

  "/objects/burried" -> reset(1); /* just in case */
  room = find_object(BURRIED);

  if(!(ob = present("dirt", environment(TP)))) {
    notify_fail("You dig your own grave.\n");
    say(NAME+" digs "+TP->query_possessive()+" own grave.\n");
    return 0;
  }

  destruct(ob);
  write("You dig something up.\n");
  say(NAME +" digs something up.\n");

  items = all_inventory(room);
  if(!sizeof(items) || !items) 
    items = ({ clone_object(ROPE), });

  j = random(sizeof(items));
  for(i=0; i<sizeof(items); i++) {
    move_object(items[i], environment(TP));
    if(i >= j) break;
  }
  return 1;
}




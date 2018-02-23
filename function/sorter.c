/* SORTER v1.0   (c) Angel, for Heaven7 v3.0-beta. April 1997.
 * This object is the generic sorter for the several bin commands and 
 * other action functions. It sorts out the items, and then returns
 * a mapping of the items it found that match the string you put in.
 */ 


mapping sorter(mixed *items,
		string prep,
		object container,
		string msg,
		object default_container) {
  int i, j, counter, num;
  object *ob;
  string tmp1, tmp2;
  string verb;
  object env, dest;


  ob = ({ });
  verb = query_verb();


  /* if we don't have anything to sort, return nothing! */
  if(!sizeof(items) || !items) {
    notify_fail("There is nothing like that here.\n");
    return 0;
  }

  num = items[0];



  if(!prep && container) prep = "from";

  if(prep && !container) {
    if(sscanf(msg, "%s "+prep+" %s", tmp1, tmp2)) {
      if(present(tmp2, environment(this_player()))) /* whoever called this fn */
        container = present(tmp2, environment(this_player()));
      else if(present(tmp2, this_player()))
        container = present(tmp2, this_player());
    }
  }

  if(!container) {
    if(default_container) container = default_container;
  }


  for(i=1; i<sizeof(items); i++) {

    /* get a counting of items */
    if(num > 0) {
      if(container)
        if(!present(items[i], container)) continue;
      if(++counter > num) break;
      ob += ({ items[i], });
    }

    /* get the counter'th item */
    else if(num < 0) {
      if(container)
        if(!present(items[i], container)) continue;
      counter--;
      if(counter == num) {
        ob += ({ items[i], });
        break;
      }
    }
    else {
      if(container) {
        if(present(items[i], container)) {
          ob += ({ items[i], });
        }
      }
      else {
        ob += ({ items[i], });
      }
    }
  }

  if(!sizeof(ob)) {
    tell_object(this_player(), "There's nothing there!\n");
    return 0;
  }

  env = environment(ob[0]); /* 1st item in array */
  if(container) dest = container; else dest = this_player();

  return ([ 	"ob" 		: ob, 
		"prep" 		: prep, 
		"container"	: container,
		"environment"	: env,
		"destination"	: dest,
  ]);
}

/* action bin for pick/get/etc... for parse_command */

/******************************************************************************
 * The ACTIONS object. v2.0
 *
 * In conjunction with the parse.c/parse_old.c object from the driver we can
 * get items we never could before!
 * Check also the command_centre in player.c
 * Angel. Aug, '96
 */

#include <mudlib.h>
#include <i_to_str.h>


#define SEC (int)this_player()->query_security_level()
#define AMT_MONEY  (int)this_player()->query_money()
#define NAME       (string)this_player()->query_name()
#define LEVEL      (int)this_player()->query_level()

/*
put x in y -> give x to y
get (or pick_up) x from y
give x to y 
drop_thing (x) (in y)
*/

/******************************************************************************
 * get x FROM y (a room or bag) and put them in me! 
 */

status get_things(object *items, string prep, object container) {
  int i, abort, wt, haveGet;
  string from, item_name;

  this_player()->recalc_carry();


  if(this_player()->query_ghost()) {
    tell_object(this_player(),"It passes straight through your hands...\n");
    return 1; 
  } 

  if((int)this_player()->query_real_light() < 1) {
    tell_object(this_player(), "It's too dark to do that.\n");
    return 1;
  }

  if(!prep) {
    switch(query_verb()) {
      case "get" : case "take" : prep = "from"; break;
      default : prep = "from"; break;
    }
  }
  if(container && !sizeof(items)) {
    write("That's not in "+lower_case(container->short())+"\n");
    return 1;
  }

  if(!sizeof(items)) {
    tell_object(this_player(),"Usage: get <item|all>\n"+
    "       get <item|all> from <container>\n"); 
    return 1; 
  } 
  
  if(container) {
    if(living(container)) {
      write("I don't think "+container->short()+" will give that away.\n");
      return 1;
    }
  }
  if(!container) {
    container = environment(this_player());
  }


  if(!container->can_put_and_get(0)) {
    tell_object(this_player(),"You can't get anything from that!\n");
    return 1;
  }


  for(i=0; i<sizeof(items); i++) {
    if(items[i] == this_player()) continue;
    if(!items[i]->get()) {
      write(items[i]->short()+" won't budge a millimeter!\n");
      continue; 
    }
    if(present(items[i], this_player())) continue; /* dont get what we have! */
    if(!objectp(items[i]) || items[i]->query_npc() || items[i]->id("PLAYER")) {
      write(items[i]->short()+" wouldn't be too happy about that.\n");
      continue;
    }
    if(living(environment(items[i])) && 
      present(items[i], environment(items[i]))) {
      continue;
    }

    if(!(item_name = (string)items[i]->short())) continue;

    item_name = lower_case(item_name);

    if(++abort > 30) {
      tell_object(this_player(), "You "+query_verb()+" only "+int_to_str(30)+
      " "+items[i]->query_short()+"\n");
      return 1;
    }

    wt = (int)items[i]->query_weight();
    if(!this_player()->add_weight(wt)) {
      write("You're not strong enough to carry "+ item_name +".\n");
      say(NAME+" attempts to carry "+item_name+".\n"); 
      break;
    }

    environment(items[i])->add_weight(-wt);
      
/* move it to me! */
    move_object(items[i], this_player());

    item_name = lower_case(item_name);
    if(environment(this_player()) == container) {
      write("You "+query_verb()+" "+ item_name +".\n");
      say(NAME+" "+query_verb()+"s "+ item_name +".\n");
      haveGet = 1;
    }
    else {
      write("You "+query_verb()+" "+item_name+" "
	+prep+" "+container->short()+"\n");
      say(NAME+" "+query_verb()+"s "+item_name+" "
	+prep+" "+container->short()+"\n");
      haveGet = 1;    
    } 
  }
  if(!haveGet)  {
    tell_object(this_player(), capitalize(query_verb())+" what? "+
    "You move the air about.\n");
  }
  return 1;
}


/* put something in something else */
status drop_things(object *items, string prep, object container) {
  int i, abort, wt, haveGive;
  string from, item_name;

  this_player()->recalc_carry();
  if(!prep) {
    switch(query_verb()) {
      case "drop" : prep = "in"; break;
      case "give" : prep = "to"; break;
      default : prep = "to"; break;
    }
  }



  if(this_player()->query_ghost()) {
    tell_object(this_player(),"It passes straight through your hands...\n");
    return 1; 
  } 

  if((int)this_player()->query_real_light() < 1) {
    tell_object(this_player(), "It's too dark to do that.\n");
    return 1;
  }

  if(!sizeof(items)) {
    tell_object(this_player(),"Usage: put|drop <item|all>\n"+
    "       put|drop <item|all> in <container>\n");
    return 1; 
  } 
  

  if(!container) container = environment(this_player());
  for(i=0; i<sizeof(items); i++) {
    if(items[i] == container) {
      write("You can't do that.\n");
      continue; 
    }

    if(!objectp(items[i]) ||
        items[i]->id("PLAYER") ||
       items[i]->query_npc()) continue;
    if(!(item_name = (string)items[i]->short())) continue; /* no move invis  */

    if(!present(items[i], this_player())) {
      continue;
    }

    if(++abort > 30) {
      tell_object(this_player(), "You "+query_verb()+" only "+int_to_str(30)+
      " "+items[i]->query_short()+"\n");
      return 1;
    }

    item_name = (string)items[i]->short();
    item_name = lower_case(item_name);

    if((this_player() == environment(items[i]) && items[i]->drop()) ||
      (this_player() != environment(items[i]) && !items[i]->get())) {
      write ("You cannot "+query_verb()+" "+ item_name +".\n");
      continue;
    } 
     
    wt = (int)items[i]->query_weight();
    if(!container->add_weight(wt)) {
      write(container->short()+" cannot carry "+ item_name +".\n");
      say(NAME+" attempts to "+query_verb()+" "+ item_name +" "+prep+" "+
               container->short()+".\n", container); 
      tell_object(container,NAME+" trys to "+query_verb()+" you "+ item_name
                           +" but you cannot carry it.\n");
      break;
    }

    if(!container->can_put_and_get(0) &&
      (string)query_verb() != "give") {
        tell_object(this_player(),"You cannot do that!\n");
        return 1;
    }

    environment(items[i])->add_weight(-wt);
      


    move_object(items[i], container);


    if(container == this_player()) {
      write("You "+query_verb()+" "+item_name+" "+prep+" yourself.\n");
      say(NAME+" "+query_verb()+"s "+ item_name+" "+prep+" "+
      (string)this_player()->query_objective()+"self.\n");
      haveGive = 1;
    }
    else {
      if(!living(container))
      {
      write("You "+query_verb()+" "+item_name+" "+prep+" "+
          lower_case(container->short())+"\n");
      say(NAME+" "+query_verb()+"s "+ item_name +" "+ prep +" "+
        lower_case(container->short())+"\n", container);
      }
      else {
        write("You "+query_verb()+" "+item_name+" "+prep+" "+
         container->short()+".\n");
        say(NAME+" "+query_verb()+"s "+item_name+" "+prep+" "+
          container->short()+"\n", container);
      }
      tell_object(container, NAME+" "+query_verb()+"s you "+item_name+"\n");
      haveGive = 1;    
    }
  } 

  if(!haveGive) {
    tell_object(this_player(), capitalize(query_verb())+
    " What? You move the air about.\n");
  }
  return 1;
}

string query_object_type() { return "Actions"; }

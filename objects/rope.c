#include <mudlib.h>
inherit TREASURE;

string tied_to;
object tied_to_ob;

void reset(status arg) {
  if(arg) return;

  set_name("rope");
  set_plural("ropes");
  set_weight(1);
  set_value(15);
}

string short(status wiz) {
  if(tied_to)
    return "A rope tied to " + tied_to;

  return "A rope";
}

void long(status wiz) {
    write("A large thick rope made from hemp.\n");
} 

status get() {
  if(tied_to) {
    notify_fail("The rope is tied to " + tied_to + ".\n");
    return 0;
  }
  return 1;
}



void init() {
    add_action("tie", "tie");
    add_action("untie", "untie");
}   

status tie(string str) {
  string t1, t2;
  object ob;

  if(!str) return 0;

  if(tied_to) {
    notify_fail("It is already tied to " + tied_to + ".\n");
    return 0;
  }

  if(sscanf(str, "%s to %s", t1, t2) != 2) return 0;

  if(!id(t1)) return 0;

  if(t2 == "me") {
    notify_fail("Why would you do that ?\n");
    return 1;
  }

  ob = present(t2, this_player());
  if(!ob) ob = present(t2, environment(this_player()));

  if(!ob) {
    if(call_other(environment(this_player()), "id", t2))
    ob = environment(this_player());
  }

  if(!ob) {
    notify_fail("Tie the rope to what?\n");
    return 0;
  }

  if(!call_other(ob, "tie", t2)) {
    write("You can't tie the rope to " + t2 + ".\n");
    return 1;
  }
  /* Is he carrying the rope ? */
  if(environment() == this_player()) {
    move_object(this_object(), environment(this_player()));
    call_other(this_player(), "add_weight", - query_weight());
  }

  tied_to = t2;
  tied_to_ob = ob;
  write("You tie the "+query_name()+" to "+ t2 +".\n");
  say(this_player()->query_name() +" ties the "+ query_name() +" "+
        t2 + ".\n");
    return 1;
}

status untie(string str) {
  if(!id(str)) return 0;

  if(!tied_to) {
    notify_fail("The "+query_name()+" is not tied to anything.\n");
    return 0;    
  }
  if(!call_other(tied_to_ob, "untie")) {
    notify_fail("The "+query_name()+" won't untie.\n");
    return 0;
  }

  write("You untie the "+query_name()+" from the "+ tied_to +".\n");
  tied_to = 0;
  tied_to_ob = 0;
  return 1;
}  
                                     
                                          



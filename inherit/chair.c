#include <mudlib.h>
inherit TREASURE;

#define NAME (string)this_player()->query_name()
#define CAP  (string)this_player()->query_cap_name()

static string *sitters;
static int max_sitters;



int set_max_sitters(int i) { return max_sitters = i;  }
int query_max_sitters()    { return max_sitters;      }


string *set_sitters(string *arg) { return sitters = (arg) ? arg : ({}); }
string *query_sitters()          { return sitters;                      }



void reset(status arg) {
  if(arg) return;
  sitters = ({});
  set_name("chair");
  set_short("A chair");
  set_long("A small wooden chair.\n");
  set_value(10);
  set_weight(3);
}



status query_sitter(string str) {
  return (member_array(str, sitters) != -1) ? 1 : 0;
}


void remove_sitter(string str) {
  int i;

  if((i == member_array(str, sitters)) == -1) return;
  sitters = sitters[0..i-1]+sitters[i+1..sizeof(sitters)-1];
}


void resolve_sitters() {
  int i;
  string *tmp_sitters;

  tmp_sitters = sitters;
  for(i = sizeof(sitters); i--; ) {
    if(!present(lower_case(tmp_sitters[i]), environment())) {
      remove_sitter(tmp_sitters[i]);
    }
  }
}


string short(status wiz) {
  resolve_sitters();
  return ::short(wiz) + ((!sizeof(sitters))
                      ? ""
                      : (sizeof(sitters) == 1)
                      ? " with "+ sitters[0] +" sitting on it"
                      : " with "+ implode(sitters[0..sizeof(sitters)-2],", ")
                       +" and "+ sitters[sizeof(sitters)-1] 
                       +" sitting on it");
}



void long(status wiz) {
  string tmp;

  ::long(wiz);
  resolve_sitters();
  if(sizeof(sitters)) {
    write("On the "+ query_name() +" you see"+
          ((sizeof(sitters) == 1)
           ? " "+ sitters[0] +" sitting on it.\n"
           : " with "+ implode(sitters[0..sizeof(sitters)-2],", ")
            +" and "+ sitters[sizeof(sitters)-1] +" sitting on it.\n"));
  }
}
    

void init() {
  if(!max_sitters) max_sitters = 1;
  resolve_sitters();

  add_action("sit", "sit");
  add_action("stand", "stand");
  add_action("com_hook", "", 1);
}


status get() {
  resolve_sitters();
  if(sizeof(sitters)) {
    write("There are people sitting on the "+ query_name() +".\n");
    return 0;
  }
  return 0;
}

status look_at(string str) {
  if(!str) return 0;
  str = capitalize(str);
  if(!sitters) sitters = ({});
  if(member_array(str,sitters) != -1) {
    command("look at "+ lower_case(str), this_player());
    return 1;
  }
  return 0;
}


status sit(string str) {
  object obj;
  string tmp1, tmp2;

  if(!str) {
    notify_fail("Sit where?\n");
    return 0;
  }
  if(this_player()->query_chair_object()) {
    notify_fail("You're already sitting on something!\n");
    return 0;
  }

  sscanf(str, "on %s", str);
  sscanf(str, "in %s", str);
  obj = present(lower_case(str), environment(this_player()));
  if(obj != this_object()) return 0;
  if(query_sitter(CAP)) {
    write("You're already sitting on the "+ query_name() +".\n");
    return 1;
  }
  if(sizeof(sitters) >= max_sitters) {
    write("There are already too many people sitting there.\n");
    return 1;
  }
  write("You sit on the "+ query_name() +".\n");
  if(!this_player()->query_stealth_on()) {
     say(NAME +" sits on the "+ query_name() +"\n");
  }
  sitters += ({ CAP, });
  clone_object("obj/shadows/chair_sd")->shadow_short();  
  return 1;
}


status stand(string str) {
  if(str && str != "up") {
    notify_fail("Perhaps you should stand up.\n");
    return 0;
  }
  if(query_sitter(CAP)) {
    remove_sitter(CAP);
    write("You get up from the "+ query_name() + ".\n");
    return 1;
  }
  return 0;
}


status com_hook() {
  string verb;
  string *exits;
  verb = query_verb();
  exits = (string *)environment()->query_exits();
  if(!exits || !sizeof(exits)) return 0;

  if(member_array(verb, exits) != -1) {
    if(query_sitter(this_player()->query_name())) {
      write("Perhaps you should stand first?\n");
      return 1;
    }
  }
}


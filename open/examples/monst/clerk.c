#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  set_name("clerk");
  set_short(0);
  set_long(0);
}

void attack() { return; }

void init() {
  ::init();
  if(this_player()->id("PLAYER")) 
    call_out("clerk", 1, this_player());
}

void clerk(object obj) {
  if(!environment()) return;
  if(!obj || !present(obj, environment()))
    return;

  tell_room(environment(),
	"Clerk says: Is there anyone you need to locate?\n");
}

void catch_tell(string str) {
  string tmp1, tmp2;
  object obj, room;

  if(sscanf(str, "%s says: locate %s\n", tmp1, tmp2)) {
    tmp2 = extract(tmp2,0,(strlen(tmp2)-2));
    if(!obj=find_living(lower_case(tmp2))) {
      tell_room(environment(), "Clerk says: I dont know where "+
	capitalize(tmp2)+" is.\n");
    }
    else if(obj->query_security_level() ||
            obj->query_spell_immune("scry")) {
      tell_room(environment(), "Clerk says: I believe "+
	obj->short()+" is out of range at this time.\n");
    }
    else {
      tell_room(environment(), "Clerk says: "+obj->short()+
        " is in "+lower_case(environment(obj)->short()) +".\n");
    }
  }
  ::catch_tell(str);
}

    


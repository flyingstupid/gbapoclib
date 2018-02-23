#include <mudlib.h>
inherit MONSTER;


string *names;
mapping messages;

void remove_messages(string str);

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("bill");
  set_heart_ob(this_object());

  names = ({ });
  messages = ([]);
}

void monster_heart_beat() {
  int jj;
  object ob;

  for(jj=0; jj<sizeof(names); jj++) {
    if(ob=present(names[jj]), environment()) {
      tell_object(ob, query_name()+" whispers to you: "+
        messages[names[jj]]+".\n");
      say(query_name()+" whispers to "+ob->query_name()+".\n", ob);
      remove_messages(names[jj]);
    }
  }
}

void remove_message(string str) {
  if((i = member_array(str, names)) != -1) 
    names = names[0..i-1] + names[i+1..sizeof(names)-1];
  messages[str] = 0;
}

void init() {
  ::init();
  add_action("whisper", "whisper");
}

status whisper(string str) {
  string tmp1, tmp2, tmpName;

  if(!sscanf(str, "tell %s %s\n", tmpName, tmp2)==2) {
    write(query_name()+" whispers to you: tell <who> <what>?\n");
    return 1;
  }
  write(query_name()+" says: If I see "+tmpName+" I will relay the message.\n");
  tmpName = lower_case(tmpName);
  messages[tmpName] = tmp2;
  return 1;
}

mapping query_messages() { return messages; }
string *query_names()    { return names;    }


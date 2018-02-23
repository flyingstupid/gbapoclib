/* charm object */

#define NAME           (string)this_player()->query_name()
#define CHARMED_WISDOM (int)charmed->query_wisdom()+1
#define CHARISMA       (int)this_player()->query_charisma()+1

object charmed;
object follow;
string name;
int no_get, no_kill, no_drop, no_follow;

void reset(status arg) {
  if(arg) return;
  no_kill   = -1;
  no_get    = -1;
  no_drop   = -1;
  no_follow = -1;
}

void set_no_kill(status arg)   { no_kill = arg; }
void set_no_get(status arg)    { no_get = arg; }
void set_no_drop(status arg)   { no_drop = arg; }
void set_no_follow(status arg) { no_follow = arg; }

int query_no_kill()   { return no_kill; }
int query_no_get()    { return no_get;  }
int query_no_drop()   { return no_drop; }
int query_no_follow() { return no_follow; }

  
status id(string str) {
  return str == "spell"
      || str == "charm";
}

status drop(status quit) {
  return 1;
}
     

void set_charmed(object ob) {
  if(!(charmed = ob)) return;
  if(!(name = (string)ob->query_name())) {
    ob = 0;
    return;
  }
  name = capitalize(name);
}

void init() {
  if(!name) return;
  add_action("charm_commands", lower_case(name));
  add_action("charm_commands", name);
}


status charm_commands(string str) {
  string arg;
   object ob;

  if(!charmed) {
    destruct(this_object());
    return 0;
  }
  if(!present(charmed, environment(this_player()))) {
    notify_fail(name +" is not here.\n");
    return 0;
  }
  if(!str) {
    notify_fail(name +" what?\n");
    return 0;
  }
  sscanf(str, "%s %s", str, arg);
  switch(str) {
    case "kill":
      if(no_kill) {
        if(no_kill == 1 || random(CHARMED_WISDOM) > random(CHARISMA)) {
          write(name +" refuses to do that!\n");
          no_kill = 1;
        }
        else {
          no_kill = 0;
        }
      }
      if(!no_kill) {
        if(!arg) {
          write(name +" looks aggressive.\n");
          say(name +" puffs up and looks aggressive.\n");
        }
        else if(!(ob = present(arg, environment(this_player())))) {
          write(name +" looks behind you and doesn't see "+ arg +".\n");
          say(name +" starts looking for "+ arg +".\n");
        }
        else if(!living(ob)) {
          tell_room(environment(this_player()),name +" picks up the "+ arg
                 +" gives it a shake, then drops it.\n");
        }
        else if(charmed->query_secondary_attacker(ob)) {
          write(name +" gives an extra aggressive attack.\n");
        }
        else {
          tell_room(environment(this_player()),
            name +" leaps upon "+ arg +".\n");
          charmed->add_secondary_attacker(ob);
        }
      }
     
    break;

    case "get":
      if(no_get) {
        if(no_get == 1 || random(CHARMED_WISDOM) > random(CHARISMA)) {
          write(name +" refuses to do that!\n");
          no_get = 1;
        }
        else {
          no_get = 0;
        }
      }
      if(!no_get) {
        if(!arg) {
          tell_room(environment(this_player()),
            name +" drops to the ground.\n");
        }
        else if((ob = present(arg, environment(charmed)))) {
          if(ob->get()) {
            if(charmed -> add_weight((int)ob->query_weight())) {
              tell_room(environment(this_player()),
                name +" gets the "+ arg +".\n");
              move_object(ob, charmed);
            }
            else {
              write(name +" tries, but can't carry it.\n");
            }
          }
          else {
            write(name +" trys but can't get it.\n");
          }
        }
        else {
          tell_room(environment(charmed),name +" looks around for the "+
            arg +".\n");
        }
      }
    break;


    case "drop":
      if(no_drop) {
        if(no_drop == 1 || random(CHARMED_WISDOM) > random(CHARISMA)) {
          write(name +" refuses to do that!\n");
          no_drop = 1;
        }
        else {
          no_drop = 0;
        }
      }
      if(!no_drop) {
        if(!arg) {
          tell_room(environment(this_player()),
            name +" drops to the ground.\n");
        }
        else if((ob = present(arg, charmed))) {
          if(!ob->drop()) {
            tell_room(environment(this_player()),
              name +" drops the "+ arg +".\n");
            move_object(ob, environment(charmed));
            charmed->add_weight((int)ob->query_weight()*(-1));
          }
          else {
            write(name +" refuses to drop it.\n");
          }
        }
        else {
          tell_room(environment(charmed),name +" looks around for the "+
            arg +".\n");
        }
      }
    break;

    case "follow":
      if(no_follow) {
        if(no_follow == 1 || random(CHARMED_WISDOM) > random(CHARISMA)) {
          write(name +" refuses to do that!\n");
          no_follow = 1;
        }
        else {
          no_follow = 0;
        }
      }
      if(!no_follow) {
        follow = clone_object("obj/shadows/follow");
        follow->follow(this_player(),charmed);
        write(name +" waits for you to leave.\n");
        say(name +" watches "+ NAME +" closely.\n");
      }
    break;

    case "stay":
      if(!follow) {
        write(name +" is not following you.\n");
      }
      else {
        destruct(follow);
        tell_room(environment(this_player()),name +" gives up the chase.\n"); 
      }
    break;


    default:
      if(!command(str +" "+ arg, charmed)) {
        write(name +" looks at you in a confused mannor.\n");
        say(name +" looks at "+ NAME +" in a confused mannor.\n");
      }
    break;
  }
  return 1;
}


    


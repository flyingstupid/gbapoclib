/* War Dog 
 * v1.0 Angel June 1996
 *
 * v1.1 Angel Oct  1998
 * Additions include:
 *    Update to include animal handling skill
 */

#include <mudlib.h>
 
#define FOLLOW           "obj/shadows/follow"
#define NAME             (string)this_player()->query_name()
#define DIFFICULTY       15                          /* chance to control dog  */
#define MY_STAT          animal_handling             /* player's general skill */

/*
#define USE_ANIMAL_HANDLING_SKILL 
*/

inherit MONSTER;


string owner, extra_name;
int heal_counter;
object follow;

 
void reset(status arg) {
  object ob;
  ::reset(arg);
 
 
  if(arg) return;
 
  if(!present("collar")) {
    ob = clone_object(CLOTHING);
    ob -> set_name("collar");
    ob -> set_short("a studded collar");
    ob -> set_long(
        "It looks like something a trained dog would wear.\n");
    ob -> set_value(10);
    ob -> set_weight(1);
    move_object(ob, this_object());
    init_command("wear collar");
  }
 
  set_name("dog");
  set_alias("dog");
  set_short("A Dog");
  set_long("A fierce war dog, trained for battle.\n");
  set_race("dog");
 
  load_chat(5, ({ "Dog sniffs the ground.\n",
        "Dog sniffs you.\n",
        "Dog listens carefully.\n",
        "Dog barks a warning.\n",
        "Dog growls angrily.\n",
  }));
 

  load_a_chat(5, ({
        "Dog barks loudly!\n",
        "Dog barks angrily.\n",
        "Dog howls.\n",
  }));
 
  set_attack_msg(({
        "licks",        "hungrily",
        "brushes",      "lightly, with a bite",
        "grazes",       "lightly, with a bite",
        "mauls",        "",
        "rakes",        "with it's claws",
        "crunches",     "with a viscious bite",
        "devistates",   "with it's powerful jaws",
  }));
  set_dead_ob(this_object());
  set_level(5);
  set_max_hp(150);
  set_hp(150);
  set_ac(6);
  set_wc(12);  /* fierce doggy! */
  set_gender(2);
 
  set_msgin("wanders in");
  set_msgout("wanders out");
 
  set_heart_ob(this_object());
 
  move_object(clone_object("obj/soul"), this_object());
}
 


void monster_heart_beat() {
  object ob;
  object *inv;
  int i;
 
  inv = all_inventory(this_object());
  if(heal_counter)
    if(!random(15)) heal_counter --;
  for(i=0; i<sizeof(inv); i++) {
    if((string)inv[i]->query_object_type() == "Food") {
       if(heal_counter > 20) {
         say(query_name()+" looks a little full right now.\n");
         say(query_name()+" drops the "+inv[i]->query_name()+"\n");
         move_object(inv[i], environment());
         break;
       }
       else {
         say(query_name()+" eats the "+inv[i]->query_name()+"\n");
         heal_self(inv[i]->query_strength());
         heal_counter += (int)inv[i]->query_strength();
         add_weight(-(inv[i]->query_weight()));
         destruct(inv[i]);
         break;
       }
    }
    else
    if((string)inv[i]->query_object_type() == "Drink") {
       if(heal_counter > 20) {
         say(query_name()+" looks a little full right now.\n");
         say(query_name()+" drops the "+inv[i]->query_name()+".\n");
         move_object(inv[i], environment());
         break;
       }
       else {
         say(query_name()+" drinks the "+inv[i]->query_name()+"\n");
         heal_self(inv[i]->query_strength());
         heal_counter += (int)inv[i]->query_strength();
         add_weight(-(inv[i]->query_weight()));
         destruct(inv[i]);
       }
    }
  }
 
  if(!find_player(owner)) {
    tell_room(environment(), "Dog goes off to find it's owner.\n");
    if(ob = present("collar")) destruct(ob);
    destruct(this_object());
  }
}
 

void monster_died() {
  tell_room(environment(), query_name()+" falls to the ground...\n");
}
 
 
void check_for_owner();
 
void init() {
  if(!extra_name) extra_name = query_name();
  /* taken from the charm_ob.c funs ...owner doesnt need to persuade it */
  add_action("animal_commands", query_name(1));
  add_action("animal_commands", query_name());
  add_action("animal_commands", query_alias());
  add_action("animal_commands", extra_name);
 
  check_for_owner();
  ::init();
}


void check_for_owner() {
  if(!present(owner, environment()))
    destruct(this_object());
}
 
void long(status wiz) {
  ::long(wiz);
  if(owner)
    write("Dog's owner is "+capitalize(owner)+", who calls "+
        this_object()->query_possessive()+" "+extra_name+".\n");
}
 

status animal_not_obey() {
#ifdef USE_ANIMAL_HANDLING_SKILL
  if(random(CHANCE) > random((int)owner->query_animal_handling())) {
    write(query_name()+" barks, refusing to obey.\n");
    return 1;
  }
  return 0;
#else
  return 0;
#endif /* USE_ANIMAL_HANDLING_SKILL */
}
    
 
status animal_commands(string str, status forced) {
  string arg;
  object ob, *obj;
  object another_dog;
  int i;
 
  if(!forced && (string)this_player()->query_name(1) != owner) return 0;
 
  if(!str) {
    notify_fail(query_name(1) +" what?\n");
    return 0;
  }
  sscanf(str, "%s %s", str, arg);
 
  switch(str) {
    case "name" :
      if(!arg) {
        write(query_name()+" looks up at you expectantly.\n");
        break;
      }
      extra_name = capitalize(arg);
      write(query_name()+" will now answer to '"+extra_name+"'\n");
      another_dog = clone_object("objects/dog");
      another_dog -> set_name(lower_case(arg));
      another_dog -> set_short("A war dog, named "+capitalize(arg));
      another_dog -> load_a_chat(5, ({
                        capitalize(arg) +" barks loudly!\n",
                        capitalize(arg) +"barks angrily.\n",
                        capitalize(arg) +"howls.\n",
      }));

      another_dog -> load_chat(5, ({ capitalize(arg)+" sniffs the ground.\n",
                        capitalize(arg) +" sniffs you.\n",
                        capitalize(arg) +" listens carefully.\n",
                        capitalize(arg) +" barks a warning.\n",
                        capitalize(arg) +" wags her tail.\n",
                        capitalize(arg) +" growls angrily.\n",
      }));
 
      another_dog -> set_alias("dog");
      another_dog -> set_owner(this_player()->query_name(1));
      move_object(another_dog, environment());
      if(ob = present("collar")) destruct(ob);
      destruct(this_object());
 
      break;
 
    case "say" :
      if(animal_not_obey()) return 1;
      write(query_name()+" barks!\n");
      say(query_name()+" barks!\n", this_player());
    break;

 
    case "kill":
      if(animal_not_obey()) return 1;
      if(!arg) {
        write(this_object()->query_name() +" looks aggressive.\n");
        say(this_object()->query_name() +" puffs up and looks aggressive.\n");
      }
      else if(!(ob = present(arg, environment(this_player())))) {
        write(this_object()->query_name() +" looks behind you and doesn't "+
          "see "+ arg +".\n");
        say(this_object()->query_name() +" starts looking for "+ arg +".\n");
      }
      else if(!living(ob)) {
        tell_room(environment(this_player()),this_object()->query_name()+
          " picks up the "+arg+" gives it a shake, then drops it.\n");
      }
      else if(this_object()->query_secondary_attacker(ob)) {
        write(this_object()->query_name()+
               " gives an extra aggressive attack.\n");
      }
      else {
        tell_room(environment(this_player()),
            this_object()->query_name()+" leaps upon "+ arg +".\n");
        this_player()->add_secondary_attacker(ob);
        this_object()->add_secondary_attacker(ob);
      }
    break;
 
    case "get":
      if(animal_not_obey()) return 1;
      if(!arg) {
        tell_room(environment(this_player()),
            this_object()->query_name() +" drops to the ground.\n");
      }
      if(arg == "all") {
        obj = all_inventory(environment());
        for(i=0; i<sizeof(obj); i++) {
           if(obj[i]->short())
             animal_commands("get "+obj[i]->query_name(), 1);
        }
      }
      else if((ob = present(arg, environment(this_object())))) {
        if(ob->get()) {
          tell_room(environment(this_player()),
            this_object()->query_name() +" gets the "+ arg +".\n");
          move_object(ob, this_object());
          this_object()->add_weight((int)ob->query_weight());
        }
        else {
          write(this_object()->query_name() +" trys but can't get it.\n");
        }
      }
      else {
        tell_room(environment(this_object()),this_object()->query_name() +
            " looks around for the "+arg+".\n");
      }
    break;
 
 
    case "drop":
      if(animal_not_obey()) return 1;
      if(!arg) {
        tell_room(environment(this_player()),
            this_object()->query_name() +" drops to the ground.\n");
      }
      if(arg == "all") {
        obj = all_inventory(environment());
        for(i=0; i<sizeof(obj); i++) {
           if(obj[i]->short())
             animal_commands("drop "+obj[i]->query_name(), 1);
        }
      }
      else if(ob = (present(arg, this_object()))) {
        if(!ob->drop()) {
          tell_room(environment(this_player()),
              this_object()->query_name()+" drops the "+ arg +".\n");
          move_object(ob, environment(this_object()));
          this_object()->add_weight((int)ob->query_weight()*(-1));
        }
        else {
          write(this_object()->query_name() +" refuses to drop it.\n");
        }
      }
      else {
        tell_room(environment(this_object()),
               this_object()->query_name() +" looks around for the "+
                 arg +".\n");
      }
    break;
 
    case "follow":
      if(animal_not_obey()) return 1;
       if(this_player()->query_followers(this_object())) {
         write(this_object()->query_name()+" is already "+
        "following you.\n");
        break;
      }
      write(query_name()+" waits for you to leave.\n");
      this_player()->add_followers(this_object());
 
      say(this_object()->query_name() +" watches "+ NAME +" closely.\n",
          this_player());
    break;
 
    case "stay":
      if(animal_not_obey()) return 1;
      if(!this_player()->query_followers(this_object())) {
        write(this_object()->query_name() +" is not following you.\n");
      }
      else {
        this_player()->remove_followers(this_object());
        tell_room(environment(this_player()),
               this_object()->query_name() +" gives up the chase.\n");
      }
    break;
 
    case "wear":
      if(animal_not_obey()) return 1;
      write(this_object()->query_name()+" can't wear anything!\n");
    break;
 
    case "wield":
      if(animal_not_obey()) return 1;
      write(this_object()->query_name()+" can't wield anything!\n");
    break;
 
    case "leave":
      if(animal_not_obey()) return 1;
      say(this_object()->query_name()+" runs off into the distance.\n");
      destruct(this_object());
    break;
 
    case "wag":
      if(animal_not_obey()) return 1;
      say(query_name()+" wags "+query_possessive()+" tail happily.\n");
    break;
 
    default:
      if(animal_not_obey()) return 1;
      if(!command(str +" "+ arg, this_object())) {
        write(this_object()->query_name()
               +" looks at you in a confused mannor.\n");
        say(this_object()->query_name() +
          " looks at "+ NAME +" in a confused mannor.\n", this_player());
      }
    break;
  }
  return 1;
}
 

string set_owner(string str) {
  return owner = str;
}
 

string query_owner() { return owner; }



#include <mudlib.h>
inherit MONSTER;

#define NAME             (string)this_player()->query_name()
#define LEVEL            (int)this_player()->query_level()
#define MY_STAT          17
#define YOUR_STAT        (int)this_player()->query_charisma()
#define ROOM_MOD         200


/****************************************************************************/
/* Fn prototypes */
void check();
void make_doors(string str, object obj);
status rent_room();
int room_cost();


int counter, i;

void reset(status arg) {
  string *rooms;
  if(!present("dagger")) {
    move_object(clone_object("room/city/obj/dagger"),this_object());
  }
  set_wc(30);

  ::reset(arg);
  init_command("wield dagger");
 
  rooms = ({ 
     "/room/city/pub/inn1",
     "/room/city/pub/inn2", 
     "/room/city/pub/inn3", 
     "/room/city/pub/inn4", 
     "/room/city/pub/hall1",
     "/room/city/pub/hall2",
     "/room/city/pub/hall3",
     "/room/city/pub/hall4",
  });
     
  /* initialise the rooms for rent */
  for(i=0; i<sizeof(rooms); i++) {
    call_other(rooms[i], "reset", 1);
  }

  if(arg) return;
  counter = 0;

  set_name("samantha");
  set_alias("thief");
  set_short("Samantha, the Grandmaster Thief");
  set_long(
     "Her short brown hair and dark seductive eyes and smile makes \n"+
     "her renowned across the city as a man killer. No one can resist \n"+
     "this woman, no one dares to. No living man has ever known to   \n"+
     "say no to her. ");
  set_level(19);
  set_gender(2);
  set_race("human");

  set_hp(2100);
  set_wc(30);
  set_ac(15);
  add_class("fighter");
  add_class("mage");
  add_class("cleric");

  load_spells(10, ({ 
     "chain lightning",  "cure light wounds", "cure serious wounds",
     "burning hands", "comet", "ice storm", "disintegrate", "hold person",
     "vampiric touch",
  }));

  load_chat(7, ({ "Samantha asks: Would you like to spend the night here?\n",
     "Samantha looks you up and down with careful eyes.\n",
     "Samantha smiles at you seductively\n",
     "Samantha says: The rooms are up stairs, and are quite cheap.\n"
  }));

  load_a_chat(5, ({ "Samantha says: You shouldn't tangle with me.\n",
     "Samantha says: I wouldn't do that if I were you.\n",
     "Samantha asks: Feel like a bit of sport, hmm..?\n",
     "Samantha says: I'm stronger than you think.\n",
     "Samantha tumbles away from your blow.\n",
     "Samantha kicks you hard.\n",
     "Samantha punches you in the face.\n"
  }));


  for(i=0; i<4; i++) {
    object ob;
    ob = clone_object("room/city/pub/key");
    move_object(ob, this_object());
  }
}

void init() {
  check();
  ::init();
}

void catch_tell(string str) {
  string tmp1, tmp2;
  if(sscanf(str, "%s says: rent %s", tmp1, tmp2) ||
     sscanf(str, "%s says: room %s", tmp1, tmp2))
     rent_room();
}

/****************************************************************************/
/* Fns to rent rooms */
status rent_room() {
  object key, door;
  int cost;

  if(!present("key", this_object())) {
    tell_room(environment(), "Samantha says: Sorry "+ NAME +", but I don't "+
    "have any rooms left to rent.\n");
    return 1;
  }

  if(key = (present("key", this_player()))) {
    if(!counter) {
      if(key -> id(NAME)) {
        tell_room(environment(), "Samantha says: You've stolen one of "+
                    "my keys!\nSamantha snatches the key away!\n");
        destruct(key);
        return 1;
      }
    }
    if(environment() -> query_players(NAME)) {
      tell_room(environment(), "Samantha says: But "+NAME+", you already "+
                               "have rented a room.\n");
      return 1;
    }
  }
  tell_object(this_player(), "Samantha haggles with you over the price of "+
                         "a room.\n");

  cost = room_cost();

  if(random(MY_STAT) > random(YOUR_STAT))
    cost += random(cost) /3;
  else
    cost -= random(cost) /4;

  if(this_player()->query_money() < cost) {
    tell_room(environment(), "Samantha says: But you don't have "+
    cost +" copper coins for the room!\n");
    return 1;
  }

  tell_object(this_player(), 
          "Samantha takes "+ cost +" copper coins for the room.\n");

  this_player()->add_money(-cost);

  key = present("key", this_object());
  key -> set_alias(NAME);
  key -> set_number(counter + 1);


  if(!this_player()->add_weight(1)) {
    tell_room(environment(), "Samantha says: You cannot carry this key, "+
    NAME +", so I will just leave it here.\nSamantha drops a key.\n");
    move_object(key, environment(this_object()));
  }
  else {
    tell_object(this_player(), "Samantha gives you a key.\n");
    say("Samantha gives "+NAME+" a key.\n",this_player());
    move_object(key, this_player());
  }

  tell_object(this_player(), "You write your name in the inn's register.\n");
  say(NAME +" writes "+this_player()->query_possessive() +" name "+
  "in the inn's register.\n",this_player());

  make_doors(NAME, this_player());
  environment()->add_players(NAME);
  return 1;
}

int room_cost() {
  return ROOM_MOD * (int)this_player()->query_level();
}

void make_doors(string str, object obj) {

  counter++;  /* start off at room 1 */

  if(!present("key", this_object())) {
    write("Sam says: There's something wrong. I seem to have no vacancies "+
          "after all.\n");
    return;
  }


  call_other("/room/city/pub/inn"+counter, "load_door",
     ({ "file",      "room/city/pub/hall"+counter,
        "closed",
        "locked",
        "long",      "A door of solid oak.\n",
        "lock id",   "lock",
        "lock long", "A lock that bears the number "+counter+".\n",
        "key id",    (string)obj->query_name(),
        "lock difficult", 10 + (int)obj->query_level(),
        "direction", "east door",
     })
  );

  call_other("/room/city/pub/hall"+counter, "load_door",
     ({ "file",      "room/city/pub/inn"+counter,
        "closed",
        "locked",
        "long",      "A door of solid oak.\n",
        "lock id",   "lock",
        "lock long", "A lock that bears the number "+counter+".\n",
        "key id",    (string)obj->query_name(),
        "lock difficult", (int)obj->query_level(),
        "direction", "west door",
     })
  );
} 


void check() {
  object *obj;

  if(!counter) {
    if(present("key", this_player())) {

      obj = all_inventory(this_player());

      for(i=0; i<sizeof(obj); i++) {
         if(obj[i] -> id("skandles downfall")) {
           tell_room(environment(), 
               "Samantha says: Hey "+NAME+", how did you get that!\n");      
           say("Samantha snatches the key away from "+NAME+".\n",
               this_player());


           tell_object(this_player(), 
                    "Samantha snatches the key away from you!\n");
           destruct(obj[i]);
        }
      }
    }
  }
}

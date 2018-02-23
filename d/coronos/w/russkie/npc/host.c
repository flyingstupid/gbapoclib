/* Taken from sam.c (/room/city/pub) */
#include <mudlib.h>
#include <ansi.h>
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
  if(!present("dirk")) {
move_object(clone_object("/d/coronos/w/russkie/obj/dirk"),this_object());
  }
  set_wc(30);

  ::reset(arg);
  init_command("wield dirk");
 
  rooms = ({ 
     "/d/coronos/w/russkie/rooms/room1",
     "/d/coronos/w/russkie/rooms/room2",
     "/d/coronos/w/russkie/rooms/room3",
     "/d/coronos/w/russkie/rooms/room4",
     "/d/coronos/w/russkie/rooms/room5",
     "/d/coronos/w/russkie/rooms/hall1",
     "/d/coronos/w/russkie/rooms/hall2",
     "/d/coronos/w/russkie/rooms/hall3",
     "/d/coronos/w/russkie/rooms/hall4",
     "/d/coronos/w/russkie/rooms/hall5",
  });
     
  /* initialise the rooms for rent */
  for(i=0; i<sizeof(rooms); i++) {
    call_other(rooms[i], "reset", 1);
  }

  if(arg) return;
  counter = 0;

  set_name("beth");
  set_alias("elizabeth");
  set_short("Elizabeth, the Inn Hostess");
  set_long("\
The beauty of this young woman strikes you. Her deep green eyes assess\n\
you wearily, and the light shines off of her blond hair. Every now\n\
and then she looks at your money sack. You can tell she knows how\n\
to get what she wants, and what she wants is your money.\n");
  set_level(20);
  set_gender(2);
  set_race("human");

  set_wc(30);
  set_ac(17);
  add_class("mage");

  load_spells(10, ({ 
     "burning hands", "comet", "ice storm", "disintegrate", "hold person",
     "vampiric touch",
  }));

  load_chat(6, ({ "Elizabeth says: Please, call me Beth.\n",
    "Elizabeth asks: Would you like to rent a room?\n",
    "Elizabeth eyes your money hungrily.\n",
    "Elizabeth twirls her flaxen hair between long, slim fingers.\n",
  }));

    load_a_chat(8, ({ "Elizabeth growls and claws at you with her nails.\n",
      "Elizabeth stares at you in disbelief.\n",
      "Elizabeth says: My, have YOU made a mistake!\n",
      "Elizabeth whimpers: What did I do to YOU?\n",
  }));


  for(i=0; i<4; i++) {
    object ob;
    ob = clone_object("/d/coronos/w/russkie/obj/key");
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
    tell_room(environment(), "Beth says: Sorry "+ NAME +", but I don't "+
    "have any rooms left to rent.\n");
    return 1;
  }

  if(key = (present("key", this_player()))) {
    if(!counter) {
      if(key -> id(NAME)) {
      tell_room(environment(), "Beth says: You stole one of my keys! "+
                   "She growls!\nElizabeth grabs the key!\n");
        destruct(key);
        return 1;
      }
    }
    if(environment() -> query_players(NAME)) {
      tell_room(environment(), "Elizabeth laughs: "+NAME+", you already "+
                               "have rented a room.\n");
      return 1;
    }
  }
  tell_object(this_player(), "Elizabeth greedily haggles with you over "+
"the price of a room.\n");

  cost = room_cost();

  if(random(MY_STAT) > random(YOUR_STAT))
    cost += random(cost) /3;
  else
    cost -= random(cost) /4;

  if(this_player()->query_money() < cost) {
  tell_room(environment(), "Elizabeth smirks: You don't have "+ cost +" copper coins for the room hon!\n");
    return 1;
  }

  tell_object(this_player(), 
          "Elizabeth hungrily takes "+ cost +" copper coins for the room.\n");

  this_player()->add_money(-cost);

  key = present("key", this_object());
  key -> set_alias(NAME);
  key -> set_number(counter + 1);


  if(!this_player()->add_weight(1)) {
  tell_room(environment(), "Elizabeth laughs and says: Go lift some weight hon, you can't carry this\n\
key "+NAME+", I'll drop it here.\nElizabeth drops a key.\n");
    move_object(key, environment(this_object()));
  }
  else {
   tell_object(this_player(), "Elizabeth gives you your room key.\n");
    say("Elizabeth gives "+NAME+" a silver key.\n",this_player());
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
  write("Elizabeth says: There's something wrong. I seem to have no vacancies "+
          "after all.\n");
    return;
  }


  call_other("/d/coronos/w/russkie/rooms/room"+counter, "load_door",
     ({ "file",      "/d/coronos/w/russkie/rooms/hall"+counter,
        "closed",
        "locked",
         "long",     "A solid walnut door.\n",
        "lock id",   "lock",
        "lock long", "A lock that bears the number "+counter+".\n",
        "key id",    (string)obj->query_name(),
        "lock difficult", 10 + (int)obj->query_level(),
        "direction", "north door",
     })
  );

  call_other("/d/coronos/w/russkie/rooms/hall"+counter, "load_door",
      ({ "file",      "/d/coronos/w/russkie/rooms/room"+counter,
        "closed",
        "locked",
        "long",      "A solid walnut door.\n",
        "lock id",   "lock",
        "lock long", "A lock that bears the number "+counter+".\n",
        "key id",    (string)obj->query_name(),
        "lock difficult", (int)obj->query_level(),
        "direction", "south door",
     })
  );
} 


void check() {
  object *obj;

  if(!counter) {
    if(present("key", this_player())) {

      obj = all_inventory(this_player());

      for(i=0; i<sizeof(obj); i++) {
         if(obj[i] -> id("skyes tavern and inn")) {
           tell_room(environment(), 
          "Elizabeth shouts: HEY "+NAME+", how did you get that?\n");
           say("Elizabeth grabs a key away from "+NAME+" angrily.\n",
               this_player());


           tell_object(this_player(), 
     "Elizabeth grabs the key away from you and glares angrily.\n");
           destruct(obj[i]);
        }
      }
    }
  }
}

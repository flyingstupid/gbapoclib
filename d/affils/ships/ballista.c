/* A heavy balista, for use with the ships.
 * v2.01 Angel, Jan 1994
 */
#include <mudlib.h>

#define THACO                 10
#define NAME                  (string)this_player()->query_name()
#define FILE                  "/room/ships/open/types/"
#define DISTANCE              "/room/ships/distance"
#define MASTER_OB             "stern"
#define BALISTA_DAMAGE        20
#define OIL_DAMAGE            6
#define RANGE                 100

status loaded, aimed, oiled;
int distance, damage;
int *targ_coordinates, *my_coordinates;
string target;

inherit TREASURE;
void tell_other_rooms(string str1, string str2);
void reset(status arg) {
  if(arg) return;

  set_name("ballista");
  set_short("A light ballista");
  set_long(
     "A strange, almost large crossbow like weapon.\n");
  set_weight(10000);  /* don't carry it */
  set_value(100);
}

void long(status wiz) {
  ::long(wiz);
  if(loaded)
    write("The ballista is loaded, and ready to fire.\n");
  if(oiled && loaded)
    write("The ballista bolt is alight with flaming oil.\n");
}

void init() {
  ::init();
  if(!damage) damage = BALISTA_DAMAGE;

  add_action("arm_balista",  "arm" );
  add_action("arm_balista",  "load");
  add_action("aim_balista",  "aim" );
  add_action("fire_balista", "fire");
  add_action("oil_balista",  "oil" );
}

int set_damage(int i) { return damage = i; }

status oil_balista(string str) {
  object ob;

  if(!str) {
    write("Put oil on what?\n");
    return 1;
  }
  if(str != "ballista" && str != "ballista bolt") return 0;

  if(!present("oil", this_player())) {
    write("You don't have any oil.\n");
    return 1;
  }

  ob = present("oil", this_player());
  if(oiled) {
    write("The ballista bolt is already alight with oil.\n");
    return 1;
  }

  destruct(ob);
  write("You put oil on the ballista and light it.\n");
  say(NAME+" puts oil on the ballista bolt, and lights it.\n",this_player());
  oiled = 1; 
  return 1;
}


status arm_balista(string str) {
  object ob;
  int i;

  if(!str) {
    write("Arm what?\n");
    return 1;
  }

  if(str != "ballista") return 0;
  if(loaded) {
    write("The ballista is alreay armed.\n");
    return 1;
  }
  if(!present("ballista bolt", this_player())) {
    write("You need a ballista bolt to fire arm the ballista.\n");
    return 1;
  }

  ob = present("ballista bolt", this_player());
  destruct(ob);
  write("You load the ballista.\n");
  say(NAME+" loads the ballista.\n", this_player());
  loaded = 1;
  return 1;
}

status aim_balista(string str) {
  string ship_file;
  string *other_ships, tmp;
  int distance, dmg, i;
  status check;

  if(!str) {
    write("Aim ballista at what?\n");
    return 1;
  }
  if(!loaded) {
    write("You have to arm the ballista first.\n");
    return 1;
  }

  other_ships = get_dir(FILE);
  str = lower_case(str);
  for(i=0; i<sizeof(other_ships); i++) {
    if(str == other_ships[i]) check = 1;
  }

  if(!check) {
    write("There are no ships by that name.\n");
    return 1;
  }
  aimed = 1;
  target = str;
  write("You aim the ballista at "+capitalize(str)+".\n");
  return 1;
}

status fire_balista() {
  string str, ship_file;
  mixed *dmg_msg;
  string tmp;
  int dmg;

  str = target;
  ship_file = FILE+str+"/"+MASTER_OB;
  targ_coordinates = (int *)call_other(ship_file, "query_coordinates");
  my_coordinates   = (int *)call_other(environment(), "query_coordinates");
  distance = (int)DISTANCE->calc_distance(my_coordinates, targ_coordinates); 

  if(!aimed) {
    write("But you haven't aimed the ballista yest.\n");
    return 1;
  }

  if(distance > RANGE) {
    write("That ship is out of range.\n");
    return 1;
  }

  dmg_msg = ({
     ({ "graze", "splinter", "bruise", "strike", "hit", "crack", "smash",
        "crush", "destroy", "obliterate", "annihilate", 
     }),
     ({ "hull", "stern", "bow", "port railing", "starboard railing",
        "main mast", "main sail", "sails", "rigging",
     }),
  });

  write("You fire on the "+capitalize(str)+"!\n");
  say(NAME+" fires the ballista on the "+capitalize(str)+"!\n");

  if(oiled) {
    dmg += OIL_DAMAGE;
    oiled = 0;
  }

  dmg = random(damage)+1;
  ship_file -> hit_ship(dmg);

  dmg = (dmg/sizeof(dmg_msg[0]));
  tell_room(ship_file, "The "+capitalize(environment()->query_ship_name())+
          " fires on you!\n");
  if(!dmg) {
     tell_room(ship_file, 
               "They miss, and the "+query_name(0)+" lands in the ocean.\n");
     say("The "+query_name(0)+" misses, and lands in the ocean.\n");
     write("You miss, and the "+query_name(0)+" lands in the ocean.\n");
     tell_other_rooms(FILE+str+"/", "miss");
  }
  else {
    tmp = dmg_msg[1][random(sizeof(dmg_msg[1]))];
    tell_room(ship_file,
               "They "+dmg_msg[0][dmg]+" the "+tmp+
               " on your ship!\n");
    say(NAME+" "+dmg_msg[0][dmg]+" the "+tmp+" of the "+capitalize(str)+"\n",
        this_player());
    write("You "+dmg_msg[0][dmg]+" the "+tmp+" of the "+capitalize(str)+"\n");
    tell_other_rooms(FILE+str+"/", "hit");
  }
  loaded = 0;
  aimed = 0;
  return 1;
}

void tell_other_rooms(string filename, string result) {
  string *files;
  int i;

  files = get_dir(filename);
  for(i=0; i<sizeof(files); i++) {
    if(files[i] != MASTER_OB) {
      if(result == "miss") {
        tell_room(filename+files[i], 
               "A "+query_name(0)+" just missed the ship.\n");
      }
      else {
        tell_room(filename+files[i],
               "The ship rocks as it it hit by a "+query_name(0)+".\n");
      }
    }
  }
}

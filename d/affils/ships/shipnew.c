/* Sailing Ship v3.03, Angel January 1994.
 * v4.0, Angel (c) August 1997.
 *
 * This sailing ship code is used to travel between islands
 * found in the /d/affils/ships/open/ports.c file. Here is
 * a mapping of all the ports of call and other info.
 * 
 * When a ship is made it should go into the /d/affils/open/types
 * dir with the file stern.c ... set_ports(({ "port1", .. }));
 * will then allow the ship to sail to those ports
 *
 * Make sure that those ports exist
 *
 */


/**************************************************************/
/* Defines */
#define PORT_FILE             "/d/affils/ships/open/ports"
#define SHIP_DIR              "/d/affils/ships/open/types/"
#define MAPS		      "/d/affils/ships/maps"
#define DISTANCE              "/d/affils/ships/distance"
#define ABANDON_SHIP          "/d/affils/ships/rooms/beach5"

#define SHIP_OB_FILE          "stern"  /* where to find other ship fns   */


#define SHIP_NAME       capitalize(this_object()->query_short())
#define CAPTAIN         "Captain"

#define WAIT_TIME       120       /* a few minutes                  */
#define X               0        /* members of an array for coords */
#define Y               1
#define SPEED           5        /* default speed of ship          */
#define SIGHT_RANGE     100      /* range of the looking glass     */
#define CLOSE_ENUFF     2
#define HP              1000     /* hp for the ship                */





/**************************************************************/
/* Info */
mapping destinations;	/* all the destinations               */
mapping port_info;	/* port info for where we're going to */

string  *ports;		/* all the ports we're going to       */
string port;		/* the port we're NOW going to        */
string port_file;	/* the file of the port 	      */

int speed;		/* how fast the ship is going         */
int counter;		/* to count where we are!	      */
int distance;		/* distance to next port	      */
int wait_time;		/* TIME to wait between voyages	      */
int hull_points;	/* HP for the ship	              */
int timer;		/* time for the trip		      */

int *old_port_coords;	/* the port we're used to be at       */
int *port_coords;	/* where we want to go!               */

string ships_captain;	/* captain of the ship 		      */
string ships_name;	/* name of the ship		      */


status auto_pilot;	/* whether anyone is controlling me!  */
status waiting;		/* whether we're waiting to go!       */




/**************************************************************/
/* Fn Specs */
void msg(string str);
void ships_start();
void ship_leaves(string str);
mixed *check_ships(int *arg);


/**************************************************************/
/* Set up Fns */
#include <mudlib.h>
#include <linewrap.h>

inherit ROOM;
void reset(status arg) {
  string txt;

  if(!destinations)  destinations  = (mapping)PORT_FILE->allports();
  if(!ports)         ports         = m_indices(destinations);
  if(!wait_time)     wait_time     = WAIT_TIME;
  if(!ships_captain) ships_captain = CAPTAIN;
  if(!ships_name)    ships_name    = "sutherland";   /* data's nebula ship! */
  if(!hull_points)   hull_points   = HP;
  if(!distance)      distance      = 666; /* grin ..arbitary to start with */


  if(arg) return;

  set_short("the sutherland");
  set_long(
     "A tall mast with spinnaker flying from it towers above you on this \n"+
     "grand sailing ship. Three other sails are full with the sea winds  \n"+
     "pushing the ship ever closer to its port of call; your destination.\n");

  set_items(({
     "spinnaker",
          "A huge sail full of wind. Upon the spinnaker is a design \n"+
          "of a naked woman with the lower body of a great wave",
     "mast",
          "The spinnaker flies from the mast",
     "ship",
          "You're standing on it",
     "sail#sails",
          "The wind fills them, pushing the ship along in the water",
     "wind#winds",
          "You can't see the wind!",  /* someone is bound to do it! */
     "sea#water#wave#waves",
          "They crash against the ship, making it toss up and "+
          "down in the water",
          "down in the water",
     "wheel",
          "The ships wheel is painted a rusty brown, matching the wood \n"+
          "on the rest of the ship. Beside it is a compass, as well as "+
          "a brass telescope",
  }));

  set_weather(2, 4, 6);
  set_exits(({  "room/city/jetty", "gang plank",  }));

  set_night_desc(
     "A lantern hangs by the wheel, lighting the upper decks.\n");
  set_night_items(({
     "lantern", "A simple oil lantern made from brass",
  }));

  call_out("ships_start", 5); /* gives a little time */
}


void long(status wiz) {
  string tmp, temp;
  ::long(wiz);

  temp = capitalize(ships_name);
  if(port) 
    tmp = "There is a map beside the ships' wheel with the destination "+
	   "'"+ capitalize(port) +"' circled in ink. ";
  else
    tmp = SHIP_NAME+" is not going anywhere. ";

  if(hull_points > hull_points/2)
    tmp += "The "+temp+" is in excellent shape.\n";
  else if(hull_points > hull_points/3)
    tmp += "The "+temp+" is looking a little shabby.\n";
  else if(hull_points > hull_points/4)
    tmp += "The "+temp+" is showing some wear and tear.\n";
  else if(hull_points > hull_points/5)
    tmp += "The "+temp+" looks quite damaged.\n";
  else
    tmp += "The "+temp+" is falling appart!\n";
  if(hull_points < 0)
    tmp += "The "+temp+" is sinking!\n";
  writelw(tmp);
}


/*************************************************************************/
/* Special LOOK at functions */
status look_at(string str) {
  string tmp, tmp1, tmp2;
  int i, j, *ship_xy, *my_xy, *dest_xy;
  string ship_file;
  mixed *ships;

  if(str == "map") {
    tmp = (string)MAPS -> make_map();
    write(tmp);
    tmp = "The map shows that the ship has many destinations, including ";

    for(i=0; i<sizeof(ports); i++) {
      if((sizeof(ports)-1) == i)
        tmp += "and "+capitalize(ports[i])+". ";
      else
        tmp += capitalize(ports[i])+", ";
    }
    if(port) {
      tmp += "From the map "+capitalize(port)+
        " is about "+ ((waiting) ? distance : (distance - timer)) +
        " nautical miles away from here.\n";
    } 
    writelw(tmp);
    return 1;
  }


  if(str == "compass") {
    tmp     = "From the compass settings you think you're sailing in ";
    my_xy   = (int *)this_object()->query_coordinates();
    dest_xy = (int *)this_object()->query_port_coords();

    tmp1 = (string)DISTANCE -> calc_direction(my_xy, dest_xy);
    if(tmp1[0] == 'e') tmp += "an "+tmp1;
    else
      tmp += "a "+tmp1;
    tmp += "erly direction.\n";
    writelw(tmp);
    return 1;
  }


  if(str == "telescope") {
    ships = check_ships(0);  /* placement of other ships ...except outs */
    write("You look through the telescope...\n");
    say(this_player()->query_name()+" looks through the telescope.\n",
      this_player());

    if(!sizeof(ships))
      write("There are no ships within sight.\n");
    else {
      for(i=0; i<sizeof(ships); i++) {
        if(ships[i][1] < SIGHT_RANGE) {
          tmp  = "You can see the ";
          tmp += capitalize(ships[i][0]);
          if(ships[i][1] < CLOSE_ENUFF)
            tmp += ". It's only a few yards ";
          else {
            tmp += ". It's about "+ships[i][1]+" nautical miles ";
            tmp += ships[i][2]+" from here.\n";
          }
          j++;
          writelw(tmp);
        }
      }
    }
    if(!j) {
      write("There are no ships within sight.\n");
    }

    if((distance - timer) < SIGHT_RANGE) {
      write("You can see that "+capitalize(port)+" is only "+
      (distance - timer)+" nautical miles away.\n");
    }
    else {
      write("You can't see your destination yet.\n");
    }
    return 1;
  }

  return ::look_at(str);
}


/* the ship now arrives at its port */
void ship_arrives() {
  timer = 0;
  port_file = port_info["file"];

  msg("The ship finally reaches "+capitalize(port)+".\n"+
        capitalize(ships_captain)+" says: Right then, we're here mates!\n"+
        "The gang plank is pulled out toward the jetty\n");

  this_object() -> add_exit(port_file, "gang plank");

  port_file -> set_ship_info(ships_name,
      SHIP_NAME+" has dropped anchor here in the harbour.");

  port_file -> add_exit(file_name(this_object()), ships_name);
  port_file -> add_item("gang plank#plank", "It leads onto the "+ships_name);
  port_file -> add_item(ships_name,
          SHIP_NAME+", with its gang plank set down close by.\n"+
          "The ship looks as if it may set sail at any moment");

  tell_room(port_file, SHIP_NAME+" sails into the harbour...\n");

  if(!auto_pilot) { /* stop the ship now! */
    set_heart_beat(0); 
    return;
  }
  else
    waiting = 1;

  /* our new port is the next on the list */
  old_port_coords = port_info["xy"];
  counter ++;
  if(counter > (sizeof(ports)-1)) counter = 0;

  port = ports[counter]; /* go to the next port on the list */
  port_info = destinations[port]; 
}


/* The ship now leaves */
void ship_leaves(string str) {
  mixed *tmp;

  timer = 0;
  msg(capitalize(ships_captain)+" exclaims: Right then maties! Set sail for "+
    capitalize(str)+" harbour!\n");

  set_heart_beat(1);
  if(port_file) {  /* put the room back the way we found it */
    port_file -> remove_exit(ships_name);
    port_file -> remove_item("gang plank#plank");
    port_file -> remove_item(ships_name);
    port_file -> set_ship_info(ships_name, 0);
    tell_room(port_file, SHIP_NAME+" sails out of the harbour...\n");
  }

  this_object() -> remove_exit("gang plank");
  port_file   = port_info["file"];
  port_coords = port_info["xy"];  /* where we want to go */

  /* calc distance from here to there */
  distance = (int)DISTANCE->calc_distance(port_coords, old_port_coords);

  msg("The anchor is pulled up onto the deck.\n");
  msg("The gang plank is pulled in, and the ship sets sail.\n");
  set_heart_beat(1);
  timer   = 0;
  waiting = 0;
  return;
}


/*************************************************************************/
/* Major Ship Sailing Fn */
void heart_beat() {
  mapping tmp;
  mixed *arr;
  int i;

  if(ships_name == "sutherland") set_heart_beat(0);
  /* dont want this object sailing around! */
  if(!speed && hull_points > 0) speed = SPEED;
    timer += speed;

  /* wait for a while before setting off again */
  if(waiting) {
    if(timer > WAIT_TIME) {
      ship_leaves(port);
      timer = 0;
      waiting = 0;
      return;
    }
    return;
  }


  /* we've arrived at our destination */
  if(timer > distance) { 
    ship_arrives();
    timer = 0;
    return;
  }

  if(!random(10)) {
    if(arr = check_ships(0))
    for(i=0; i<sizeof(arr); i++) {
      if(arr[i][1] < CLOSE_ENUFF) {
        msg("You notice the "+capitalize(arr[i][0])+" passing close by to "+
        "the "+arr[i][2]+"...\n");
      }
    }
  }
}


void ships_start() {
  string tmp;

  /* 1st port is where we start off */
  port            = ports[0];
  port_info       = destinations[port];
  port_file       = port_info["file"];
  old_port_coords = port_info["xy"];
  port_coords     = old_port_coords;

  counter    = 1;
  waiting    = 1;
  auto_pilot = 1;
 
  port       = ports[counter];
  port_info  = destinations[port];
  set_heart_beat(1);
}


mixed *check_ships(int *arg) {
  int i, j, *dest_xy, *my_xy;
  string *ships, tmp, ship_file, k;
  mixed *result;

  if(!sizeof(arg)) arg = 0;
  ships = get_dir(SHIP_DIR);
  if(!sizeof(ships)) return 0;
  result = ({});

  for(i=0; i<sizeof(ships); i++) {
  	if(ships[i] == "CVS") continue;
    if(!sscanf(ships[i], "%s.c", tmp)) {
      ship_file = SHIP_DIR+ships[i]+"/"+SHIP_OB_FILE;

      if((string)ship_file->query_ship_name() !=
        ((string)this_object()->query_ship_name())) {

        dest_xy = (int *)call_other(ship_file, "query_coordinates");
        if(arg)
          my_xy = arg;
        else
          my_xy   = (int *)this_object()->query_coordinates();

        if(dest_xy && my_xy) {
          j = (int)DISTANCE->calc_distance(my_xy, dest_xy);
          tmp =  capitalize((string)ship_file->query_ship_name());
          k = (string)DISTANCE->calc_direction(my_xy, dest_xy);
          result += ({ ({ tmp, j, k, }), });
        }
      }
    }
  }
  return result;
}


mixed *query_coordinates() {
  int x1, x2, y1, y2, dx, dy;
  int gradient;
  int x, y;

  if(waiting) return old_port_coords;
  if(!timer) return old_port_coords;
  x1 = old_port_coords[X];  x2 = port_coords[X];
  y1 = old_port_coords[Y];  y2 = port_coords[Y];

  dx = x2 - x1;
  dy = y2 - y1;

  x = (dx * timer)/distance;
  y = (dy * timer)/distance;
  return ({ (x1 + x), (y1 + y), });
}

void msg(string message) {
  if(!message) return;
  tell_room(this_object(), message);
  return;
}

int hit_ship(int dmg) {
  hull_points -= dmg;
  if(hull_points < 0) {
    msg("The ship starts to sink!\n");
    msg(capitalize(ships_captain)+" exclaims: Abandon ship! We're sinking!\n");
    set_heart_beat(0);
    this_object()->add_exit(ABANDON_SHIP, "overboard");
  }
  else {
    if(hull_points/dmg)
      speed /= (hull_points/dmg);
    if(speed < 1) speed = 1;
    msg(SHIP_NAME+" slows in the water due to hull damage.\n");
    set_heart_beat(1);
  }
  return hull_points;
}


status set_auto_pilot(status a){ return auto_pilot = a;  }

int   *query_port_coords()     { return port_coords;     }
int   *query_old_port_coords() { return old_port_coords; }
int   query_ship_hp()          { return hull_points;     }

string query_ship_name()       { return ships_name;       }
string query_captain()         { return ships_captain;        }

string *query_ports()          { return ports;		 }

mapping query_destinations()   { return destinations;    }
mapping query_port_info()      { return port_info;       }


status query_no_fight()        { return 1;               }

/*************************************************************************/
/* Set Funs */
int set_ship_hp(int i)                { return hull_points = i;    }
int set_ship_speed(int i)             { return speed = i;          }
int set_wait_time(int i)              { return wait_time = i;      }

mapping set_destinations(mapping map) { return destinations = map; }

string *set_ports(string *arr)	      { return ports = arr;        }
string set_ship_name(string str)      { return ships_name = str;    }
string set_captain(string str)        { return ships_captain = str;      }

void clean_up() { return; } /* don't clean up and stop ships! */

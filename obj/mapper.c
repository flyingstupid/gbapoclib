/*************************************************************************/
/* Room mapper v2.0 (c) Angel, January 2002. ravenloft@hunterlink.net.au
 *
 * Based on v1.01 Hippo's Tracker 1994
 * 
 * Lots of comments to help you through this code, should you wish to 
 * improve upon it. If you've made any advancements, please let me know!
 *
 */

 

#include <mudlib.h>
inherit TREASURE;

#define STARTROOMSYMBOL "S"
#define ROOMSYMBOL      "x"
#define STORESYMBOL     "o"
#define MARGIN          1
#define PAGEHEIGHT      200
#define PAGEWIDTH       70
#define SPACER		2
#define X               0
#define Y               1

#define X_START		0
#define Y_START		0

#define OFFSET          5


#define NAME            (string)this_player()->query_name(1)

#define SAVEFILE        "/maps.log"


/*************************************************************/
/* global variables */

string *validExits;
string *symbols;
string *rooms;

int    *x_coords, *y_coords;
int    *x_amount, *y_amount;
int    *x_map,    *y_map;

int    x_globaloffset, y_globaloffset;

mixed *coordinates;
mixed *roadmap;
mixed *tmpInfo;

mapping roomInfo;




/*************************************************************/
/* initialise fns */

void add_room(string str, mixed *arr, status force);
void remove_room(string str);
void add_room_info(string filename, int *coordinates);
void allocate_coordinates(string filename);
void adjust_coordinates();

status valid_room_exit(string exit);
status query_room(string str);


mixed *query_room_coordinates(string str);
mixed *query_roadmap();


int query_room_coordinates_x(string str);
int query_room_coordinates_y(string str);

string *get_room_exits(string str);
string *filter_room_files(string *arr);
string *filter_room_exits(string *arr);
string *allocate_rooms();

string write_roadmap();

mixed initialise_roadmap();


/*************************************************************/
/* create the object */

void reset(status arg) {
  if(arg) return;

  set_name("map generator");
  set_alias("generator");
  set_short("A map generator");

  set_long("A room generator for Creators\n"+
           "Use: map\n");

  validExits = ({ "north", "northeast", "east", "southeast", "south", "southwest", "west", "northwest", });
  symbols    = ({ "\|",     "\/",         "-",     "\\",      "\|",     "\/",       "-",     "\\",      });
  x_amount   = ({  0,	    1,           1,         1,           0,      -1,         -1,     -1,        });
  y_amount   = ({  1,       1,           0,        -1,          -1,      -1,          0,      1,        });

  x_map      = ({ });
  y_map      = ({ });

  rooms      = ({ });
  roadmap    = ({ });
  roomInfo   = ([ ]);
  coordinates = ({ });

  initialise_roadmap();
}

get()  { return 0; }
drop() { return 1; }

void init() {
  add_action("allocate_rooms", "map");
}

/*************************************************************/
/* adds and queries */

// note that the array position for rooms and its coordinates
// should basically be the same, since position in an array is
// very important to the information stored in there, unlike a
// mapping

mixed *query_room_info() { return ({ rooms, coordinates, }); }

string *query_rooms() { return rooms; }

status query_room(string str){
  if(!rooms) rooms = ({ });
  return (member_array(str, rooms) == -1) ? 0 : 1;
}

void add_room(string str, mixed *arr, status force){
  if(str) {
    if(query_room(str) && force)
      remove_room(str);

    if(!query_room(str)) rooms += ({ str, });

    if(arr)
      coordinates += ({ arr, });
  }
}

void remove_room(string str){
  int i;
  if((i = member_array(str, rooms)) != -1) {

// if i have corresponding coordinates, remove them first
    if(query_room_coordinates(str))
      coordinates = coordinates[0..i-1] + coordinates[i+1..sizeof(coordinates)-1];

// now remove me
    rooms = rooms[0..i-1] + rooms[i+1..sizeof(rooms)-1];
  }
}

mixed *query_room_coordinates(string str) {
  int i;
  if((i = member_array(str, rooms)) != -1 && (i < sizeof(coordinates))) {
    return coordinates[i];
  }
}

int query_room_coordinates_x(string str) {
  mixed *arr;
  if(arr = query_room_coordinates(str)) {
    return arr[X];
  }
}

int query_room_coordinates_y(string str) {
  mixed *arr;
  if(arr = query_room_coordinates(str)) {
    return arr[Y];
  }
}

mixed *query_coordinates() { return coordinates; }

status query_valid_room_exit(string exit) {
  return (member_array(exit, validExits) == -1) ? 0 : 1 ;
}

string *get_room_exits(string filename) {
  return call_other(filename, "query_exits");
}



/*************************************************************/
/* other useful fns */

string strip_filename(string filename) {
  string s;
  int i;

  if(sscanf(filename,"%s.c", s) == 1) 
    filename = s;

  if(extract(filename,0,0) == "/") 
    filename = extract(filename,1);

  if(sscanf(filename, "%s#%d", s, i) == 2)
    filename = s;

  return filename;
}

mixed *initialise_roadmap() {
  mixed *tmp1;
  string *tmp2;
  int i, j;

  roadmap = ({ });

  for (i=0; i<PAGEHEIGHT; i++) {
    tmp1 = allocate(PAGEWIDTH);
    roadmap += ({ tmp1, });
  }
  return roadmap;
}



// returns all the filenames for the valid exits for this room
string *filter_room_files(string *arr) {
  int i;
  string *tmpRooms;

  tmpRooms = ({ });

  for(i=0; i<sizeof(arr); i += 2) {
    if(query_valid_room_exit(arr[i+1])) {
      tmpRooms += ({ strip_filename(arr[i]), });
    }
  }
  return tmpRooms;
}
    
// returns all the valid exits for this room
string *filter_room_exits(string *arr) {
  int i;
  string *tmpExits;

  tmpExits = ({ });

  for(i=0; i<sizeof(arr); i++) {
    if(query_valid_room_exit(arr[i]))
      tmpExits += ({ arr[i], });
  }
  return tmpExits;
}


string *process_room(string filename) {
  object ob;
  int i, j;
  int x, y, xnew, ynew;
  int adjustment;
  string *tmpDestDir, *tmpRooms, *tmpExits;


  if(!filename) filename = file_name(environment(this_object()));

  tmpDestDir = get_room_exits(filename);
  tmpRooms   = filter_room_files(tmpDestDir);
  tmpExits   = filter_room_exits(tmpDestDir);
  x          = query_room_coordinates_x(filename);
  y          = query_room_coordinates_y(filename);

  for(i=0; i<sizeof(tmpRooms); i++) {
    if(!query_room(tmpRooms[i])) {
      adjustment = member_array(tmpExits[i], validExits);
      xnew = x + (x_amount[adjustment] * SPACER);
      ynew = y + (y_amount[adjustment] * SPACER);
      add_room(tmpRooms[i], ({ xnew, ynew, }), 1);

      if(xnew < x_globaloffset) x_globaloffset = xnew;
      if(ynew < y_globaloffset) y_globaloffset = ynew;
    }
  }

  return rooms;
}


/*************************************************************/
/* start of the main function */

string *allocate_rooms() {
  int i;
  object ob;
  string filename;

  ob                 = environment(this_object());
  filename           = strip_filename(file_name(ob));
  rooms              = ({ filename, });
  coordinates        = ({ ({ X_START, Y_START, }), });
  x_globaloffset     = 0;
  y_globaloffset     = 0;

// set the first room to roughly the middle of the page to start with

//  add rooms to the list
//  separating the fn's works better for some reason
  for(i=0; i<sizeof(rooms); i++) {
    process_room(rooms[i]); 
  }

  write("Processed "+ sizeof(rooms) +" to map.\n");

// adjust the coordinates so they are not negative and outside
// the bounds of the array to draw the map
  adjust_coordinates();

// now write the roadmap
  write_roadmap();

  return rooms;
}


void adjust_coordinates() {
  int i;
  int x, y;

  for(i=0; i<sizeof(coordinates); i++) {
    x = coordinates[i][X];
    y = coordinates[i][Y];

    x = x - x_globaloffset + MARGIN;
    y = y - y_globaloffset + MARGIN;

    coordinates[i][X] = x;
    coordinates[i][Y] = y;
  }
}

// arr1 contains filenames, arr2 contains coordinates
string write_roadmap() {
  int i, j;
  int x, y, xSymbol, ySymbol, xOld, yOld;
  int adjustment;
  int mapsize;
  string filename, str;
  string *exits;
  string tmp, mapSymbol, wholemap;
  status hascontent;
  mixed *arr;
  mixed *roomCoordinates;
  string *filenames;

  wholemap = "";



  // this was initialised in the reset()
  mapsize = sizeof(roadmap);

  for(i=0; i<sizeof(rooms); i++) {
    x = coordinates[i][X];
    y = coordinates[i][Y];

    xOld = x; yOld = y;

    exits = get_room_exits(rooms[i]);
    exits = filter_room_exits(exits);

// rather than setting array from 0 we set it from the last element
// to the first, otherwise, the map ends up with y coords incorrect
    y     = (mapsize - y);

   
    if(function_exists("add_store", find_object(rooms[i])))
      roadmap[y][x] = STORESYMBOL; 
    else
      roadmap[y][x]= ROOMSYMBOL;

    if(!i)
      roadmap[y][x] = STARTROOMSYMBOL;


// write symbols for exits from the current room    

    for(j=0; j<sizeof(exits); j++) {
      adjustment = member_array(exits[j], validExits);
      mapSymbol = symbols[adjustment];

      xSymbol   = x + x_amount[adjustment];
      ySymbol   = y - y_amount[adjustment];

      roadmap[ySymbol][xSymbol] = mapSymbol;
    }
  }


//start the mapping of the coordinates and exits from the roadmap array
  tmp = "";

  for(i=0; i<PAGEHEIGHT; i++) {
    for(j=0; j<PAGEWIDTH; j++) {
      if(!roadmap[i][j]) {
        tmp += " ";
      }
      else {
        tmp += roadmap[i][j];
        hascontent = 1;
      }
    }
    if(hascontent) {
      tmp += "\n";
      hascontent = 0;
    } 
    else {
      tmp = "";
    }
    wholemap = wholemap + tmp;
    tmp = "";
  }

  wholemap += "\n"+
  "Key: S - You are here\n"+
  "     o - Shop/Store  \n"+
  "     x - Other rooms \n";

  write(wholemap);

//write_file(WIZARD_DIR+NAME+SAVEFILE, "\n\n"+ wholemap +"\n\n");
  write("\n"+sizeof(rooms)+" rooms successfully mapped at "+ WIZARD_DIR+NAME+SAVEFILE +"\n");

  return wholemap;
}




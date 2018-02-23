#include <mudlib.h>
#include <ansi.h>

#include "/d/affils/ships/open/ports.c"

void add_array_to_map (mixed * arr);
void add_ports_to_map();
void initialise_map();

#define WIDTH       60
#define SHIP_DIR    "/d/affils/ships/open/types/"
#define MASTER_FILE "/stern"
#define PAGE        18
#define XYZ_COORDS  2

string map;

void initialise_map() {
  int i, j;

  map = "";

  for(j=0; j<PAGE; j++) {
    map += "\n";
    for(i=0; i<WIDTH; i++) {
      map += " ";
    }
  }
  map += "\n";
}

void add_ports_to_map() {
  add_array_to_map(ports_to_array());
}
  

void add_array_to_map(mixed * map_arr) {
  int *arr;
  int i, j, tmpi;
  int y_max, x_max, y_min, x_min;
  int x, y;
  string map_symbol;
  string symbol_name;
  string *amap;

  for(i=0; i<sizeof(map_arr); i++) {
    arr = map_arr[i][XYZ_COORDS];
    if(!i) {
      x_max = arr[0];        x_min = arr[0];
      y_max = arr[1];        y_min = arr[1];
    }
    else {
      if(arr[0] > x_max)      x_max = arr[0];
      else if(arr[0] < x_min) x_min = arr[0];
      if(arr[1] > y_max)      y_max = arr[1];
      else if(arr[1] < y_min) y_min = arr[1];
    }
  }
    
  amap = explode (map +"\n","\n");

  for(i=0; i<sizeof(map_arr); i++) {
    arr = map_arr[i][XYZ_COORDS];
    y = arr[1] - y_min;
    y = (y * PAGE)/(y_max - y_min);
    x = arr[0] - x_min;
    x = (x * WIDTH)/(x_max - x_min);
    j = (y * WIDTH) + x;
    map_symbol  = ((map_arr[i][0][0] == '^') ? "X" : ".");
    symbol_name = ((map_arr[i][0][0] == '^') ?
                  extract(map_arr[i][0], 1)  :
                  map_arr[i][0]);
    y = PAGE-y;
    tmpi = (y > PAGE/2) ? -1 : 1;
    if(x-1 >= WIDTH-1) x = WIDTH - 2;
    while (amap[y][x + 1] != ' ') {
      y += tmpi;
      if(map_symbol != ".") map_symbol = " ";
    }

    amap[y] = amap[y][0..x]+BOLD+map_symbol+OFF+symbol_name+
             amap[y][strlen(symbol_name)+(x+1)..strlen(amap[y])-1];
  }
  map = implode (amap,"\n") + "\n";    
}

string query_map() { return map; }
  
string make_map() {

  int i;
  string *files;
  int *ship_xyz;
  string ship_file, ship_name;
  mixed *total_arr;

  files = get_dir(SHIP_DIR);
  total_arr = ({});
  for(i=0; i<sizeof(files); i++) {
    ship_file = SHIP_DIR+files[i]+MASTER_FILE;
    ship_name = (string)ship_file->query_ship_name();
    ship_xyz  = (int *)ship_file->query_coordinates();
    if(!ship_name || !ship_xyz) continue;
    ship_name = "^"+ ship_name;
    total_arr += ({({ ship_name, ship_file, ship_xyz, })});
  }

  initialise_map();
  add_array_to_map(ports_to_array() + total_arr);
  return query_map();
}


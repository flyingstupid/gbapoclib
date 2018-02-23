#include <mudlib.h>
#include <linewrap.h>

#define CLOSE_ENUFF 	2
#define SHIPA		"/d/affils/ships/shipnew"
#define SIGHT_RANGE	100

inherit TREASURE;

static int *xy_coordinates;


void reset(status arg) {
  if(arg) return;
  set_name("telescope");
  set_short("A fine brass telescope");
  set_long(
"A fine brass telescope, stamped with the seal of the Bright Moon family\n"+
"of Ille Coronos, who make fine brass and glass equipment for the local \n"+
"university.\n");
  set_weight(1000);
  set_value(1000);
}

void init() {
  ::init();
  if(!xy_coordinates || !sizeof(xy_coordinates)) xy_coordinates = ({ 0, 0, });
}

void long(status wiz) {
  string tmp;
  int i;
  int j;
  mixed *ships;
  ::long(wiz);

  ships = (mixed *)SHIPA->check_ships(xy_coordinates);

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
          tmp += ". It's only a few yards away.\n";
        else {
          tmp += ". It's about "+ships[i][1]+" nautical miles ";
          tmp += ships[i][2]+" from here.\n";
        }
        j++;
        writelw(tmp);
      }
    } 
  }
  return;
}

int *set_xy(int x, int y) {
  return xy_coordinates = ({ x, y, });
}

int *query_xy() { return xy_coordinates; }


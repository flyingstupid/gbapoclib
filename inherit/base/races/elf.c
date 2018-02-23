/* Modular race - Elf */

#include <mudlib.h>
inherit PLAYER;

int *query_start_stats() {
  return ({  1,  2,  1,  1,  3,  1,  2  }); /* for all elves */
}

int *query_max_stats() {
  int *max_stats;
  string str, race_type;
  
  str = (string)query_race(0); 
  sscanf(str, "%s %s", race_type, str);
  if(race_type == "half") 
    max_stats = ({  20, 25, 22, 23, 26, 25, 24  }); 
  else if(race_type == "gray" || race_type == "grey")
    max_stats = ({  19, 27, 20, 21, 26, 22, 26  });
  else if(race_type == "wood" || race_type == "wild")
    max_stats = ({  20, 20, 26, 23, 26, 19, 26  });
  else
    max_stats = ({  20, 26, 20, 22, 26, 21, 26  });
  return max_stats;
}

int query_race_save_bonus()     { return 2; }
int query_race_carry_bonus()    { return 0; } /* no bonus */
int query_race_right_wc_bonus() { return 1; }
int query_race_left_wc_bonus()  { return 1; }
int query_race_ac_bonus()       { return 1; }
int query_search_bonus()        { return 5; }

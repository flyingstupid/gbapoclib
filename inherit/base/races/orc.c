/* Modular race - Orc */

#include <mudlib.h>
inherit PLAYER;

int *query_start_stats() {
  return ({  2,  1,  2,  2,  2,  1,  1, });
}

int *query_max_stats() {
  return ({ 25, 18, 29, 24, 23, 25, 18, }); 
}


int query_race_save_bonus()     { return -1; }
int query_race_carry_bonus()    { return 2;  }

int query_race_right_wc_bonus() { return 2;  }
int query_race_left_wc_bonus()  { return 0;  }
int query_race_ac_bonus()       { return -1; }


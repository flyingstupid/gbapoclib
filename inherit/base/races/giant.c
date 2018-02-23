/* Modular race - Giant */

#include <mudlib.h>
inherit PLAYER;

int *query_start_stats() {
  return ({  3,  1,  3,  1,  1,  1,  1, });
}

int *query_max_stats() {
  return ({ 32, 15, 32, 23, 20, 20, 18, });
}


int query_race_save_bonus()     { return -1; }
int query_race_carry_bonus()    { return 5;  }

int query_race_right_wc_bonus() { return 1;  }
int query_race_left_wc_bonus()  { return 0;  }
int query_race_ac_bonus()       { return -1; }


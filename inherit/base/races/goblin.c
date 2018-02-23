/* Modular race - Goblin */

#include <mudlib.h>
inherit PLAYER;


int *query_start_stats() {
  return  ({  1,  3,  1,  1,  2,  2,  1, });
}

int *query_max_stats() {
  return ({  20, 25, 20, 20, 26, 27, 23   });
}


int query_race_save_bonus()     { return 1;  }
int query_race_carry_bonus()    { return 1;  }

int query_race_right_wc_bonus() { return 2;  }
int query_race_left_wc_bonus()  { return 2;  }
int query_race_ac_bonus()       { return 1;  }


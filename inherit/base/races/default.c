/* Modular race - Human/Default race settings */

#include <mudlib.h>
inherit PLAYER;


int *query_start_stats() {
  return  ({  3,  3,  3,  3,  3,  3,  3, });
}

int *query_max_stats() {
  return ({  25, 25, 25, 25, 25, 25, 25   });
}


int query_race_save_bonus()     { return 0; }
int query_race_carry_bonus()    { return 0; }

int query_race_right_wc_bonus() { return 0; }
int query_race_left_wc_bonus()  { return 0; }
int query_race_ac_bonus()       { return 0; }


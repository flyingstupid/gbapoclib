/* Modular race - Halfling */

#include <mudlib.h>
inherit PLAYER;

int *query_start_stats() {
  return ({  1,  2,  1,  1,  2,  2,  2, }); /* for both races */
}

int *query_max_stats() {
  return ({ 18, 25, 20, 20, 26, 25, 22, }); /* for both races */
}

int query_race_save_bonus()     { return 3; }
int query_race_carry_bonus()    { 
  return (query_race(0) == "halfling") ? -2 : -3; 
}

int query_race_right_wc_bonus() { return (query_race(0) == "halfling") ? 1 : 0; }
int query_race_left_wc_bonus()  { 
  return (query_race(0) == "halfling") ? 1 : 2; 
}

int query_race_ac_bonus() {
  return (query_race(0) == "halfling") ? 1 : 2;
}


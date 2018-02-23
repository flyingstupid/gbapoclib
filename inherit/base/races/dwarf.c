/* Modular race - Dwarf */

#include <mudlib.h>
inherit PLAYER;

int *query_start_stats() {
  return ({  3,  1,  2,  1,  1,  2,  1, }); /* for all dwarves */
}

int *query_max_stats() {
  return ({ 27, 20, 26, 23, 23, 25, 19, });
}

int query_race_save_bonus()     { return 3; }
int query_race_carry_bonus()    { return 0; } /* no bonus */
int query_race_right_wc_bonus() { return 2; }
int query_race_left_wc_bonus()  { return 0; }
int query_race_ac_bonus()       { return 0; }

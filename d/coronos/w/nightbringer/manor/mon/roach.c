/* COCKROACH */
/* Author:DarkBringer */
/* 04-25-97 */


#include <mudlib.h>
inherit MONSTER;

  reset(status arg) {

  ::reset(arg);
  if(arg) return;

  set_short("A Cockroach");
  set_name("cockroach");
  set_alias("roach");
  set_race("roach");
  set_long(
"It is an ugly, brown bug with six legs and two waving antenais. It is\n"+
"quite disgusting looking. The Penors' certainly need to call an\n"+
"exterminator.\n");

  set_gender(random(2) + 1);
  set_level(1);
  set_ac(3);
  set_wc(5);

  load_chat(5, ({"Cockroach scitters across the carpet.\n",
    "Cockroach waves its leg at you.\n",
    }));

  load_a_chat(5,({"Cockroach runs around in circles.\n",
    }));

  set_attack_msg(({
               "nudges softly",    "with its leg",
               "bruises softly",   "with its leg",
               "grazes lightly",   "with its antena",
               "whips lamely",     "with its antena",
               "butts softly",     "with its head",
               "butts severly",    "with its head",
               "crushes",          "with its jaws",
          }));


  }

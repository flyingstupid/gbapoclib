/* back stab */

static status done_backstab;

#include <mudlib.h>
#include <living.cfg>


#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"


status backstab(string str) {
  object obj, primary, weapon;
  string type;
  int your_dex;
  int dam;
  int my_backstab;

  if(!str) {
    notify_fail("backstab who?\n");
    return 0;
  }

  obj = present(lower_case(str), environment(this_player()));


  if((primary = (object)this_player()->query_primary_attack())) {
    if(present(primary, environment(this_player()))) {
      write("But surely "+lower_case((string)primary->short()) +" is ready for you this time!\n");
      return 1;
    }
  }

  if(!this_player()->query_stealth_on()) {
    write("You must sneak up on your victim before you can backstab them!\n");
    return 1;
  }

  if(weapon = this_player()->query_right_weapon()) {
    if((string)weapon->query_type() == "missile") {
      write("You can't backstab someone with a missile weapon!\n");
      return 1;
    }
  }



  my_backstab = (int)this_player()->query_backstab();
  my_backstab += (int)this_player()->query_wc();
  dam = 4 * (random(my_backstab/4) + 1);




  if(random(100) < 5) dam = 10000000000; /* instant assassination! */
  else {
    dam *= random(dam) + 1;
  }

  this_player()->load_spell(({
    "class",             "thief",
    "target",            str,
    "name",              "backstab",
    "sphere",            "backstab",
    "cost",              2,
    "damage",            dam,
    "immune",            "backstab",
    "level",             1,
"cast time",             3,
    "casting msg",
	({ "You look at "+obj->query_name()+" carefully, and wait for the "+
	   "right moment.\n",
           "You ready your weapon.\n",
           "You make sure no one is watching you . . . \n",
  }),

    "msg target",        NAME +" has backstabed you!\n",
    "msg caster",      TARG +" stumbles from your attack.\n",
  }));

  return 1;
}



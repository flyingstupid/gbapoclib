#include <mudlib.h>
#define OWNER_NAME "mycroft"

inherit MONSTER;

void reset(status arg) {
   ::reset(arg);
   if(arg) return;

set_name("mongoose");
set_race( "mammal");
   set_gender(1);
set_short("mongoose");
   set_long(
"Great at hunting snakes,\n"+
"the mongoose also makes a great pet!\n"+
"  \n");
set_level(50);
   set_al(1000);
set_wc(45);
set_ac(24);
set_hp(3000);
set_max_hp(3000);
   set_attack_msg(({
      "grazes","slightly",
      "scratches","with a light touch",
      "claws","with a quick swipe",
      "chomps","with a forceful bite",
      "rakes","with both claws"
   }));
  
   set_heart_ob(this_object());
}

void init() {
   ::init();
   add_action("pet_fun","pet");
}

status pet_fun(string str) {
   if (!str) {
      write("What did you want to pet?\n");
      return 1;
   }
if (str!="mongoose" && str!="pet mongoose" && str!="pet")  {
      write("You want to pet the "+str+"?  I don't think so!\n");
      return 1;
   }
   write(
 "You pet the little mongoose\n"+
"       \n"
   );
say(this_player()->query_name()+" pets the little mongoose.\n",
      this_player()
   );
   return 1;
}

void monster_heart_beat() {
   object owner;

   /* This will find the owner if he/she is actually on.  If the owner
      is not logged on, then the find_player will return 0 and
      monster_heart_beat will terminate
   */

   if (owner=find_player(OWNER_NAME)) {

      /* We only want to move the moster and tell the rooms if
         the environments (rooms) are different.  If we were to
         move the pet all the time, that would be a little too
         taxing on the mublib.
      */

      if (environment(owner) != environment(this_object())) {

         /* This will notify the people in the old room that
            the monster is leaving.
         */         
   
         tell_room(environment(this_object()),
"The mongoose leaves to track down Mycroft.\n"
         );

         move_object(this_object(), environment(owner));

         /* After we move the moster, we want to tell the
            people in the new room (room of the owner) of
            it's arrival.
         */

         tell_room(environment(this_object()),
"The mongoose comes into the room with a cobra in his mouth.\n"
         );
      }
   }
}

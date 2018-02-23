#include <mudlib.h>
#include "/d/ooc/w/jheleg/path.h"
inherit ROOM;

void reset(status arg)
{
   reset_doors(0);
   ::reset(arg);
   if (!arg)
   {
      load_door(({
         "destination", "d/ooc/w/jheleg/bhouse/mwash",
         "direction",   "washing machine",
         "closed",
         "description",
            "It is a small, round, and made of aluminum.\n",
      }));

      load_door(({
         "destination", "d/ooc/w/jheleg/bhouse/mdry",
         "direction",   "clothes dryer",
         "closed",
         "description",
            "It is a small, round, and made of aluminum.\n",
      }));

      set_short("Laundry Room");
      set_long(
         "  You find yourself in a tiled, cold, and expressionless room\n"+
         "  containing a washing machine, a clothes dryer, and a set of\n"+
         "  shelves.  One exposed light bulb hangs from the ceiling    \n"+
         "  providing your only source of light.                       \n"
      );
      set_items(({
            "washing machine",
         "A large Whirlpool brand washing machine stands ready to handle\n"+
         "your toughest job.  There is a button on the washing machine -\n"+
         "your curiosity tells you to push it.                          \n",

            "clothes dryer",
         "A large Whirlpoos brand clothes dryer stands empty longing for\n"+
         "its next batch of clean wet clothes to dry.  There exists a   \n"+
         "button on the machine.  Should you push it?                   \n",

            "machines#machine",
         "There are two different machines here; a washine machine and  \n"+
         "a clothes dryer.                                              \n",

            "shelves#shelf",
         "The shelves contain such necessary items as detergent, bleach,\n"+
         "and the ever-popular Snuggle softner.                         \n",

            "light bulb",
         "The frosted white light bulb hangs vulnerably from the ceiling.\n",
      }));
      set_smell(
         "The pungent aroma of detergent and bleach hangs in the air\n"
      );
      set_listen(
         "You can hear the occasional dripping of water coming from behind\n"+
         "the machines.\n"
      );
      set_ooc_room(1);
      set_weather(2, 2, 0);
      set_exits(({
         BHOUSE "hall2", "south",
      }));
   }
}

void init()
{
   ::init();
   add_action("push_fun", "push");
}

status push_fun(string str)
{
   if(!str) return 0;
   
   if(str!="button" && 
      str!="washing machine button" &&
      str!="clothes dryer button") return 0;

   if(str=="button")
   { 
      write(
         "Which button would you like to push?  The washing machine button,\n"+
         "or the clothes dryer button?                                     \n"
      );
      return 1;
   }
   if(str=="washing machine button")
   {
      write("You push the washing machine button...\n\n");
      say(this_player()->query_name()+
         " pushes the washing machine button...\n", this_player());
      tell_room(this_object(), 
         "The washing machine jumps to life, does its thing, and then falls\n"+
         "silent once again.\n"
      );
      tell_room("/d/ooc/w/jheleg/bhouse/mwash",
         "Someone has activated the machine from the outside!  You begin to\n"+
         "get turns and churned, but the machine suddenly stops as quickly \n"+
         "as it started.\n"
      );
   }
   else
   {
      write("You push the clothes dryer button...\n\n");
      say(this_player()->query_name()+
         " pushes the clothes dryer button...\n", this_player());
      tell_room(this_object(), 
         "The clothes dryer jumps to life, does its thing, and then falls\n"+
         "silent once again.\n"
      );
      tell_room("/d/ooc/w/jheleg/bhouse/mdry",
         "Someone has activated the machine from the outside!  You begin to\n"+
         "get turns and churned, but the machine suddenly stops as quickly \n"+
         "as it started.\n"
      );
   }
   return 1;
}



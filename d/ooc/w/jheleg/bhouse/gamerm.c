#include <mudlib.h>
#include "/d/ooc/w/jheleg/path.h"
inherit "d/ooc/w/jheleg/inherit/game_room";

void reset(status arg)
{
   reset_doors(0);
   ::reset(arg);
   if (!arg)
   {
      load_door(({
         "destination", "d/ooc/w/jheleg/bhouse/hall2",
         "direction",   "west door",
         "closed",
         "description",
            "The door is made of solid oak.\n",
      }));
     
      set_short("Gaming Room");
      set_long(
         "  Here resides the infamous gaming room of Heaven7.  Soft    \n"+
         "  lights illuminate the room in a very pleasant way.  Soft,  \n"+
         "  velvet couches surround a huge oaken table where the games \n"+
         "  are actually played.  A giant hi-fi stereo system sits     \n"+
         "  against one wall.  Above the stereo is a sign that has been\n"+
         "  hand carved into a piece of stained walnut.                \n"
      );
      set_items(({
            "light#lights#round light#round lights#embedded light#"+
            "embedded lights",
         "Round, embedded lights give of a heatless glow all throughout\n"+
         "the room.\n",

            "table#oaken table#horseshoe-shaped table",
         "A horseshoe-shaped table sits in he middle of the room      \n"+
         "providing plenty of room for all.                            \n",

            "stereo#giant stereo#hi-fi stereo#stereo system#"+
            "hi-fi stereo system",
         "A hi-fi Onkyo component system is tuned to the local classical\n"+
         "radio station.\n",

            "carpet#tan carpet#short carpet#short tan carpet#tan short "+
            "carpet",
         "Unlike the rest of the carpet located in the house, the carpet\n"+
         "here is short and tan.  It appears as though it is vacuumed   \n"+
         "faithfully every day.                                         \n",
      }));
      set_smell(
         "The scent of fresh wood and new carpet permeates the room.\n"
      );
      set_listen("Soft classical music floats around the room.\n");
      set_ooc_room(1);
      set_weather(2, 2, 0);
   }
}

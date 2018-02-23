#include <mudlib.h>
inherit ROOM;
void reset(status arg)
   {
      if (arg) return;
      set_short(
         "A Decorative Foyer");
      set_long(
         "This is a very decorative room, with many pictures on the walls.\n"+
         "The floor is hard wood, and there is a very small fireplace\n"+
         "along one of the walls.  There are no windows in this room as\n"+
         "the family probably spent all their money decoration the rest of this room.\n"+
         "There isn't anyone in this room, which makes you wonder where the\n"+
         "family is.\n");
      set_weather(1, 2, 0);
      set_items
      (({
         "pictures", "These pictures are of small children playing.",
         "wall#walls", "These walls have pictures all over them.",
         "floor", "This floor is all hard wood.",
      }));
      set_exits
      (({
          "/d/coronos/w/vorax/h2r2.c", "west",
         "/d/coronos/w/vorax/res5.c", "east",
      }));
   }

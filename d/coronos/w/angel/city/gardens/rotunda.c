#include <mudlib.h>
inherit ROOM;
void reset(status arg) {
  object obj;

  if(!present("bench")) {
    obj = clone_object("inherit/chair");
    obj -> set_weight(100000); 
    obj -> set_short("A white bench");
    obj -> set_long(
     "The bench looks just right for someone to sit \n"+
     "on after a long walk through the city gardens.\n");
    obj -> set_name("bench");
  }


  if(arg) return;
  set_short("the rotunda");
  set_long(
     "Around you is the reminder of ancient craftmanship. This old  \n"+
     "rotunda is crafted from some ancient wood, probably from the  \n"+
     "elvish forests, and carved by hand by the elf who designed it.\n"+
     "Ornate carvings of leaves and trees and small animals are etched \n"+
     "into the supports, reaching high toward the shadowy ceiling above.\n");

  set_smell(
     "The smell of fresh paint and old wood abounds in this tall rotunda.\n");
  set_listen(
     "You can hear the chattering of small animals from the ceiling.\n");
  set_items(({
     "supports", "They hold up the ceiling",

     "paint", "The pain appears to be wet",

     "wood",
     "An old ancient wood, now coated with fresh white paint",

     "carvings",
     "The carvings cover the supports of the rotunda. Possums, owls, \n"+
     "and other small furry animals can be seen etched into the wood",

     "possums", "They seem to be collecting nuts",

     "gum nuts#nuts", "The nuts the possums are collecting seem to be gum nuts",

     "animals", "There are many animals carved into the wooden supports",

     "owls#owl", "A few wise old owls are carved into the wooden supports "+
     "by expert hands",

     "ceiling#shadows#",
     "You think you spot some movement, but you cannot be sure. Perhaps  \n"+
     "if you climbed up there you would see more clearly what the shadows\n"+
     "hide? The climb up looks a fair way; it might be a little dangerous\n"+
     "if you should fall in the attempt",
  }));
  set_climb(5);
  set_weather(1, 2, 0);
  set_fall_dam(5);
  set_exits(({
	"d/coronos/w/angel/city/gardens/garden9", "west",
     "d/coronos/w/angel/city/gardens/ceiling", "up",
  }));

}
  

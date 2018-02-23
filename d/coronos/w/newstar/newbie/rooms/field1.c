/* field1.c -- newbie */
/* Darkness and Newstar */

#include <mudlib.h>
inherit ROOM;
 
void reset (status arg){

  if(!present("goat")){
    move_object(clone_object(
    "/d/coronos/w/newstar/newbie/npc/goat"),this_object());
  }
 
  if(!present("pig")) {
    int i;
    for(i=0; i<3; i++) {
      move_object(clone_object(
      "/d/coronos/w/newstar/newbie/npc/pig"),this_object());}
  }

  if(arg) return;
 
  set_short("a large open field");
  set_long(
    "This large open field has been grazed many times by the animals of\n"+
    "this farm.  The green grass is growing back quickly and in good\n"+
    "health.  ");
  set_day_desc(
    "The sun shines warmly upon the peacefull field.  From here,\n"+
    "a forest can be seen far to the north, and even beyond that is a \n"+
    "dark mountain range.  A large barn stands to the west of here.\n"+
    "Its doors are cracked open, inviting you to enter.\n");
  set_night_desc(
    "The moon glows brightly in the heavens, illuminating the\n"+
    "the quiet field.  The faint silhouette of the dark mountain range\n"+
    "and a dense forest can be seen far to the north.  A large barn\n"+
    "stands to the west.  Its doors are cracked open, inviting you to \n"+
    "enter.\n");
 
  set_day_items(({
    "sun",
      "The sun is very bright.  It hurts to look at it for too long.\n",
    }));
  set_night_items(({
    "moon",
      "The moon glows brightly, illuminating the fields and the plains.\n",
    "heavens",
      "The heavens are full of bright stars, and the moon glows bright.\n",
    }));
  set_items(({
    "barn#west",
      "The large barn is quite old.  The red paint is peeling off the\n"+
      "wooden boards that make up the walls.  Cracks in the roof must\n"+
      "let in lots of water when it rains.  The door is cracked open,\n"+
      "allowing you to freely enter the barn.\n",
    "cracks",
      "The cracks in the roof are too high to inspect more carefully.\n",
    "mountain#mountains#mountain range#silhouette",
      "The mountains far to the north are tall and wide.  Dark and scary,\n"+
      "the mountains are probably home to many strange creatures.\n",
    "forest",
      "The forest is far to the north.  It looks to be dense and dark.\n",
    "field#room",
      "This large open field is very peacefull.  The grass is short\n"+
      "and healthy here.\n",
    "animals",
      "There are many different kinds of animals on the farm, like cows,\n"+
      "horses, pigs and chickens.\n",
    "grass",
      "The grass is short and healthy.  It is used as grazing feed\n"+
      "for the farm's many animals.\n",
    }));
 
  set_smell(
    "Country fresh air fills your lungs.  It's sweet smell\n"+
    "is invigorating and refreshing.\n");
  set_listen(
    "You hear the wind beating against the outter walls of the barn.\n"+
    "The howling of the wind whistles as it enters through cracks in\n"+
    "the walls.\n");
  set_weather(2, 4, 0); /* Bright moonlight at night. Newbie.*/
  set_exits(({
      "/d/coronos/w/newstar/newbie/rooms/forest6", "north",
      "/d/coronos/w/newstar/newbie/rooms/yard", "south",
      "/d/coronos/w/newstar/newbie/rooms/field2", "east",
      }));
}
 


void init() {
  ::init();
  add_action("enter1", "enter");
}



status enter1(string str) {
  string tmp1, tmp2;
  if(!str) {
    write("What are you trying to enter?\n");
    return 1;
  }
 
  if((sscanf(str, "%sbarn%s", tmp1, tmp2)) ||
     (sscanf(str, "%sdoor%s", tmp1, tmp2))) {
    write("\n\nYou enter thebarn.\n");
    this_player()->move_player(
        "into the barn#d/coronos/w/newstar/newbie/rooms/barn1");
    return 1;
  }
  return 0;
}

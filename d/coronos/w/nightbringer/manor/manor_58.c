/* MANOR_58.c
   AUTHOR:NIGHTBRINGER
   04-28-97 */

#include <mudlib.h>
#include <ansi.h>
inherit ROOM;

void reset(status arg) {
  if(arg) return;

  set_short("Under The Penor's Manor");
  set_long(
"The strange wailing sounds decrease in volume a little as you\n"+
"head north. Strange flickering shadows dance along the walls like\n"+
"a twisted puppet show. Someone here has spray painted some graffiti\n"
"on the wall.\n");


  set_items(({
"wall#walls#floor",
"It is made of made of earth\n",

"ceiling",
"The ceiling is made of stone and looks very sturdy.\n",

"shadow#shadows#flickering shadow#flickering shadows",
"You are unable to determine what they are...just that they are not\n"+
"natural.\n",

"graffiti",
"Someone has spray painted something on the wall hear...perhaps you\n"+
"should read it.\n",

           }));


  set_smell("It smells damp and musty in here.\n");
  set_listen("Erie sounds seem to assail your ears from all directions.\n");

  set_weather(0,2,0);
  set_exits(({
        "d/coronos/w/nightbringer/manor/manor_57.c", "south",
           }));
}

void init() {
  ::init();
  add_action("read", "read");
}

status read(string str) {
  if(str == "graffiti") {
    write(RED_F+"         -+= NightBringer Rulez!  =+- \n"+OFF);
    write("Dirty vandals!\n");
    return 1;
  }
  return 0;
}

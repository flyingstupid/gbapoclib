#include <ansi.h>
#include <mudlib.h>
inherit PUB;

  void reset(status arg) {
  if(!present("skye")) arg = 0;
  if(arg) return;
  set_exits(({
"/d/coronos/w/russkie/rooms/18", "east",
}));
    set_short("Skyes tavern and inn");
  set_long("Everything seen in this small tavern is made of old, dull wood. The many\n\
shades of brown in the room give it a very rustic feel. The air is thick\n\
with smoke, and the smell of cheap whiskey. A sign hangs above the bar,\n\
and on the bar itself is a printer menu.\n");
  set_weather(4,1,0);
  set_owner("skye");
  add_drink("ale", "bottle of ale", "It goes down smooth.", 3);
  add_drink("whiskey", "shot of whiskey", "A shot of lightning runs through your body!", 10);
  add_drink("vodka", "glass of vodka", "Very potent stuff, it burns a little.", 23);
  add_food("stew", "thick beef stew", "It tasted very warm and hearty.", 4);
  add_food("sandwich", "a turkey sandwich", "A very filling meal.", 11);
  add_food("drumstick", "a chicken drumstick", "A bit tough, but it hits the spot.", 20);

  set_items(({
"wood",
"Everywhere you look there are different kinds of wood.\n",
"smoke",
"Hack, cough, you could cut through this stuff with a knife.\n",
"sign",
"\
-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\
-=    Skyes Tavern and   =-\n\
-=          Inn          =-\n\
-=                       =-\n\
-=    Inquiries about    =-\n\
-=     rooms can be      =-\n\
-=     made upstairs     =-\n\
-=                       =-\n\
-=-=-=-=-=-=-=-=-=-=-=-=-=-\n",
"bar",
"This is a tall bar, covered in drinks and lost souls.\n",
}));
}

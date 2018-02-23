#include <mudlib.h>
inherit PUB;

void reset(status arg) {
   reset_doors(arg);
   load_door(({
      "file",      "d/coronos/w/chi/city/streets/comm8",
      "direction", "pub door",
      "key id",    "domain key",
      "long",
         "Part iron, part oak, the door wears the attitude of this\n"+
         "well.\n",
   }));

   if(arg) return;

   set_short("the Ogre's Milk Pub");
   set_long(
	"\t-=[ Ogre's Milk Pub ]=-\n"+
      "The dwarves that made this city are said to have named the pub\n"+
      "after their drink of choice, Ogre's Milk.  Dimly lit, the pub\n"+
      "exudes an attitude of solitude and independence.  You don't see\n"+
      "many people coming in here to socialize or banter, but rather to\n"+
      "refresh their spirits and thirsts via the many drinks that are\n"+
      "offered here.  The menu is actually engraved into the wooden bar.\n"
   );

   set_items(({
         "bar#names#name#symbol#symbols#wooden bar#oak bar#sturdy bar#"+
         "sturdy oak bar",
      "A sturdy oak bar that has many names and symbols carved into its\n"+
      "surface.  You notice that the menu is carved into the bar as well.\n",
   }));
   set_weather(2,1,0);

   set_owner("trom");

   add_drink("beer", "bottle of beer", "That feels refreshing", 2);
   add_drink("wine", "Glass of fine wine", 
             "A tingling feeling goes through your body", 10);
   add_drink("spirits", "dwarvish spirits", 
             "A shock wave runs through your body", 23);
   add_food("nuts", "handfull of forest nuts", 
            "They are as tasteless as they are appealing", 1);
}


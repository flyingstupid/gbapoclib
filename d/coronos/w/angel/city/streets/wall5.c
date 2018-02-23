/* wall street #5 */
#include <mudlib.h>

#define PATH	"d/coronos/w/angel/city/streets/"
#define MONST	"d/coronos/w/angel/city/monst/"

inherit ROOM;

void reset(status arg) {
  object ob;
  int ii;

  if(!random(4) && !present("guard")) {
    for(ii=0; ii<3; ii++) {
      ob = clone_object(MONST+"guard1");
      move_object(ob, this_object());
    }
  }

  if(arg) return;
  set_short("wall street");

  set_long(
"\tWall Street\n"+
"The outer wall stands strong to the north of this long grey stone  \n"+
"street. Along the south side are small residential buildings, some \n"+
"several stories high, but most of simple design, reflecting the    \n"+
"family nature of this part of Ille Coronos. The majority of people \n"+
"who live here are obviously simple citizens. ");

  set_items(({
	"street", "You stand on Wall Street.\n",
	"stone#stones",
	"The stones are large slabs of grey rock, hand carved by "+
	"dwarven stonemasons.\n",
	"buildings",
	"This is the residential part of Ille Coronos, where the \n"+
	"families of the guard, merchants, and other people live \n"+
	"under the lawful reign of The Circle.\n",
  }));



set_day_desc("The sun shines on\nyou as you walk along here.\n");
  set_day_items(({
"sun#sun shine",
	"Do you want to go blind?!\n",
  }));

  set_night_desc(
"There are tall bronze\n"+
"torch sconces which cast light into the street, keeping it safe.  \n"+
"Lights from the houses shine through their small windows.\n");

  set_night_items(({
"torch#torches",
	"The light flickers, casting dancing shadows onto the road.\n",
	"windows",
	"The windows in the houses have their curtains drawn, making\n"+
	"it impossible to see inside.\n",
	"light",
	"The light from the windows looks inviting.\n",
  }));

  set_weather(2, 4, 0);

  set_exits(({
	PATH+"gate1", "east",
	PATH+"wall4", "west",
  }));
}



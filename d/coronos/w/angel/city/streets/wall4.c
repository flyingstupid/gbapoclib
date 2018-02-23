/* wall street #4 */
#include <mudlib.h>

#define PATH	"d/coronos/w/angel/city/streets/"
#define MONST	"d/coronos/w/angel/city/monst/"
#define NAME	(string)this_player()->query_name()

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
"There is a small bed of flowers in full bloom against the north    \n"+
"wall of the city, growing in strong contrast to the guard house    \n"+
"standing to the far south of the street. Along the south side      \n"+
"of Wall Street are small houses surrounding a temple of some       \n"+
"description. The area is well kept, and very clean. ");


  set_smell("There is the distinct fragrance of flowers in the air.\n");

  set_items(({
	"guard house",
	"The guard house is way down the end of the street",
	"flower#flowers",
	"There are many of them. Someone obviously has a green thumb.\n"+
	"Perhaps you could pick one?",

	"street", "You stand on Wall Street.\n",

	"stone#stones",
	"The stones are large slabs of grey rock, hand carved by "+
	"dwarven stonemasons.\n",

	"buildings",
	"This is the residential part of Ille Coronos, where the \n"+
	"families of the guard, merchants, and other people live \n"+
	"under the lawful reign of The Circle.\n",

	"temple",
	"The temple is a small wooden stone with a high peak. Above \n"+
	"the door is a holy symbol.\n",
	"symbol#holy symbol",
	"The symbol depicts an iconic fist bathed in white-red flames.\n",
	"fist",
	"The fist is clenched tight",
	"flames", "The flames appear not to be burning the fist",
  }));

  set_day_desc(
"The sun shines on\nyou as you walk along here.\n");

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
	PATH+"wall5", "east",
	PATH+"wall3", "west",
  }));
}

void init() {
  ::init();
  add_action("pick", "pick");
}

status pick(string str) {
  object ob;
  string tmp1, tmp2;
  string *desc;

  desc = ({
	"red", "blue", "pink", "violet", 
	"orange", "yellow", "black",
  });

  if(sscanf(str, "%sflower%s", tmp1, tmp2)) {
    if(this_player()->add_weight(1)) {
      ob = clone_object(TREASURE);
      ob -> set_name("flower");
      ob -> set_short("A "+desc[random(sizeof(desc))]+" flower.\n");
      ob -> set_long(
	"The flower looks very beautiful.\n");
      ob -> set_value(10);
      ob -> set_weight(1);
      move_object(ob, this_player());
      write("You pick a flower from the garden.\n");
      say(NAME+" picks a flower from the garden.\n", this_player()); 
    }
    else {
      write("You can't pick the flower, you don't have the strength.\n");
    }
  }
  return 1;
}
 


#include <mudlib.h>

#define MONST   "d/coronos/w/angel/city/monst/"
#define NAME (string)this_player()->query_name()


inherit STORE;


void reset(status arg) {


  if(!present("braiden")) {
    set_owner("braiden");
  }
  if(!present("dwarf")) {
    move_object(clone_object("inherit/dwarf"), this_object());
  } 

  if(arg) return;

  set_short("the city garden");
  set_long(
        "Another group of bottle trees, blooming with red flowers,      \n"+
        "stands in the corner of gardens, against the northwest         \n"+
        "wall. The cobblestone pathway winds close to them, southward,  \n"+
        "along the sides of the garden walls. A small cart stand beside \n"+
	"the garden walls, it's sides over flowing with wares.\n");


  set_day_desc(
     "The sunlight beams down on you from on high, peeking through the \n"+
     "white fluffy clouds.\n");

  set_night_desc(
     "The moon stares down at you as dark sinister clouds pass by.\n");

  set_listen("The air is silent; the sound of peace.\n");

  set_items(({
    "cart",
	"The cart bares all sorts of odds and ends, some weapons and armour, \n"+
	"items of clothing, food and drink, and even treasure. It's owner has\n"+
	"the reputation of only selling to newcommers to Ille Coronos city,  \n"+
	"and sometimes even refuses to sell to locals!. The small cart has a \n"+
	"sign on it's side, noting the prices of items for sale.\n",

     "wall#walls",
          "Tall walls surround the gardens, protecting the flaura and "+
          "fauna inside",
     "bottle tree#bottle trees#tree#trees",
          "So named after its strange shape, the trunk of bottle trees \n"+
          "are almost seven feet in diameter. Their spread of leaves   \n"+
          "make this place ideal for picnics, and for resting in peace",
     "path#cobblestone path#cobblestones#cobblestone",
          "A well travelled cobblestone path",
  }));

  set_day_items(({
     "sunlight#sun#light",
          "Do you want to go blind?",
     "cloud#clouds",
          "They are white and fluffy. One reminds you of an echidna",
  }));

  set_night_items(({
     "moon",
          "You can see the man in the moon. He \n"+
          "appears to be grinning an evil grin at you",
     "cloud#clouds",
          "They look dark and sinister...and very spooky",
  }));

  set_exits(({
        "d/coronos/w/angel/city/gardens/garden1",   "northeast",
        "d/coronos/w/angel/city/gardens/garden6",   "south",
        "d/coronos/w/angel/city/gardens/garden3",   "east",
        "d/coronos/w/angel/city/gardens/garden5",   "southwest",
  }));

  set_weather(2,4,0);

  add_sell_items("clothing");	/* additional treasure items */
  add_sell_items("container");


  set_sell_weapon();		/* standard items */
  set_sell_armour();
  set_sell_treasure();
}

void init() {
  add_action("sell", "sell");
  add_action("buy",  "buy");
  ::init();
}

status sell(string str) {
  if((int)this_player()->query_level() > 5) {
    if(random(10)) {
      write("Braiden asks: Why should I sell to the likes of you?\n");
      return 1;
    }
    write("Braiden says: Oh, alright. I'll sell just this once.\n");
  }
  else {
    write("Braiden says: I just love newcommers to our fair city!\n");
  }
  return ::sell(str);
}

status buy(string str) {
  if((int)this_player()->query_level() > 5) {
    if(random(10)) {
      write("Braiden asks: Why should I buy from the likes of you?\n");
      return 1;
    }
    write("Braiden says: Oh, alright. You can buy just this once.\n");
  }
  else {
    write("Braiden says: I just love newcommers to our fair city!\n");
  }
  return ::buy(str);
}  


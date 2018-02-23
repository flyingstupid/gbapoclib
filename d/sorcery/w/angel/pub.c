#include <mudlib.h>
#include <ansi.h>

inherit PUB;


void reset(status arg) {
  reset_doors(arg);
  load_door(({
	"file", "d/sorcery/w/angel/path7",
	"direction", "north door",
	"long",
         "A large wooden door with a peep hole in the center.\n"+
         "Above the door hangs a sign which reads: "+
         BOLD+BLINK+"the Last Cantrip tavern"+OFF+"\n",
  }));

  if(!present("list")) {
    move_object(clone_object("objects/party_list"),this_object());
  }

  /* hack to make bloodeye come back */
  if(arg) return;

  set_exits(({
     "room/city/pub/foyer", "north",
  }));

  set_short("the Last Cantrip");
  set_long(
	"\t-=[  The Last Cantrip  ]=- \n"+
	"The atmosphere of this little tavern is quite warm and snug; \n"+
	"the very reason why this pub is popular with the local wizards\n"+
	"who make the Tower of High Sorcery their home. The walls bear \n"+
	"a few portraits of those mages who have made this isle famous,\n"+
	"standing watch over the shadowy booths around the room. A few \n"+
	"simple tables and chairs lay scattered about the room in some \n"+
	"order, maximising the pleasant view of the open fire pit toward\n"+
	"the east wall, above which is the tavern's menu.\n");

  set_items(({
	"wall#walls",
	"The walls are made from a rare wed wood that does not grow \n"+
	"in these parts. Hanging at regular intervals along its \n"+
	"are a few portraits of famous wizards and Council members.\n",

	"portraits",
	"Hanging in simple gold frames are some paintings of some of the \n"+
	"mages and wizards who have made the Isle of Sorcery famous. One \n"+
	"is but an empty frame with a small gold plaque underneath.\n",

	"plaque",
	"The plaque reads: 'The One Whose Name is Spoken in Whispers",

	"booth#booths",
	"A warm and dark place to sit and drink",
	"shadow#shadows",
	"They look rather inviting and private; just the way wizards like it",

	"table#tables",
	"A few round tables made from the same wood as the walls stand \n"+
	"around the room, chairs surrounding them. Each has an unobstructed\n"+
	"view of the fire pit",

	"chair#chairs",
	"They are carved from a strong dark pine, and look remarkably "+
	"comfortable",

	"fire pit#pit",
	"The fire pit looks well stoaked. Above is on the wall is the \n"+
	"menu of the Last Cantrip tavern",

	"fire", "Looking at it this way ...is almost hypnotic...\n",
  }));

  set_weather(4,1,0);
  set_owner("flaekos");

  add_drink("beer", "bottle of beer", "That feels refreshing", 2);
  add_drink("draught", "mug of draught", "That was a good drop!", 7);
  add_drink("wine", "Glass of fine wine", 
            "A tingling feeling goes through your body", 10);
  add_drink("ale", "strong ale", "That drop could rip out your throat", 15);
  add_drink("stout", "bottle of stout", "Definitely brewed with magic!", 30);


  add_food("soup", "bowl of vegetable soup", "It tastes like lumpy water", 3);
  add_food("cheese", "cheese", "It smells horrible, but tastes great", 10);
  add_food("bread",  "bread",  "It tasted as lumpy as it looked",18);

  add_sdrink("water", "flask of water", "Quite refreshing!", 2);
  add_sdrink("milk",  "glass of goats milk", "Definitely an aquired taste", 5);
  add_sdrink("broth", "some beef broth", "That was a little watery", 7);
  add_sdrink("broth",  "some chicken broth", "That was a little watery", 8);

}

void init() {
  ::init();
  add_action("read","read");
}

status read(string str) {
  if(str=="list") {
    write("The fonts on the list are too small to read from here. You should get it\n"+
    "before you can read it.\n");
    return 1;
  }
  return 0;
}

#include <mudlib.h>
inherit ROOM;

void reset (status arg){
    if (arg) return;

    reset_doors(arg);
    load_door(({
	"file", 	"d/coronos/w/darkness/rshop",
	"direction", "south door",
	"long", "This is a wooden door made of oak.\n",
	"door id", "south door",
	"key id", "brass key",
	"lock id", "brass lock",
	"lock description", "An old brass lock\n",
	"lock difficulty", 16,
	"closed", "locked",
      }));


    set_short("Main Street");
    set_long(
      "Main Street road continues to run east to west and just to the south \n"+
      "is an old, abandoned shop. Off to the west seems to be a large gate \n"+
      "on the north side of the road.");
    set_day_desc(
      " The street is full of people \n"+
      "going along their way. Right outside the shop is an old lamp post.\n");
    set_night_desc(
      " The quiet street seems empty and is \n"+
      "lit by an oil lamp, hanging from its post by the shop.\n");
    set_items(({
	"door",
	"The door is made of oak and has a sign hanging on it.\n",
	"lamp post#post",
	"This is a simple lamp post.  The oil lamp hangs from the post by a chain.\n",
	"cobblestones#cobblestone",
	"These grey cobblestones have been smoothed and worn over time.\n",
	"road",
	"The road is made from grey cobblestones.\n",      
	"gate",
	"The gate is off to the west.  It looks like it will lead you to \n"+
	"the city gardens.\n",
	"shop#building",
	"The shop is a very old building, and yet it is in very good shape.\n"+
	"It is a one floor building made of brick.  It's display window is\n"+
	"boarded up, and a sign hangs on the door.\n",
	"brick#bricks",
	"These are just ordinary bricks made from red clay.\n",
	"boards#board",
	"These boards are made from strong oak.\n",
	"window",
	"This is a large display window that has been borded up.\n",
	"sign",
	"The sign reads:\n"+
	"| This building for rent.          |\n"+
	"| Ask a City Official for details. |\n",
	"garden#gardens",
	"The gardens are far to the north.  The gate that lets you enter\n"+
	"the gardens is to the west.\n",
      }));
    set_day_items(({
	"lamp#oil lamp",
	"This is a simple oil lamp that hangs from a post.  It is has a metal\n"+
	"frame and glass panels.  The lamp is unlit right now.\n",
      }));
    set_night_items(({
	"lamp#oil lamp",
	"This is a simple oil lamp that hangs from a post.  It has a metal\n"+
	"frame and glass panels.  The lamp shines brightly, illuminating the\n"+
	"area.\n",
      }));
    set_smell(
      "You smell nothing but fresh air.\n");
    set_listen(
      "You faintly hear the squeak of the gate to the west.\n");
    set_weather(2, 4, 0);
    set_exits(({
	"/d/coronos/w/darkness/mainst2", "east",
	"/d/coronos/w/alena/ille/m_1","west",
      }));
}

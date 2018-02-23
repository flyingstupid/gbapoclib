inherit "players/relgar/temple/main.c";
#include "/players/relgar/private/mydefs.h"

reset(arg){
    load_door(({
	"destination","d/tempus/w/relgar/bapod",
	"direction","south door",
	"closed",
	"key id","iron key",
	"lock id","iron lock",
	"lock description",
	"The lock is made from a greyish metal that glows with a soft amber light.\n",
	"locked",
	"desc",
	"The door is made of a smooth stone that is set almost perfectly\n"+
	"into the wall to the south. Only the handle and lock potrude.\n",
	"door number",1,
      }));

    if(arg) return;

    set_short("Private chambers of the cathedral");
    set_light(2);
    set_long(
      "\tYou have made your way into the private worship chambers of the\n"+
      "priests of the Baatezu. There is so much blood on the floors here that \n"+
      "your feet stick to the floor as you walk. To the east you can see statues\n"+
      "flanking a set of double doors to the north. Here on every wall are candle\n"+
      "holders that light the room constantly.\n"
    );
    set_exits(({
	"d/tempus/w/relgar/temp2","east",
      }));
    set_items(({
	"blood",
	"The blood on the floor is at least a centimeter deep and oozes constantly\n"+
	"towards the door to the south. It creeps up all of the walls as if alive.\n",
	"walls#north wall#west wall#south wall",
	"All of the walls here are fairly nondescript grey rock. Each have candle\n"+
	"holders that support the gloomy lighting for this area of the cathedral.\n"+
	"The blood that covers the floor almost creeps up the wall. In places it\n"+
	"goes almost the height of your knee up the wall.\n",
	"candle holders#holders#holder",
	"The holders, each with a candle in them, are all carved to resemble demonic\n"+
	"almost reptilian visages, the candles coming out of howling mouths or\n"+
	"upturned ears.\n",
	"statues#doors#double doors",
	"You'll get a better view of them to the east.\n",

      }));
} /* end of reset */

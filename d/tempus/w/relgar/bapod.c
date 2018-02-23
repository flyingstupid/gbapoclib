inherit "players/relgar/temple/main.c";
#include "/players/relgar/private/mydefs.h"

reset(arg){
    load_door(({
	"destination","d/tempus/w/relgar/temp1",
	"direction","north door",
	"closed","locked",
	"long",
	"A high relief carving of a demon head adorns the door to the north.\n",
	"lock difficulty",8,
	"key id","iron key",
	"lock id","iron lock",
	"lock description",
	"They lock is made from a greyish metal but is glowing with a soft amber\n"+
	"light.\n",
	"trap on",
	"trap description",
	"There appears to be something writhing inside the lock of the door.\n",
	"trap damage",(10+random(20)),
	"trap message",
	"As you try to open the door a large black tentacle lunges out from the\n"+
	"lock and crushes you before falling to dust!\n",
	"trap room message",
	"@@query_name:$this_player()$@@ gets crushed by a large "+
	"black tentacle from the door.\n",
	"door number",1,
      }));

    if(arg) return;

    set_short("The Baatezu sermon podium");
    set_light(2);
    set_long(
      "\tYou stand at the north end of the congregation room of the\n"+
      "cathedral. Just to the east of you is the high podium where priests of\n"+
      "the Baatezu give their sermons. You can see the large cross hanging to\n"+
      "your east and the altar is just to the south of that. There are steps\n"+
      "going to the top of the podium that you might be able to climb.\n"
    );
    set_exits(({
	"d/tempus/w/relgar/tside2","south",
      }));
    set_items(({
	"podium",
	"The podium is very similar to many of the wooden podiums that are often\n"+
	"found in places of holy worship. However, this podium, while also made\n"+
	"of wood, seems to be stained with something making it almost completely\n"+
	"black. The top seems to be blacker than the rest of the podium while the\n"+
	"bottom is almost a light tan color.\n",
	"cross",
	"The cross hangs upside down to the east of you. You notice that it \n"+
	"constantly drips blood. One of the arms hangs above the podium dripping\n"+
	"its gory fluid on the priests giving the sermons.\n",
	"altar","You'd get a better look if you moved closer.\n",
	"steps","You might be able to climb them to get to the top of the podium.\n",
      }));
} /* end of reset */

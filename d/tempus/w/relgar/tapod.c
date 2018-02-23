inherit "/players/relgar/temple/main.c";
#include "/players/relgar/private/mydefs.h"

reset(arg){
    load_door(({
	"destination","d/tempus/w/relgar/temp3",
	"direction","north door",
	"closed",
	"locked",
	"lock difficulty",12,
	"key id","bronze key",
	"lock id","bronze lock",
	"trap on",
	"trap description",
	"The handle appears to be glowing red with heat.\n",
	"trap damage",(10+random(20)),
	"trap message",
	"As you grab the handle, a long spear of flame shoots from the keyhole!\n",
	"trap room message",
	"@@query_name:$this_player()$@@ is torched by a long spear of flame "+
	"from the key hole of the door!\n",
	"key","None yet.",
	"long",
	"A high relief, demons visage adorns the north door here.\n",
	"door number",1,
      }));

    if(arg)return;
    set_short("The Tanar'ri sermon podium");
    set_light(2);
    set_long(
      "\tYou stand at the northern end of the cathedral. To your west is\n"+
      "large cross that the congregation prays to. There is a large podium here \n"+
      "that priests who worship the Tanar'ri give their sermons from. There are\n"+
      "some steps going to the top of the podium that you might be able to climb\n"+
      "with some luck.\n"
    );
    set_items(({
	"cross",
	"The cross to the west is the same large, upside down cross that the \n"+
	"congregation worships. It constantly drips with blood. One of the arms of\n"+
	"the cross hangs over the podium here, dripping its gory fluid on those\n"+
	"priests giving sermons.\n",
	"podium",
	"This podium appear to be made from a silvery type of wood. It looks just\n"+
	"like normal wooden podiums that are found in places of holy worship but\n"+
	"the lower half of the podium seems to be stained with some dark substance.\n"+
	"",
	"steps","With some luck you might be able to climb them.\n",
      }));
    set_exits(({
	"d/tempus/w/relgar/tside1","south",
      }));
} /* end of reset */

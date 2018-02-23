inherit "d/tempus/w/relgar/main.c";
#include "/players/relgar/private/mydefs.h"

reset(arg){

    if (arg) return;
    set_light(2);
    set_short("the southeast corner of the cathedral.");
    set_long(
"\tYou are standing just to the east of the main\n"+
"door of the cathedral. In the southeast corner of the room\n"+
      "here there is a large stone statue. There are several stained\n"+
      "glass windows with demonic scenes of death and destruction. The outside\n"+
      "light barely passes through the almost opaque glass. There are several\n"+
      "stone columns here with torch sconces hanging from them.\n"
    );
    set_items(({
	"statue",
	"The large stone statue stands at least twelve feet tall. It is made of\n"+
	"a dark, grey stone. It looks to be some sort of humanoid but has large\n"+
	"wings that sprout from its back. The face has large, tusk-like fangs\n"+
	"that look as though they are dripping with saliva.\n",
	"windows#scenes#glass windows#demonic scenes",
	"The scenes depicted on the windows are fairly grotesque. Most of them\n"+
	"show vaguely humanoid, amorphous bipods devouring humans, and demi-humans\n"+
	"alike.\n",
	"columns",
	"The stone columns are made from black marble with white veins of quartz\n"+
	"running throughout.\n",
      }));

    set_exits(({
	"d/tempus/w/relgar/entrance","east",
	"d/tempus/w/relgar/tside2"  ,"north",
      }));

} /* end of reset */

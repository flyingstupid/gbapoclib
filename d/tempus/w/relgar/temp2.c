inherit "players/relgar/temple/main.c";
#include "/players/relgar/private/mydefs.h"

reset(arg){
    load_door(({
	"destination","d/tempus/w/relgar/arena",
	"direction","north door",
	"closed",
	"key id","iron key",
	"lock id","iron lock",
	"locked",
	"desc",
	"The double doors to the north are made from a phosphorescent form of wood\n"+
	"that lights the entire room with its glow. It has an iron lock.\n",
	"lock description",
	"The lock is made from a greyish metal that glows with a soft amber light.\n",
	"door number",1,
      }));

    if(arg) return;
    set_short("The private chambers of the cathedral");
    set_light(2);
    set_exits(({
	"d/tempus/w/relgar/temp1","west",
	"d/tempus/w/relgar/temp3","east",
      }));
    set_long(
      "        You stand in the private chambers of the cathedral. None of the \n"+
      "congregation ever see this section of the temple. Those unfortunate enough\n"+
      "to get a tour of this section never see the light of day again. There\n"+
      "are two statues to the north that flank a pair of double doors. There is a\n"+
      "continuous stream of blood that flows from beneath the doors.\n"
    );
    set_items(({
	"statue 1#left statue#statue on the left",
	"The statue on the left stands twelve feet tall and has been painted\n"+
	"a bright red color. It seems to leer down at you with its snarling fang-\n"+
	"filled maw. A leathery pair of wings are folded at its back and its large\n"+
	"arms and legs each sport wicked claws at each end.\n",
	"statue 2#right statue#statue on the right",
	"The statue on the right has been painted a dark red color. It stands twelve\n"
	+
	"feet tall. It looks like a tall human except that its head is not human.\n"+
	"The 'head' consists of actually two heads. One is that of a snarling dog,\n"+
	"always aware of its surroundings, and the other is that of a serpent, long\n"+
	"and prehensile. The snake head is facing towards the back of the statue as\n"+
	"though looking behind itself. The statue holds in its hands a huge, double\n"+
	"headed axe and it wears a long cape about its shoulders.\n",
	"statue",
	"The statue on the left or the statue on the right?\n",
	"stream of blood#blood#stream",
	"The stream of blood flows slowly from beneath the north doors. It covers \n"+
	"the floor and makes it slightly sticky in places and slightly slippery in\n"+
	"others.\n",
      }));

} /* end of reset */

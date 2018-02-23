#include "/players/relgar/private/mydefs.h"
inherit "/d/tempus/w/relgar/main.c";

reset(arg){
    load_door(({
	"destination","d/tempus/w/relgar/temp2",
	"direction","south door",
	"closed","locked",
	"lock difficulty",25,
	"long",
	"The huge double doors to the south are made from some type of phosphorescent\n"+
	"wood that lights up the whole room here.\n",
	"key id","iron key",
	"lock id","iron lock",
	"lock description",
	"The lock is made from a greyish metal that is glowing with a strange light.\n",
	"door number",1,
      }));
    if(arg)return;
    set_short("Inside the arena");
    set_light(2);
    set_long(
      "        You stand at the top of a large bowl shaped arena. Your whole \n"+
      "vision is taken up by the enormous face of some spawn of hell that covers\n"+
      "the wall far to the north. You notice that there is a large pool of blood\n"+
      "under the face that covers the entire arena floor. There are several forms\n"+
      "lying in the pool that, while dead and far away still make shivers run the\n"+
      "length of your spine. There are some steps that lead down to the north.\n"
    );
    set_items(({
	"arena#bowl",
	"You are standing at the top of the bowl shaped arena. It is filled with \n"+
	"many cheering and jeering priests of the Baatezu and the Tanar'ri.\n",
	"face#spawn#spawn of hell",
	"The face of the spawn of hell completely covers the entire north wall of \n"+
	"the arena. It seems to be a horned skull with several waving tentacles in\n"+
	"place of a mouth. Each of the tentacles is tipped with a needle shaped \n"+
	"barb. Several of them have quivering corpses attached to them.\n",
	"blood#pool#arena floor#floor#pool of blood",
	"The large pool of blood that covers the floor is mixed with several slain\n"+
	"forms of humanoids and non-humanoids alike. The blood itself covers all \n"+
	"the walls and even runs across the ceiling. It runs down the wall to the\n"+
	"south and drains out the door on the floor.\n",
	"forms",
	"The forms lying in the pool are terrible to behold. You can't imagine\n"+
	"facing any of them in battle, let alone facing whatever killed them \n"+
	"in battle.\n",
	"steps",
	"The steps lead down and to the north.\n",
      }));
    set_smell(
      "You can smell the blood and death of many combatants in the arena.\n"
    );
    set_listen(
      "You can't hear anything over the din of the raging priests watching the \n"+
      "contest on the arena floor.\n"
    );
} /* end of reset */

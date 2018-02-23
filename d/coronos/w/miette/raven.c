#include <mudlib.h>
inherit MONSTER;


void reset(status arg) {
    ::reset(arg);
    if (arg) return;

    set_name("raven");
    set_plural("ravens");
    set_money(random(2)+2);
    set_long(
      "A large bird of the crow family, having lustrous black feathers and a \n"+
      "straight, sharp beak.  They are characterized by intelligence and the \n"+
      "power of uttering articulate sounds in a hoarse ominous voice.  Ravens \n"+
      "do not wait, as some say, for the noise of battle; they can be seen \n"+
      "following armed bands of men for miles, waiting for the clash and the\n"+
      "kill.\n");
    load_chat(7,({
	"Raven shrieks: Caw! Caw!\n",
	"Raven looks at you and says: Nevermore!\n",
	"Raven shrieks: Caw!\n",
	"Raven flaps its wings.\n",
	"Raven hops about.\n",
      }));
    set_level(4 + random(3));
    set_dexterity(15);
    set_alignment(0);
    set_race("raven");
    set_gender(0);
    set_attack_msg(({
	"misses", "\b.",
	"scatches", "slightly with its claws",
	"nips", "with sharp beak",
	"draws blood from", "with nasty claws",
	"bites", "hard with its wicked beak",
	"leaps on", "trying to bite your eyes out",
      }));
}

#include <mudlib.h>
inherit MONSTER;

object cloak, bag, xbow, bolt, arm;
void reset(status arg) {
  int i;

  ::reset(arg);
  if(!cloak) {
    cloak = clone_object(CLOTHING);
    cloak -> set_name("cloak");
    cloak -> set_short("A simple black cloak");
    cloak -> set_long(
	"A fine black cloak with a purplpe hem. It looks \n"+
	"quite expensive, and appears to be hand made from\n"+
	"some sort of silk.\n");
    cloak -> set_weight(1);
    cloak -> set_value(500);
    move_object(cloak, this_object());
    init_command("wear cloak");
  }

  if(!arm) {
    arm = clone_object(ARMOUR);
    arm -> set_name("leather");
    arm -> set_type("armour");
    arm -> set_armour_material("leather");
    arm -> set_ac(1);
    arm -> set_weight(1);
    arm -> set_short("a suit of black leather armour");
    arm -> set_long(
	"A fine suit of black leather armour. Obviously its \n"+
	"owner was meticulous about its care and maintenance.\n"+
	"The lapel on the site bears a strange marking of the\n"+
	"likes you have never seen before.\n");
    arm -> set_alias("marking");
    arm -> set_read("You don't understand what it says.\n");
    arm -> set_info("The rune is that of a drow house.\n");
    arm -> set_value(300);
    move_object(arm, this_object());
    init_command("wear armour");
  }

  if(!bag) {
    bag = clone_object("objects/quiver");
    bag -> set_alias("quiver");
    bag -> set_short("A quarrel");
    bag -> set_name("quarrel");
    bag -> set_long("You put crossbow bolts inside.\n");
    bag -> set_weight(1);
    bag -> set_value(100);
    move_object(bag, this_object());
  }

  if(!xbow) {
    xbow = clone_object("objects/bow");
    xbow -> set_name("handcrossbow");
    xbow -> set_alias("crossbow");
    xbow -> set_short("A hand crossbow");
    xbow -> set_long(
	"A fine hand crossbow, with gold trimmings. This is \n"+
	"not made by human hands.\n");
    xbow -> set_value(1000);
    xbow -> set_weight(2);
    xbow -> set_ammunition("bolt");
    move_object(xbow, this_object());
    init_command("wield crossbow");
  }

  for(i=0; i<5; i++) {
    bolt = clone_object("objects/arrow");
    bolt -> set_name("bolt");
    bolt -> set_short("A bolt");
    bolt -> set_long("A crossbow bolt made from a black wood.\n");
    bolt -> set_weight(1);
    bolt -> set_value(10);
    move_object(bolt, bag);
  }

  if(arg) return;
  set_alias("merchant");
  set_name("di'illan");
  set_gender(1);
  set_race("dark elf");
  set_alias("merchant");
  set_alt_name("elf");
  set_alias("dark elf");
  set_level(13);
  add_money(150 + random(100));
  set_short("Di'Illan, the simple merchant");
  set_long(
	"There is something not quite right about this simple    \n"+
	"merchant. He hides deep within the hood of his cloak    \n"+
	"and seems more intent on watching you, and those around \n"+
	"him, than getting to market on time. There is something \n"+
	"about him that makes you suspect he is quite powerful.\n");
  set_magic_resist(10);
  add_class("fighter");
  add_class("thief");
  add_class("mage");
  load_spells(15, ({
	"magic missile", "acid arrow", "acid rain",
	"burning hands", "enlarge",
  }));

  load_l_chat(5, "elf", ({ "Be ready for the drow attack",
	"If you be an allie, be ready for the drow attack",
	"The drow attack comes soon",
	"Ille Coronos will fall soon",
	"Ille Coronos will meet its doom!",
  }));

  load_chat(5, ({ "Di'Illan says: I am selling fine cloth.\n",
	"Di'Illan asks: Where is the market place?\n",
	"Di'Illan asks: You haven't seen the guards have you?\n",
  }));

  load_a_chat(5, ({ "Di'Illan says: My kindred will take vengence.\n",
	"Di'Illan says: Lolth shall have your soul.\n",
	"Di'Illan exclaims: Lolth, save me!\n",
  }));
  set_wander(50, 1000);
  set_alignment(-1000);
  set_domain("city");
}

#include <mudlib.h>
inherit MONSTER;

object cloak, bag, xbow, bolt, arm;
void reset(status arg) {
  int i;

  ::reset(arg);
  if(!cloak) {
    cloak = clone_object(CLOTHING);
    cloak -> set_name("cloak");
    cloak -> set_short("A black cloak");
    cloak -> set_long(
        "A fine black cloak with a purple hem. It looks \n"+
        "quite expensive, and appears to be hand made from\n"+
        "some sort of silk.\n");
    cloak -> set_weight(1);
    cloak -> set_value(500);
    move_object(cloak, this_object());
    init_command("wear cloak");
  }

  if(!arm) {
    arm = clone_object(ARMOUR);
    arm -> set_name("chainmail");
    arm -> set_type("armour");
    arm -> set_armour_material("adamantite");
    arm -> set_ac(3);
    arm -> set_weight(4);
    arm -> set_short("a suit of black chainmail");
    arm -> set_long(
	"A fine suit of chainmail whose links are delicate, yet as \n"+
	"strong as adamantite armour. There is a sigil on the arm  \n"+
	"which identifies the armour as the property of the house  \n"+
	"of Noquar.\n");

    arm -> set_alias("sigil");
    arm -> set_read("You don't understand what it says.\n");
    arm -> set_info("The rune is that of a drow house, Noquar.\n");
    arm -> set_value(1200);
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
  set_name("ka'ldaer");
  set_alias("scout");
  set_gender(1);
  set_race("dark elf");
  set_alt_name("elf");
  set_level(15);
  set_max_hp(350);
  set_hp(350);
  set_magic_resist(75);
  add_money(150 + random(100));
  set_short("Ka'ldaer, the drow scout");
  set_long(
	"Ka'ldaer is one of a scouting party watching the huamn city to the south.\n"+
	"He is ever watchful for the enemies of the house of Noquar and will slay \n"+
	"any opponent without question.\n");

  add_class("fighter");
  add_class("thief");
  add_class("mage");
  load_spells(15, ({
        "magic missile", "acid arrow", "acid rain",
        "burning hands", "enlarge", "fire shield", "shield",
	"fire ball", "lightning bolt",
	"cone of cold", "resist fire", "resist lightning",
	"burning hands",
  }));


  load_l_chat(5, "elf", ({ 
	"Ille Coronos, such a weak city",
	"I hate humans",
	"I hate all surface dwellers",
	"I hate surface elves",
	"I hate gnomes",
	"I hate smelly orcs, but I will put up with them",

  }));

  load_chat(3, ({ 
	"Ka'ldaer looks on the ground for tracks.\n",
	"Ka'laer looks at you carefully.\n",
	"Ka'ldaer asks: Are you friend or enemy of Noquar?\n",
  }));


  load_a_chat(5, ({ 
	"Ka'ldaer: My kindred will take vengence.\n",
        "Ka'ldaer says: Lolth shall have your soul.\n",
        "Ka'ldaer exclaims: Lolth shall save me!\n",
  }));

  set_wander(50, 1000);
  set_alignment(-1000);
  set_domain("ud");
}

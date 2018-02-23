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
    arm -> set_short("A suit of black chainmail");
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

  if(!xbow) {
    xbow = clone_object(WEAPON);
    xbow -> set_name("longsword");
    xbow -> set_type("slash");
    xbow -> set_short("A black longsword");
    xbow -> set_long(
	"The blade of this longsword is forged from some sort of \n"+
	"dark, black metal. The hilt is wrought from gold and is \n"+
	"set with a few semi precious gems. The whole design is  \n"+
	"familiar as drow in origin.\n");
    xbow -> set_length(45);
    xbow -> set_wc(16); /* +3 sword */
    xbow -> set_weight(6);
    xbow -> set_value(3300);
    xbow -> set_alias("sword");
    xbow -> set_enchanted(1);
    move_object(xbow, this_object());
    init_command("wield longsword");
  }



  set_ac(10);
  set_wc(17);

  if(arg) return;
  set_name("drow");
  set_alias("scout");
  set_gender(1);
  set_race("dark elf");
  set_alt_name("elf");
  set_level(13);
  set_max_hp(300);
  set_hp(300);
  set_magic_resist(75);
  add_money(150 + random(100));
  set_short("A drow scout");
  set_plural("drow scouts");
  set_long(
  "As one of Ka'ldaer's men, this drow is keen eyed, and ready for \n"+
  "an attack by the humans and other creatures of the surface world.\n"+
  "He looks a litlte more tough than the weak drow who were banished\n"+
  "from the Underdark with their priestess leader.\n");

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
	"That priestess brings us nothing but shame",
	"The drow outside this cave have been banished",
	"Lolth have mercy on the priestess, and slay her quickly",
  }));

  load_chat(3, ({ 
	"Drow keeps an eye open for surface dwellers.\n",
	"Drow watches you closely.\n",
	"Drow asks: From where do you hail?\n",
  }));


  load_a_chat(5, ({ 
	"Drow moves swiftly.\n",
	"Drow says: You will not defeat me so easily.\n",
	"Drow says: Loth shall have your soul.\n",
	"Drow laughs at you.\n",
  }));

  set_alignment(-700);

}

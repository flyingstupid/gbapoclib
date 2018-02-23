#include <mudlib.h>
inherit MONSTER;

object a1, a2, w1;

void reset(status arg) { 
  string *tmp, Tmp;
  ::reset(arg);

  if(!a1) {
    tmp = ({
	"boots", "gloves", "helm", 
    });
    Tmp = tmp[random(sizeof(tmp))];
    a1 = clone_object(ARMOUR);
    a1 -> set_weight(1);
    a1 -> set_ac(1);
    a1 -> set_value(300);
    a1 -> set_name(Tmp);
    a1 -> set_type(Tmp);
    a1 -> set_armour_material("leather");

    switch(Tmp) {
      case "boots" : case "gloves" :
      a1 -> set_short("A pair of "+Tmp);
      a1 -> set_long(
	"This pair of "+Tmp+" could not have been made by orcish hands, even \n"+
	"though the smell of it might make you think otherwise. The sigil on \n"+
	"the sides indicates it is of drow design.\n");
      break;

      default :
      a1 -> set_short("A helm");
      a1 -> set_long("This "+Tmp+" could not have been made by orcish hands, even \n"+
	"though the smell of it might make you think otherwise. The sigil on \n"+
	"the sides indicates it is of drow design.\n");
      break;
    }
    move_object(a1, this_object());
    init_command("wear "+Tmp);
  }


  if(!a2) {
    a2 = clone_object(ARMOUR);
    a2 -> set_type("armour");
    a2 -> set_armour_material("leather");
    a2 -> set_ac(2);
    a2 -> set_weight(2);
    a2 -> set_value(600);
    a2 -> set_name("leather armour");
    a2 -> set_alias("leather");
    a2 -> set_short("A suit of studded leather armour");
    a2 -> set_long(
	"A fine suit of studded leather armour. While it smells terribly of \n"+
	"orc sweat, the sigil on the sleeve and typical design of the outfit\n"+
	"suggests that the drow of the house of Noquar fashioned them.\n");
    move_object(a2, this_object());
    init_command("wear leather");
  }

  if(!w1) {
    w1 = clone_object(WEAPON);
    w1 -> set_name("longsword");
    w1 -> set_alias("sword");
    w1 -> set_type("slash");
    w1 -> set_short("A longsword");
    w1 -> set_long(
	"This appears to be more of a weapon of the drow than an orcish longsword.\n"+
	"The blade is keen edged and in very good condition, even though it smells\n"+
	"of orcish sweat and blood.\n");
    w1 -> set_wc(15); /* +2 longsword*/
    w1 -> set_length(45);
    w1 -> set_weight(6);
    w1 -> set_value(2600);
    move_object(w1, this_object());
    init_command("wield longsword");
  }

  set_level(12);
  set_max_hp(230);
  set_hp(230);

  if(arg) return;

  set_name("lieutenant");
  set_gender(1);
  set_short("An orc lieutenant");
  set_long(
	"The head warrior of his clan, this lieutenant appears to have been \n"+
	"trained in more than biting and clawing his victims. The armour he \n"+
	"wears and the way he stands suggests that he is a fit fighting machine.\n"+
	"The beads he wears around his neck also suggest he is a shaman of sorts\n");

  set_race("orc");

  load_l_chat(5, "orc", ({
	"What are you doing here?",
	"Go away, else the master sees you!",
	"Be gone, the dark elves will have your head, and mine!",
  }));

  load_chat(5, ({ 
	"Lieutenant mumbles.\n",
	"Lieutenant watches you carefully.\n",
	"Lieutenant says: Salute me, you big pig.\n",
	"Lieutenant sniffs.\n",
	"Lieutenant picks his nose.\n",
	"Lieutenant rubs "+query_possessive()+" groin.\n",
	"Lieutenant swears in some unknown language.\n",
	"Lieutenant sizes you up.\n",
	"Lieutenant says: Me the leader here.\n",
	"Lieutenant says: Me boss.\n",
  }));

  add_class("fighter");
  add_class("cleric");
  set_magic_resist(25);
  load_spells(30, ({
	"bless", "curse", "cure light wounds", "cure serious wounds",
	"cure wounds", "cause wounds", "cause light wounds", "sts",
	"barkskin",
  }));
}

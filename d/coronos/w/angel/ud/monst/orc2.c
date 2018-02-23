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
    a1 -> set_type(Tmp);
    a1 -> set_armour_material("leather");
    a1 -> set_name(Tmp);

    switch(Tmp) {
      case "boots" : case "gloves" :
      a1 -> set_short("A pair of "+Tmp);
      a1 -> set_plural("pairs of "+Tmp);
      a1 -> set_long(
	"This pair of "+Tmp+" could not have been made by orcish hands, even \n"+
	"though the smell of it might make you think otherwise. The sigil on \n"+
	"the sides indicates it is of drow design.\n");
      break;

      default :
      a1 -> set_short("A helm");
      a1 -> set_plural("helms");
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
    a2 -> set_name("leather armour");
    a2 -> set_alias("leather");
    a2 -> set_short("A suit of studded leather armour");
    a2 -> set_plural("suits of studded leather armour");
    a2 -> set_long(
	"A fine suit of studded leather armour. While it smells terribly of \n"+
	"orc sweat, the sigil on the sleeve and typical design of the outfit\n"+
	"suggests that the drow of the house of Noquar fashioned them.\n");
    a2 -> set_value(600);
    move_object(a2, this_object());
    init_command("wear leather");
  }

  if(!w1) {
    w1 = clone_object(WEAPON);
    w1 -> set_name("spear");
    w1 -> set_type("pierce");
    w1 -> set_short("A spear");
    w1 -> set_plural("spears");
    w1 -> set_long(
	"While this wooden spear seems simple enough, the head is made from a \n"+
	"fine black metal. The whole design makes you wonder whether an orc or\n"+
	"some more advanced humanoid made the weapon.\n");
    w1 -> set_wc(12); /* +2 spear */
    w1 -> set_length(60);
    w1 -> set_weight(3);
    w1 -> set_value(1700);
    move_object(w1, this_object());
    init_command("wield spear");
  }

  set_level(5 + random(10));
  set_alignment(-(10 + random(100)));
  add_class("fighter");
  add_class("thief");

  set_max_hp(100 + random(150));
  set_hp(query_max_hp());

  if(arg) return;

  set_name("orc");
  set_alias("warrior");
  set_gender(random(2) + 1);
  set_short("An orcish warrior");
  set_long(
"This orc looks as though he has been trained for years in the tactics \n"+
"of military warfare. "+capitalize(query_pronoun())+" looks as though he has been in \n"+
"this army for many years. \n");
  set_race("orc");

  load_l_chat(5, "orc", ({
	"What are you doing here?",
	"Go away, else the master sees you!",
	"Be gone, the dark elves will have your head, and mine!",
  }));

  load_chat(5, ({ 
	"Orc mumbles.\n",
	"Orc watches you carefully.\n",
	"Orc says: Go away.\n",
	"Orc sniffs.\n",
	"Orc picks his nose.\n",
	"Orc rubs "+query_possessive()+" groin.\n",
	"Orc swears in some unknown language.\n",
	"Orc stands you up.\n",
  }));

  load_a_chat(5, ({
	"Orc exclaims: Hail to Gruumish!\n",
	"Orc says: The One Eye will slay you!\n",
	"Orc swears.\n",
	"Orc grumbles.\n",
	"Orc growls.\n",
  }));
}


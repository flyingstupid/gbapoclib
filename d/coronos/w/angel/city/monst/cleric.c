/* Cleric of the All-God
 * Angel, October 1993.
 */

object robe, symb;

#include <mudlib.h>
inherit MONSTER;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("cleric");
  set_short("A cleric of the All-God");
  set_long("This is a devout follower of the All-God.\n");
  set_gender(random(2) + 1);
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_hp(100);
  set_al(300 + random(200));
  load_chat(9, ({ "Cleric asks: Do you know the one true way, my friend?\n",
     "Cleric asks: Who do you seek, my child?\n",
     "Cleric smiles peacefully.\n",
     "Cleric prays a silent prayer.\n",
     "Cleric looks toward the heavens for spiritual guidance.\n"
  }));
  load_a_chat(10, ({ "Cleric exclaims: How dare you!\n",
     "Cleric says: This is blasphemy.\n",
     "Cleric prays a silent prayer.\n",
     "Cleric cries out in pain.\n",
     "Cleric calls for divine aid.\n",
  }));

  load_spells(2, ({ "clw"}));
  set_race("human");

  robe = clone_object(CLOTHING);
  robe -> set_name("robe");
  robe -> set_alias("robes");
  robe -> set_short("white clerical robes");
  robe -> set_long("The bear the symbol of the All-God upon them.\n");
  robe -> set_value(50);
  robe -> set_sell_destruct(1);
  robe -> set_weight(1);
  move_object(robe, this_object());
  init_command("wear robe");

  symb = clone_object(CLOTHING);
  symb -> set_name("holy symbol");
  symb -> set_alias("symbol");
  symb -> set_short("A platinum holy symbol");
  symb -> set_weight(1);
  symb -> set_sell_destruct(1);
  symb -> set_value(20 + random(100));
  symb -> set_long(
     "This holy symbol bears silver dragons looped in a figure eight, each\n"+
     "chasing the others tail. This is the symbol of the All-God that his \n"+
     "clerical follers wear. It appears to be made of platinum.\n");
  move_object(symb, this_object());
  init_command("wear symbol");
}


 

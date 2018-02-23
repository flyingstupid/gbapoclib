/* potion */

#include <mudlib.h>

inherit DRINK;
inherit WAND;

string spell;

string query_spell();
status set_spell(string s);

void reset(status arg) {
  if(arg) return;
  set_name("potion");
  set_plural("potions");
  set_short("Potion");
  set_info("@@query_potion_string:$this_object()$@@");
  set_spell("cure wounds"); /* default potion */
  set_weight(1);
  set_room_msg("@@query_name:$this_player()$@@ quaffs a potion.\n");
}

void init() {
  drink::init();
  wand::init();
  add_action("drink", "drink");
  add_action("drink", "quaff");
}

string query_object_type() { return "Potion"; }

string query_spell()       { return spell; }

status set_spell(string s) { 
  string *loading_spell;
  int i;

  if(!s) return 0;
  loading_spell = (mixed *)clone_object("obj/shadows/get_spell")->get_spell(s);  
  if(member_array("passive", loading_spell) == -1) return 0;
  if((i = member_array("level", loading_spell)) != -1) {
    set_cast_level(loading_spell[i+1]);
    set_charges(100);
    spell = s;
    set_casting_msg("You quaff a @@query_name:$this_object()$@@ of "+
                    spell +".\n");
    set_spells(({ "drink", spell,
                  "quaff", spell,
    }));  /* activation 'words' have to be query_verb() to add_action() */
    return 1;
  }
  return 0;
}

void add_spell(mixed arg) {
  if(!arg) return;
  if(stringp(arg)) arg = ({ arg, });
  set_spell(arg[0]);
}

status drink(string str) {
  if(drink::drink(str)) {
    if(spell && query_charges()) {
      load_spell();
      set_full(0);
      set_plural("empty bottles");
    }
  }
  else {
    write("!The "+query_name()+" is empty!\n");
  }
  return 1;
}

void end_spell() {
  charges = 0;
}
 
string query_potion_string() {
  if(query_full() && spell) {
    return "It is a Potion of "+ capitalize(spell) +".\n";
  }
  else {
    return "You find nothing special.\n";
  }
}


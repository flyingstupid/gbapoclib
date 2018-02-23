/***************************************************************************
/* armour that imbues a magical protection, and spell casting when worn */

#include <mudlib.h>
inherit ARMOUR;
inherit WAND;

string protection;
string query_object_type()  	    { return "Magic Armour";   }
string query_protection()         { return protection;       }
string set_protection(string str) { return protection = str; }


int query_value() { return armour::query_value()+wand::query_value(); }

mapping query_specs() {
  return ([
	"protection" 	: protection 
  ]) + armour::query_specs()
     + wand::query_specs(); /* wow, funky, hu? */
}


status wear(string str) {   /* redo the wear string */
  status flag;

  flag = armour::wear(str);
  if(worn) {
    if(protection) environment()->add_spell_immunity(protection);
    wand::init(); 
  }
  return flag;
}

status drop(status quit) {
  if(protection) environment()->remove_spell_immunity(protection);
  return armour::drop(quit);
}

status remove(string str) {  
  move_object(this_object(), environment()); /* remove spell actions */
  if(protection) environment()->remove_spell_immunity(protection);
  return armour::remove(str);
}

void init() {
  armour::init();
}


/* for info */

string query_protection_string() {
  if(protection) {
    return "The "+ query_name() +" will protect you from "+
           protection +" when it is worn.\n";
  }
}



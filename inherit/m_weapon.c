/**********************************************************************/
/* magic weapon that can imbue magic protection and cast spells when  */
/* wielded                                                            */

#include <mudlib.h>
inherit WEAPON;
inherit WAND;


string protection;
string query_object_type() 	    { return "Magic Weapon";   }
string query_protection()         { return protection;       }
string set_protection(string str) { return protection = str; }

int query_value() { return weapon::query_value()+wand::query_value(); }

mapping query_specs() {
  return ([
	"protection" : protection,
  ]) 
  + weapon::query_specs() + wand::query_specs();
}

status drop(status silently) {  
  if(protection) environment()->remove_spell_immunity(protection);
  return weapon::drop(silently);
}  


status wield(string wielding) {  
  status flag;
  flag = weapon::wield(wielding);
  if(wielded) {
    if(protection) environment()->add_spell_immunity(protection);
    wand::init();
  }
  return flag;  
}  

void init() {
  if(environment()) weapon::init();
  wand::init();
}


/* for info */

string query_protection_string() {
  if(protection) {
    return "The "+ query_name() +" will protect you from "+
           protection +" when it is wielded.\n";
  }
}


/******************************************************************************
 * progeny.c
 * Staff of the Progeny
 * 
 * Pulse,
 * October 1996
 */
 
#include <mudlib.h>
inherit MAGIC_WEAPON;
 
void reset(status arg) {
  ::reset(arg);
  
  if(arg) {
    return;
  }
  
  set_name("staff");
  set_alias("progeny");
  set_plural("staves");
  
  set_short("Staff of the Progeny");
  set_long(
    "This deep scarlet staff is emblazened with numerous arcane runes which\n"+
    "glow with a flame-colored hue.  The staff eminates an intense heat.\n"
  );
  
  set_read("The runes are written in an ancient language you can't read.\n");
  
  add_spell("fire ball");
  add_spell("fire shield");
  add_spell("bbb");
  set_protection("fire");
  set_class( ({ "mage", "cleric" }) );
  
  set_charges(100);
  set_cast_level(25);
  set_info("This staff protects from fire.\n");
  
  /* +5 staff */
  set_wc(16);
  set_type("crush");
  set_length(72);
  set_weight(4);
  set_value(15000);
}
 
status wield(string str) {
  string message;
  message="ok";
  
  if (id(str)) {
    if (!this_player()->query_class("mage")) {
      message =
	"You don't seem to have the proper training to\n"+
	"control the powerful magics this staff contains.\n";
    }
    
    if (message != "ok") {
      write("The staff burns in your hands!  "+message); 
      environment()->hit_player(10+random(20));
      return 1;
    }
    else {
      write("You feel powerful energy stream through your body.\n");
      return ::wield(str);
    }
  }
 
  return ::wield(str);
}
 
 
int hit(object target) {
  if (target->query_level() <5) {
    tell_object(environment(), 
		"The staff consumes "+target->query_name()+
		" in a billow of fire!\n");
    /* This will most likely kill a monster under level 5 */
    return (::hit(target) * 2);
    return 0;
  }
  else  {
    return ::hit(target);
  }
}
 

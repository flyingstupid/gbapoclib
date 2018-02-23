#include <mudlib.h>
#include <ansi.h>

/* Sword of Life Stealing */
/* Note that this sword is neutral, and therefore has no alignment
 * for wielding it. The sword does not care WHO it drains, so long
 * as it DOES get to drain something.
 */

inherit MAGIC_WEAPON;

void reset(status arg) {
  if(arg) return;
  set_name("shortsword");
  set_type("slash");
  set_alias("sword");
  set_alt_name("lifestealer");
  set_length(24);
  set_wc(15); /* +5 of life stealing */

  set_weight(5);

  set_value(6000); /* due to special fn */

  set_short("A black shortsword");
  set_plural("black shortswords");
  set_long(
	"This shortsword has a keen edge and is fashioned in the\n"+
	"drow tradition from some kind of black metal. The hilt \n"+
	"has been decorated with fine silk threads braided together\n"+
	"to form a flowing tassle of gold and purples.\n");

  set_info("This sword drains the living essence from victims, and\n"+
	   "is more commonly referred to as a 'Life Stealer'.\n");

  set_hit_func(this_object());
}


int weapon_hit(object target) {
  if(!target) return 0;

  if(!random(20)) { /* 5% chance to drain only, like AD&D */

    tell_object(environment(),
	"The sword in your hand glows a bright "+BOLD+CYAN_F+
	"blue!"+ OFF +"\n");
    say(environment()->query_name()+"'s sword glows a "BOLD+CYAN_F+
	"bright blue!"+ OFF +"\n", environment());

    if(target->id("undead")) {
      tell_object(environment(),
      "A vortex opens between you and "+target->query_name()+", and \n"+
      "your life energy is swept away toward "+target->query_name()+"!\n");

      say(environment()->query_name()+" cries out in pain and is "+
	"drained of some life essence!\n", environment());

      environment()->drain_level();
      return 0;
    }
  
    if(target->query_spell_immunity("draining")) {
      tell_object(environment(), target->query_name()+" appears "+
	"immune to your swords effects.\n");
      return 0;
    }

    say(target->query_name()+" cries out in pain and is drained of "+
	"some life essence!\n");
    tell_object(environment(), target->query_name()+" cries out in pain "+
	"and is drained some life essence.\n");
    target->drain_level();
    return (30); /* total of x3 damage */
  }

  if(!random(10))
    tell_object(environment(), "You can feel your sword "+
	"becomming hungry for blood.\n");

  return 0;
}




#include <mudlib.h>
#include <spell.h>

inherit "inherit/timer";
#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status ego(string targ, mixed alt_type) {
  int dam, i;
  string file;


  if(!targ || !(targ == "whip" || sscanf(targ, "whip %s", targ))) {
      notify_fail("Ego whip who?\n");
      return 0;
  }

  if(targ == "whip") targ = 0;
  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("ego whip")) {
      notify_fail("You have not yet learned that psionic power.\n");
      return 0;
    }
  }
  if(!alt_type) alt_type = "telepathic";


  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(5) + 1);
  if(dam > 30) dam = 30;


  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);


 this_player()->load_spell(({
    "target",            targ,
    "name",              "Ego Whip",
    "sphere",            alt_type,
    "cost",              5,
    "damage",            dam,
    "immune",            "psionics",
    "spell object",      file,
    "level",             9,
    "cast time",         2,
    "casting msg", "Your mind lashes out with superior power.\n",
    "casting msg room", "The air around "+NAME+" begins to crackle...\n",
    "msg target",	NAME+" assaults your ego with great power.\n",
  }));
  return 1;
}

status cast_spell(object caster,object target,object prev,int dmg) {
  object hold;
  string spell_name;
  int defense;
  int attack;
  object shield;
  mixed loaded_spell;

  hold = present("Hold 2", target);
  if(hold) {
    tell_object(caster,"You extend the time of the stun effect on "+
                (string)target->query_name()+".\n");
    hold->adj_time(dmg * 30);
    destruct(this_object());
    return 0;
  }

  if(!(shield = present("mind shield", target))) {
      tell_object(caster, target->query_name()+"'s open mind and ego centre "+
	"crumbles at your attack!\n");
      tell_object(target, caster->query_name()+" stabs at the ego "+
	"of you open mind!\n");
    adj_time(dmg);
    return 0;
  }

  loaded_spell = (mixed *)caster->query_loaded_spell();
  defense = (int)target->query_telepathy();
  attack = (int)caster->query_telepathy();
  spell_name = (string)shield->query_defense_mode();



  switch(spell_name) {
    case "mind blank" :
      attack += 5;
      break;
    case "thought shield" :
      attack -= 0;
      break;
    case "mental barrier" :
      attack -= 3;
      break;
    case "intellect fortress" :
      attack -= 4;
      break;
    case "tower of iron will" :
      attack -= 3;
      break;
    default :
      attack -= 6;
      break;
  }

  if(random(attack) > random(defense)) {
    shield -> adj_tanjents(1);
    if(shield->query_tangents() > 2) { /* i.e. it's 3! */
      tell_object(caster, "You turn "+target->query_name()+"'s mental "+
	"defenses into rubble.\n");
      tell_object(target, "You feel your mental defenses crumble...!\n");
      shield->end_spell();
      adj_time(dmg * 30);
      return 0;
    }
    tell_object(caster, "You break down some of "+target->query_name()+
	"'s defenses.\n");
    tell_object(target, caster->query_name()+" breaks down some "+
	"of your mental defenses!\n");
    destruct(this_object());
    return 0; /* no damage or hits */
  }

  else {
    tell_object(caster, target->query_name()+"'s mind repells your attack.\n");
    tell_object(target, "You withstand "+caster->query_name()+"'s mind attack.\n");
    destruct(this_object());
    return 0;
  }

  destruct(this_object());
  return 0;
}

void time_out() {
  tell_object(environment(),"Your mind clears...\n");
  ::time_out();
}

void dispel_magic() { time_out(); } /* std spell fn to clean up */

status id(string str) {
  return str == "psionic" ||
         str == "spell" ||
         str == "Hold";
}

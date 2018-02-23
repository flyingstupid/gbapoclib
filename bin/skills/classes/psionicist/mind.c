#include <mudlib.h>
#include <spell.h>

#define NAME "@@query_name:$this_player()$@@"  /* gives greater flexibilty */
#define TARG "@@query_name:$this_object()$@@"

status mind(string targ, mixed alt_type) {
  int dam, i;
  string file;


  if(!targ || !(targ == "thrust" || sscanf(targ, "thrust %s", targ))) {
      notify_fail("Mind thrust who?\n");
      return 0;
  }

  if(targ == "thrust") targ = 0;
  if(!alt_type) { /* i.e. not called from another source */
    if(!this_player()->query_psi_skills("mind thrust")) {
      notify_fail("You have not yet learned that psionic power.\n");
      return 0;
    }
  }
  if(!alt_type) alt_type = "telepathic";


  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);
  dam *= (random(2) + 1);
  if(dam > 20) dam = 20;


  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i);


 this_player()->load_spell(({
    "target",            targ,
    "name",              "Mind Thrust",
    "sphere",            alt_type,
    "cost",              2,
    "damage",            dam,
    "immune",            "psionics",
    "spell object",      file,
    "level",             2,
    "cast time",         2,
    "casting msg", "Your mind stabs out like an icy blade\n",
    "casting msg room", "The air around "+NAME+" begins to crackle...\n",
    "msg target",        NAME+" stabs at your synapses!\n",
  }));
  return 1;
}

status cast_spell(object caster,object target,object prev,int dmg) {
  string spell_name;
  int defense;
  int attack;
  object shield;
  mixed loaded_spell;

  if(!(shield = present("mind shield", target))) {
      tell_object(caster, target->query_name()+"'s open mind crumbles "+
	"at your attack!\n");
      tell_object(target, caster->query_name()+" stabs at the synapses "+
	"of your open mind!\n");
   destruct(this_object());
    return 1;
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
      attack -= 2;
      break;
    case "mental barrier" :
      attack -= 4;
      break;
    case "intellect fortress" :
      attack -= 4;
      break;
    case "tower of iron will" :
      attack -= 5;
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
      destruct(this_object());
      return 1;
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


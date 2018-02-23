/* globe of invulnerability */
#include <spell.h>
inherit "inherit/timer";




#define NAME "@@query_name:$this_player()$@@"

int globe_level;

status globe(string targ, mixed alt_type) {
  string tmp1, tmp2, file;
  int dam, i;
  int spell_level;
  string spell_name;

  if(!alt_type) alt_type = "evocation";
  dam = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()  /* wands */
      : (int)call_other(this_player(),"query_"+alt_type);



  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  if(!targ) {
    notify_fail("Globe of <minor|major> invulnerability?\n");
    return 0;
  }

  if(sscanf(targ, "%sminor%s", tmp1, tmp2)) {
    spell_level = 15;
    spell_name = "Minor Globe of Invulnerability";
  }
  else if(sscanf(targ, "%smajor%s", tmp1, tmp2)) {
    spell_level = 25;
    spell_name = "Major Globe of Invulnerability";
  }
  else {
    notify_fail("Globe of <minor|major> invulnerability?\n");
    return 0;
  }


  targ = 0;

  this_player()->load_spell(({
    "target",            targ,
    "name",              spell_name,
    "sphere",            alt_type,
    "cost",              spell_level,
    "damage",            dam, /* used as time, no damage */
    "immune",            "protection",
    "level",             spell_level,
    "cast time",         6,
    "spell object",      file,
    "passive",
    "casting msg",
	({ "You concentrate on the magical energies around you.\n",
	   "You summon magical energies from around you.\n",
	   "Light flashes before your eyes.\n",
	   "You begin to form a magical barrier around you.\n",
	   "Colours begin to swirl and swim in front of you.\n",
	   "A globe of light and colour forms before you.\n",
        }),

    "casting msg room",
	({ NAME+" summons magic of great power...\n",
	   "Colours swirl around "+NAME+".\n",
	   "Light and colour swim around "+NAME+".\n",
	   "A globe begins to form around "+NAME+".\n",
	   "There is some crackling of multi coloured light.\n",
	   "There is a thunder clap around "+NAME+".\n",
        }),

  }));
  return 1;
}

status cast_spell(object caster, object target, object previous, int dmg) {
  object ob;
  mixed *loaded_spell;

  loaded_spell = caster->query_loaded_spell();
  globe_level = SPELL_LEVEL;


  if((ob = present("globe 2", target))) {
    tell_object(target,"You extend the time of your Globe spell.\n");
    ob->adj_time(dmg * 30);
    destruct(this_object());
    return 1;
  }

  tell_object(target, "You feel a shell of magical colours form around you.\n");
  adj_time(dmg * 30);
  return 1;
}


void extra_long() {
  if(this_player() == environment())
    write("You have many thousands of colours swirling around you...\n");
  else
    write(environment()->query_name()+" has many thousands of colours "+
	"swirling around "+environment()->query_objective()+".\n");
}

void time_out() {
  tell_object(environment(),"The Globe of Invulnerability fades...\n");
  ::time_out();
}


status id(string str) {
  return str == "spell"
      || str == "external"
      || str == "globe"
      || str == "globe of invulnerability";
}

status spell_capture(object caster,
                     object target,
                     object target_ob,
                     object previous,
                     int dmg) {
  mixed *loaded_spell;

  loaded_spell = caster->query_loaded_spell();

  if(PASSIVE) return 0;

  if(SPELL_LEVEL < globe_level) {
    tell_object(caster, 
	"Your spell is absorbed by "+environment()->query_name()+
	"'s Globe of Invulnerability!\n");
    tell_object(environment(),
	"You Globe of Invulnerability stops "+caster->query_name()+
	"'s spell!\n");

    caster->unload_spell();
    return 1;
  }
  return 0;
}

void long(status wiz) {
  write("A magical globe of swirling colours surrounds you.\n");
}

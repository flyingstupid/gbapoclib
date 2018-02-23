#include "path.h"

#define  NAME       "@@query_name:$this_player()$@@"
#define  SPELLNAME  (string)caster->query_spell_name()
#define  SPELLDMG   (int)caster->query_spell_dmg()  

status control(string str, mixed alt_type, string class) {
  string targ, spell_name, file;
  int cost, level, i;

  if(!str) {
    notify_fail("Control flames? control light?\n");
    return 0;
  }

  sscanf(str, "%s %s", spell_name, targ);

  switch(spell_name) {
    case "flames" : 
      if(!alt_type) { 
        if(!this_player()->query_psi_skills("control flames")) {
          notify_fail("You have not yet learned the 'Control Flames'"+
		" psionic power.\n");
          break;
        }
      }
      level = 1;
      cost  = 1;
      spell_name = "Control Flames";
    break;

    case "light" : 
      if(!alt_type) { 
        if(!this_player()->query_psi_skills("control light")) {
          notify_fail("You have not yet learned the 'Control Light'"+
		" psionic power.\n");
          break;
        }
      }
      level = 5;
      cost  = 5;
      spell_name = "Control Light";
    break;

    default :
      notify_fail("Control flames? Control light?\n");
      return 0;
    break;
  }

  level = (objectp(alt_type))
      ? (int)alt_type->query_cast_level()
      : (int)call_other(this_player(),"query_"+alt_type);

  file = file_name(this_object());
  sscanf(file, "%s#%d", file, i);

  if(!alt_type) alt_type = "psychokinetic";
  if(!class)    class    = "psionicist";

  this_player()->load_spell(({
  	"target",            targ,
  	"name",              spell_name,
  	"sphere",            alt_type,
  	"cost",              cost,
  	"damage",            (level * 60), /* for duration */
  	"level",             level,
  	"cast time",         2,
  	"spell object",      file,
  	"class",             class,
  	"casting msg",       "You start to feel gravitational forces around you...\n",
  	"casting msg room",  "You can feel gravity swell around "+NAME+".\n",
  	"passive",
  }));
  return 1;
}


/* call when this object is cloned to target */

status cast_spell(object caster, object target, object previous, int level) {

  switch(SPELLNAME) {
    case "Control Light" :
      write("The light begins to grow in your surrounds . . .\n");
      say("Suddenly the area around "+caster->query_name()+" begins to get lighter . . .\n");
      caster->adj_light(caster->query_current_light() + 1);
    break;


    case "Control Flames" :
      if(target->id("torch")) {
        if(target->query_time_left() != -1) {
          write("Your "+target->query_name()+" flares with a brighter light.\n");
          say(caster->query_name()+"'s "+target->query_name()+" flares with a "+
		"brighter light.\n",caster);
        }
        else {
          target->light(target->query_name());
          write("Your "+target->query_name()+" suddenly bursts into bright flames!\n");
          say(caster->query_name()+"'s "+target->query_name()+" suddenly bursts into "+
		"bright flames!\n",caster);
        }
              
        target -> set_light_intensity(2);
        target -> set_max_fuel(target->query_max_fuel() + (60 * SPELLDMG));
        target -> adj_time(60 * SPELLDMG);
        write("Your "+target->query_name()+" flares with a brighter light.\n");
        say(caster->query_name()+"'s "+target->query_name()+" flares with a "+
		"brighter light.\n");
      }
      else 
        write("You can only make ignitable items burn for longer.\n");
    break;

    default :
      write("Nothing happens.\n");  
    break;
  }

  destruct(this_object());
  return 0;
}




#include "path.h"

status project(string str, mixed alt_type, string class) {
  string targ, spell_name;
  int cl, cost, level;

  if(!str) {
    notify_fail("Project force?\n");
    return 0;
  }

  sscanf(str, "%s %s", spell_name, targ);

  if(!alt_type) { 
    if(!this_player()->query_psi_skills("project force")) {
      notify_fail("You have not yet learned the 'Project"+
		" Force' psionic power.\n");
      return 0;
    }
  }

  cost = 13;
  level = 13;


  if(!alt_type) alt_type = "psychokinetic";
  if(!class)    class    = "psionicist";

  cl = (objectp(alt_type))
     ? (int)alt_type->query_cast_level()
     : (int)this_player()->query(alt_type);

  cl *= random(6);
  if(cl > 50) cl = 50;


  this_player()->load_spell(({
  	"target",            targ,
  	"name",              "Project Force",
  	"sphere",            alt_type,
  	"cost",              cost,
  	"level",             level,
  	"class",             class,
  	"cast time",         1,
  	"damage",            cl,  
  }));

  return 1;
}





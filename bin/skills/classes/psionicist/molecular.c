#include "path.h"

#define DIFFICULTY 	10
#define MOD		3

status molecular(string str, mixed alt_type, string class) {
  string file;
  int i;
  string targ, spell_name;
  int cl, cost, level;

  if(!str) {
    notify_fail("Molecular rearrangement?\n");
    return 0;
  }

  sscanf(str, "%s %s", spell_name, targ);

  if(!targ) {
    notify_fail("Molecular rearrangement what?\n");
    return 0;
  }

  
  if(!alt_type) { 
    if(!this_player()->query_psi_skills("molecular rearrangement")) {
      notify_fail("You have not yet learned the 'Molecular"+
		" Rearrangement' psionic power.\n");
      return 0;
    }
  }


  if(!alt_type) alt_type = "psychokinetic";
  if(!class)    class    = "psionicist";

  level = 13;
  cost  = 13;
  cl = (objectp(alt_type))
     ? (int)alt_type->query_cast_level()
     : (int)this_player()->query(alt_type);


  file = file_name(this_object());
  sscanf(file,"%s#%d",file,i); 


  this_player()->load_spell(({
  "target",            targ,
  "name",              "Molecular Rearrangement",
  "sphere",            alt_type,
  "cost",              cost,
  "level",             level,
  "class",             class,
  "cast time",         1,
  "spell object",      file,
  "damage",            cl,  /* as time */
  "passive",
  }));
  return 1;
}

/*********************************************************************/
/* when cloned to player */


status cast_spell(object caster,object target,object prev,int dmg) {
  object ob;
  int myChance, failureChance;
  int j, k;

  myChance = (int)TP->query_psychokinetic();
  failureChance = (int)target->query_ac() + (int)target->query_wc();

  write("You concentrate on the very atoms of "+ob->query_name()+".\n");
  say(TP->query_name()+" concentrates very hard on "+ob->query_name()+".\n", caster);

  if(ob->query_modified() || ob->query_enchanted()  || living(ob)) {
    write("The "+ob->query_name()+" resists the molecular rearrangement.\n");
  }

  else if((j = random(failureChance)) > (k = random(myChance))) {
    write("The "+ob->query_name()+" resists the molecular rearrangement.\n");
  }


  else {
    j = (k - j)/MOD; /* amount we won comparison by */
    if(j < 1) j = 1;
    ob -> set_modified(1);
    ob -> set_enchanted(1);
    ob -> set_info("The "+ob->query_name()+"'s hardness has been altered psionically "+
		"by Molecular Rearrangement.\n");

    ob -> set_wc((int)ob->query_wc() + j);
    ob -> set_ac((int)ob->query_ac() + j);

    ob -> set_long((string)ob->query_long() + "The "+ob->query_name()+" looks "+
		"as though it is very hard and tough.\n");
    ob -> set_sell_destruct(1);
  }
  destruct(this_object());
  return 0;
}






